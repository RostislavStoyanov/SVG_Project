#include"FigureCollection.h"

const char checkForX[4] = "x=\"";
const char checkForY[4] = "y=\"";
const char checkForWidth[8] = "width=\"";
const char checkForHeight[9] = "height=\"";
const char checkForFill[7] = "fill=\"";
const char checkForStroke[9] = "stroke=\"";
const char checkForStorkeWidth[15] = "stroke-width=\"";
const char checkForR[4]= "r=\"";
const char checkForCx[5]= "cx=\"";
const char checkForCy[5]= "cy=\"";
const char checkForX1[5] = "x1=\"";
const char checkForX2[5] = "x2=\"";
const char checkForY1[5] = "y1=\"";
const char checkForY2[5] = "y2=\"";
const char firstRows[5][100] =
{
	"<?xml version=\"1.0\" standalone=\"no\"?>",
	"<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\" ",
	" \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">",
	"<svg width = \"40cm\" height = \"20cm\" viewBox = \"0 0 1200 700\"",
	"\t xmlns = \"http://www.w3.org/2000/svg\" version = \"1.1>",
};


void getContent(const char arr[], char temp[], const int startPostion, int &indexInTemp)
{
	for (int j = startPostion; arr[j] != '"'; ++j)
	{
		temp[indexInTemp] = arr[j];
		indexInTemp++;
		if (arr[j + 1] == 0) break;
	}
	return;
}

void searchFor(const char arr[], char buffer[], int& index, int& indexInBuff)
{
	for (int j = index; arr[j] != '"'; ++j)
	{
		buffer[indexInBuff] = arr[j];
		indexInBuff++;
		index = j;
	}
}

void nulifyArray(char arr[], const size_t size)
{
	for (int i = 0; i<size; ++i)
	{
		arr[i] = 0;
	}
	return;
}

bool checkForBlank(char* temp)
{
	for(size_t i=0;i<strlen(temp);i++)
	{
		if (temp[i] != 0) return false;
	}
	return true;
}

void menuOpened(const char* file)
{
	bool isNew = 0;
	std::cout << "Opening:" << file << std::endl;
	std::ifstream input;
	input.open(file);
	FigureCollection figures;
	int numberOfLines = 0;
	if (input.is_open())
	{
		input.clear();
		input.seekg(0, std::ios::beg);
		char currentFigure[2048] = { 0 };
		int currentFigureCounter = 0, figureNumber = 0;
		bool isFigure = 0;
		bool completedFigure = 0;
		int currentFigureType = 0;
		while (!input.eof())
		{
			if (!isFigure) numberOfLines++;
			char  line[1024];
			input.getline(line, 1024);
			size_t strLen = strlen(line);
			if (line[0]=='<'&&line[1]=='s'&&line[2]=='v'&&line[3]=='g')
			{
				isFigure = 1;
				continue;
			}
			if (!strcmp(line, "</svg>"))
			{
				isFigure = 0;
				if (input.eof()) break;
				continue;
			}
			if (isFigure)
			{
				for (unsigned int i = 0; i < strLen; ++i)
				{
					currentFigure[currentFigureCounter] = line[i];
					currentFigureCounter++;
					if (line[i] == '/'&&line[i + 1] == '>')
					{
						completedFigure = 1;
						break;
					}
					else
					{
						completedFigure = 0;
					}
				}
			}
				if (completedFigure)
				{
					if (checkForBlank(currentFigure)) 
						continue;
					char currFill[20] = { 0 };
					char currStroke[20] = { 0 };
					char figureType[30] = { 0 };
					int figureTypePosition = 0;
					int currStrokeWidth=1, indexInTemp, indexInBuff;
					for (int i = 0; line[i] != ' '; ++i)
					{
						figureType[figureTypePosition] = line[i];
						figureTypePosition++;
					}

					//Checking for figure type
					//1 - rectangle,2-circle,3-line


					for (unsigned int i = 0; i < strlen(currentFigure); ++i) {
						if (currentFigure[i] == '<')
						{
							if (currentFigure[i + 1] == 'r') currentFigureType = 1;
							if (currentFigure[i + 1] == 'c') currentFigureType = 2;
							if (currentFigure[i + 1] == 'l') currentFigureType = 3;
						}
					}
					//stroke-width ,fill and stroke
					nulifyArray(currStroke, 20);
					nulifyArray(currFill, 20);
					for (unsigned int i = 0; i < strlen(currentFigure); ++i)
					{
						switch (currentFigure[i])
						{
						case 'f':
						{
							char buffer[20] = { 0 };
							char temp[20] = { 0 };
							indexInTemp = 0;
							indexInBuff = 0;
							int index = i;
							searchFor(currentFigure, buffer, index, indexInBuff);
							buffer[indexInBuff] = currentFigure[index + 1];
							if (strcmp(buffer, checkForFill) == 0 )
							{
								getContent(currentFigure, temp, i + 6, indexInTemp);
							}
							else break;
							strcpy_s(currFill, strlen(temp)+1, temp);
							break;
						}
						case 's':
						{
							char buffer[20] = { 0 };
							char temp[20] = { 0 };
							indexInTemp = 0;
							indexInBuff = 0;
							int index = i;
							searchFor(currentFigure, buffer, index, indexInBuff);
							buffer[indexInBuff] = currentFigure[index + 1];
							if (currentFigure[i + 6] == '-')
							{
								if (strcmp(buffer, checkForStorkeWidth) == 0)
								{
									getContent(currentFigure, temp, i + 14, indexInTemp);
								}
								else break;
								currStrokeWidth = std::atoi(temp);
								break;

							}
							else if (strcmp(buffer, checkForStroke) == 0 )
							{
								getContent(currentFigure, temp, i + 8, indexInTemp);
							}
							else break;
							strcpy_s(currStroke, strlen(temp)+1, temp);
							break;
						}
						}

					}
					switch (currentFigureType)
					{
					case 1:
					{
						double currX, currY, currWidth=-1, currHeight=-1;
						for (unsigned int i = 0; i < strlen(currentFigure); ++i)
						{
							switch (currentFigure[i])
							{
							case 'x': {
								char buffer[20] = { 0 };
								char temp[20] = { 0 };
								indexInTemp = 0;
								indexInBuff = 0;
								int index = i;
								searchFor(currentFigure, buffer, index, indexInBuff);
								buffer[indexInBuff] = currentFigure[index + 1];
								if (strcmp(buffer, checkForX) == 0)
								{
									getContent(currentFigure, temp, i + 3, indexInTemp);
									currX = std::atof(temp);
								}
								break;
							}
							case 'y': {
								char buffer[20] = { 0 };
								char temp[20] = { 0 };
								indexInTemp = 0;
								indexInBuff = 0;
								int index = i;
								searchFor(currentFigure, buffer, index, indexInBuff);
								buffer[indexInBuff] = currentFigure[index + 1];
								if (!strcmp(buffer, checkForY))
								{
									getContent(currentFigure, temp, i + 3, indexInTemp);
									currY = std::atof(temp);
								}
								break;
							}
							case 'w':
							{
								if (currWidth != -1) break;
								char buffer[20] = { 0 };
								char temp[20] = { 0 };
								indexInTemp = 0;
								indexInBuff = 0;
								int index = i;
								searchFor(currentFigure, buffer, index, indexInBuff);
								buffer[indexInBuff] = currentFigure[index + 1];
								if (strcmp(buffer, checkForWidth) == 0 && currentFigure[index - 1]!='-')
								{
									getContent(currentFigure, temp, i + 7, indexInTemp);
								}
								else break;
								currWidth = std::atof(temp);
								break;
							}
							case 'h':
							{
								char buffer[20] = { 0 };
								char temp[20] = { 0 };
								indexInTemp = 0;
								indexInBuff = 0;
								int index = i;
								searchFor(currentFigure, buffer, index, indexInBuff);
								buffer[indexInBuff] = currentFigure[index + 1];
								if (strcmp(buffer, checkForHeight) == 0 )
								{
									getContent(currentFigure, temp, i + 8, indexInTemp);
								}
								else break;
								currHeight = std::atof(temp);
								break;
							}
							}
						}
						Rectangle* rect = new Rectangle;
						rect->getInfo(currFill, currStroke, currStrokeWidth, currX, currY, currWidth, currHeight);
						figures.addEntry(rect);
						break;
					}
					case 2:
					{
						double currCx, currCy, currR;
						for (unsigned int i = 0; i < strlen(currentFigure); ++i)
						{
							switch (currentFigure[i])
							{
							case 'c':
							{
								char buffer[20] = { 0 };
								char temp[20] = { 0 };
								indexInTemp = 0;
								indexInBuff = 0;
								int index = i;
								searchFor(currentFigure, buffer, index, indexInBuff);
								buffer[indexInBuff] = currentFigure[index + 1];
								if (strcmp(buffer, checkForCx) == 0 )
								{
									getContent(currentFigure, temp, i + 4, indexInTemp);
									currCx = std::atof(temp);
								}
								else if (strcmp(buffer, checkForCy) == 0)
								{
									getContent(currentFigure, temp, i + 4, indexInTemp);
									currCy = std::atof(temp);
								}
								else break;
								break;
							}
							case 'r':
							{
								char buffer[20] = { 0 };
								char temp[20] = { 0 };
								indexInTemp = 0;
								indexInBuff = 0;
								int index = i;
								searchFor(currentFigure, buffer, index, indexInBuff);
								buffer[indexInBuff] = currentFigure[index + 1];
								if (strcmp(buffer, checkForR) == 0 )
									getContent(currentFigure, temp, i + 3, indexInTemp);
								else break;
								currR = std::atof(temp);
								break;
							}
							}
						}
						Circle * circ = new Circle;
						circ->getInfo(currFill, currStroke, currStrokeWidth, currCx, currCy, currR);
						figures.addEntry(circ);
						break;
					}
					case 3:
					{
						double currX1, currX2, currY1, currY2;
						for (unsigned int i = 0; i < strlen(currentFigure); ++i)
						{
							switch (currentFigure[i])
							{
							case 'x':
							{	char buffer[20] = { 0 };
							char temp[20] = { 0 };
							indexInTemp = 0;
							indexInBuff = 0;
							int index = i;
							searchFor(currentFigure, buffer, index, indexInBuff);
							buffer[indexInBuff] = currentFigure[index + 1];
							if (strcmp(buffer, checkForX1) == 0 )
							{
								getContent(currentFigure, temp, i + 4, indexInTemp);
								currX1 = std::atof(temp);
							}
							else if (strcmp(buffer, checkForX2) == 0 )
							{
								getContent(currentFigure, temp, i + 4, indexInTemp);
								currX2 = std::atof(temp);
							}
							else break;
							break;
							}
							case 'y':
							{
								char buffer[20] = { 0 };
								char temp[20] = { 0 };
								indexInTemp = 0;
								indexInBuff = 0;
								int index = i;
								searchFor(currentFigure, buffer, index, indexInBuff);
								buffer[indexInBuff] = currentFigure[index + 1];
								if (strcmp(buffer, checkForY1) == 0)
								{
									getContent(currentFigure, temp, i + 4, indexInTemp);
									currY1 = std::atof(temp);
								}
								else if (strcmp(buffer, checkForY2) == 0)
								{
									getContent(currentFigure, temp, i + 4, indexInTemp);
									currY2 = std::atof(temp);
								}
								else break;
								break;
							}
							}
						}
						Line* line = new Line;
						line->getInfo(currFill, currStroke, currStrokeWidth, currX1, currY1, currX2, currY2);
						figures.addEntry(line);
						break;
					}
					}
					nulifyArray(currentFigure, 2048);
					currentFigureCounter = 0;
				}
				
			}
		}
	else {
		std::cout << "Could not open the file!\n Creating new file.." << std::endl;
		std::ofstream out(file);
		isNew = 1;
	}
	char userInput[256] = { 0 };
	char firstWord[256] = { 0 };
	int firstWordIndex = 0;
	while (true)
	{
		std::cin.getline(userInput, 256);
		for (unsigned int i = 0; userInput[i] != ' '&&i < strlen(userInput); ++i)
		{
			firstWord[firstWordIndex] = userInput[i];
			firstWordIndex++;
		}
		if (!strcmp(firstWord, "close")) break;
		else if (!strcmp(firstWord, "print")) figures.printToConsole();
		else if (!strcmp(firstWord, "create"))figures.createFromLine(userInput);
		else if (!strcmp(firstWord, "erase"))
		{
			if (userInput[firstWordIndex] == 0) figures.deleteEntry();
			else
			{
				int id = (int)((userInput[firstWordIndex + 1]) - '0');
				figures.deleteEntry(id);
			}
		}
		else if (firstWord[0] == 's'&&firstWord[1] == 'a'&&firstWord[2] == 'v'&&firstWord[3] == 'e')
		{
			input.clear();
			input.seekg(0, std::ios::beg);
			char ** firstLines = new char*[numberOfLines];
			for (int i = 0; i < numberOfLines; i++)
			{
				firstLines[i] = new char[1024];
				char currFileLine[1024] = { 0 };
				input.getline(currFileLine, 1024);
				strcpy_s(firstLines[i], 1024, currFileLine);
			}
			char filePath[256] = { 0 };
			unsigned int filePathPosition = 0;
			std::ofstream out;
			if (isNew) {
				out.open(file, std::ios::out|std::ios::app);
				for (int i = 0; i < 5; i++)
					out << firstRows[i] << "\n";
				out << '\t' << "<desc>Created new file </desc> \n \n";
			}
			else
			{
				for (int i = firstWordIndex + 1; userInput[i] != ' '&&i<strlen(userInput); ++i)
				{
					filePath[filePathPosition] = userInput[i];
					filePathPosition++;
				}
				out.open(filePath, std::ios::out | std::ios::trunc);
			}
			if (!strcmp(firstWord, "saveas"))
			{
				for (int i = 0; i < numberOfLines; i++)
				{
					out << firstLines[i] << std::endl;
				}
				out << '\t' << "<desc>Saved to: "<< filePath<< "</desc> \n \n";
				figures.exportToFile(out);
				out.close();
			}
			for (int i = 0; i < numberOfLines; i++)
				delete[] firstLines[i];
			delete[] firstLines;
		}
		nulifyArray(userInput, 256);
		nulifyArray(firstWord, 256);
		firstWordIndex = 0;
	}
	return;
}

void menu()
{
		char userInput[256];
		char* fileName;
		unsigned int nameCounter = 0;
		std::cin.getline(userInput, 256);
		if (!strcmp(userInput, "exit"))
			return;
		size_t inputLen = strlen(userInput);
		if (userInput[0] == 'o' && userInput[1] == 'p' && userInput[2] == 'e'&&userInput[3] == 'n'&&userInput[4]!=0)
		{
			fileName = new char[inputLen - 4];
			for (unsigned int i = 5; i <= inputLen; ++i)
			{
				fileName[nameCounter] = userInput[i];
				nameCounter++;
			}
			menuOpened(fileName);
			nulifyArray(fileName, strlen(fileName));
		}
		else std::cout << "Please open a file first!" << std::endl;
		menu();
}

int main()
{
	menu();
	return 0;
}