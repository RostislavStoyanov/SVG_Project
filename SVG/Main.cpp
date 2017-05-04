#include"FigureCollection.h"
#include<fstream>

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

void getContent(const char arr[], char temp[], const int startPostion, int indexInTemp)
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

void nulifyArray(char arr[], const int size)
{
	for (int i = 0; i<size; ++i)
	{
		arr[i] = 0;
	}
	return;
}


void menuOpened(const char* file)
{
	std::cout << "Opening:" << file << std::endl;
	std::ifstream input;
	input.open(file);
	FigureCollection figures;
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
			char  line[1024];
			input.getline(line, 1024);
			unsigned int strLen = strlen(line);
			if (!strcmp(line, "<svg>"))
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
							break;
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
						double currX, currY, currWidth, currHeight;
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
								}
								currX = std::atof(temp);
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
								if (strcmp(buffer, checkForY) == 0)
								{
									getContent(currentFigure, temp, i + 3, indexInTemp);
								}
								currY = std::atoi(temp);
								break;
							}
							case 'w':
							{
								char buffer[20] = { 0 };
								char temp[20] = { 0 };
								indexInTemp = 0;
								indexInBuff = 0;
								int index = i;
								searchFor(currentFigure, buffer, index, indexInBuff);
								buffer[indexInBuff] = currentFigure[index + 1];
								if (strcmp(buffer, checkForWidth) == 0)
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
		if (!strcmp(firstWord, "print")) figures.printToConsole();
		if (!strcmp(firstWord, "create"))figures.createFromLine(userInput);
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
		unsigned int inputLen = strlen(userInput);
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