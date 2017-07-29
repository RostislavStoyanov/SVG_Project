#include "Menu.h"

void printHeadLine()
{
	char headline[11] = "SVG PARSER";
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hOut, &csbi);
	size_t width = csbi.srWindow.Right - csbi.srWindow.Left;
	size_t halfTextSize = 5;
	size_t numberOfWhites = (width - halfTextSize) / 2;
	for (size_t i = 0; i < width; i++)
		std::cout << '-';
	std::cout << std::endl;
	for (size_t i = 0; i < (numberOfWhites); i++)
	{
		std::cout << " ";
	}
	std::cout << headline << std::endl;
	for (size_t i = 0; i < width; i++)
		std::cout << '-';
	std::cout << std::endl;
}

void Menu::readFigureProperties(String & line, String & fill, String &stroke, unsigned int strokeWidth)
{
	size_t openingPos;
	size_t closingPos = line.find("/>");
	if (line.find("rect") != String::npos)
		openingPos = line.find("rect");
	else if (line.find("circle") != String::npos)
		openingPos = line.find("circle");
	else if (line.find("line") != String::npos)
		openingPos = line.find("line");
	size_t fillPos = line.find("fill");
	size_t strokePos = line.find("stroke");
	size_t strokeWidthPos = line.find("stroke-width");
	if (fillPos > openingPos&&fillPos < closingPos)
		fill = line.substrDelim(fillPos + 6, '"');
	if (strokePos > openingPos&&strokePos < closingPos)
		stroke = line.substrDelim(strokePos + 8, '"');
	if (strokeWidthPos > openingPos&&strokeWidthPos < closingPos)
	{
		String temp = line.substrDelim(strokeWidthPos + 13, '"');
		char* tempArr = temp.toChar();
		sscanf(tempArr, "%u", &strokeWidth);
		delete[] tempArr;
	}
}

void Menu::noFileOpened()
{
	while (true)
	{
		String input1;
		std::cout << '>';
		std::cin >> input1;
		if (input1 == "exit")
			break;
		else if (input1 == "help")
		{
			std::cout << "List of available commands: \n"
				<< "open <file name> - opens the file specified or creates a new one if the file cannot be opened or does not exist \n"
				<< "exit - closes the program \n"
				<< "help - displays the current message" << std::endl;
		}
		else if (input1 == "open")
		{
			String input2;
			std::cin >> input2;
			delete[] figures;
			figures = new Figures::FigureCollection;
			char* fileName = input2.toChar();
			std::ifstream input;
			input.open(fileName);
			if (input.is_open())
			{
				std::cout << "Successfully opened: " << fileName << std::endl;
				int numberOfLines = 0;
				readFile(input,numberOfLines);
				input.close();
				if (numberOfLines == -1)
				{
					std::cout << "Please try opening or creating a new file " << std::endl;
					noFileOpened();
				}
				std::ofstream output;
				output.open(fileName);
				fileOpened(output,numberOfLines);
			}
			else {
				std::cout << "Could not open :" << fileName << " - creating new file" << std::endl;
				input.close();
				std::ofstream output;
				output.open(fileName);
				fileOpened(output,0);
			}
			delete[]fileName;
		}
		else
			std::cout << "That is not a valid command, see help for list of available commands" << std::endl;
	}
	return;
}

void Menu::readFile(std::istream &is,int& numberOfLines)
{
	bool reachedOpening = false;
	while (!is.eof())
	{
		String line;
		line.getLine(is);
		if (!(line.find("<svg") == String::npos)&&(reachedOpening==false))
			numberOfLines++;
		if (line.find("<svg")!=String::npos)
		{
			reachedOpening = true;
			break;
		}
	}
	if (reachedOpening == false)
	{
		std::cout << "The file is invalid" << std::endl;
		numberOfLines = -1;
		return;
	}
	else readFromSvg(is);
}

void Menu::fileOpened(std::ofstream & os,int numberOfLinesAbove)
{
	//dont forget to close it before return 
	//os.close();
}

void Menu::readFromSvg(std::istream &is)
{
	String currentFigure;
	while (!is.eof())
	{
		String currentLine;
		currentLine.getLine(is);
		if (currentLine == "</svg>")
			return;
		currentFigure += currentLine;
		if (currentFigure.find("<rect") != String::npos)
		{
			if (currentFigure.find("/>") == String::npos)
				continue;
			else
			{
				readRectangle(currentFigure);
				currentFigure == "";
				continue;
			}
		}
		if (currentFigure.find("<circle") != String::npos)
		{
			if (currentFigure.find("/>") == String::npos)
				continue;
			else
			{
				readCircle(currentFigure);
				currentFigure == "";
				continue;
			}
		}
			if (currentFigure.find("<line") != String::npos)
			{
				if (currentFigure.find("/>") == String::npos)
					continue;
				else
				{
					readLine(currentFigure);
					currentFigure = "";
					continue;
				}
			}
		}
}

void Menu::readRectangle(String & currentRect)
{
	double currentX=0, currentY=0, currentHeight=0, currentWidth=0;
	String stroke="black", fill="white";
	unsigned int currentStrokeWidth=0;
	size_t openingPos = currentRect.find("<rect");
	size_t closingPos = currentRect.find("/>");
	size_t widthPos = currentRect.find("width");
	size_t heightPos = currentRect.find("height");
	size_t xPos = currentRect.find("x=");
	size_t yPos = currentRect.find("y=");
	if (xPos > openingPos&&xPos < closingPos)
	{
		String temp = currentRect.substrDelim(xPos + 3, '"');
		currentX = temp.stod();
	}
	if (yPos > openingPos&&yPos < closingPos)
	{
		String temp = currentRect.substrDelim(yPos + 3, '"');
		currentY = temp.stod();
	}
	if (widthPos > openingPos&&widthPos < closingPos)
	{
		String temp = currentRect.substrDelim(widthPos + 7,'"');
		currentWidth = temp.stod();
	}
	if (heightPos > openingPos&&heightPos < closingPos)
	{
		String temp = currentRect.substrDelim(heightPos + 8,'"');
		currentHeight = temp.stod();
	}
	readFigureProperties(currentRect,fill,stroke,currentStrokeWidth);
	Figures::Rectangle* newRect = new Figures::Rectangle;
	newRect->getInfo(fill, stroke, currentStrokeWidth, currentX, currentY, currentWidth, currentHeight);
	figures->addEntry(newRect);
}

void Menu::readCircle(String & currentCirc)
{
	double currCx = 0, currCy = 0, currR = 0;
	String currFill="white", currStroke="white";
	unsigned int currStrokeWidth = 0;
	size_t openingPos = currentCirc.find("<circle");
	size_t closingPos = currentCirc.find("/>");
	size_t cXPos = currentCirc.find("cx");
	size_t cYPos = currentCirc.find("cy");
	size_t rPos = currentCirc.find("r");
	Figures::Circle* newCirc = new Figures::Circle;
	if (cXPos > openingPos&&cXPos < closingPos)
	{
		String temp = currentCirc.substrDelim(cXPos + 4, '"');
		currCx = temp.stod();
	}
	if (cYPos > openingPos&&cYPos < closingPos)
	{
		String temp = currentCirc.substrDelim(cYPos + 4, '"');
		currCy = temp.stod();
	}
	if (rPos > openingPos&&rPos < closingPos)
	{
		String temp = currentCirc.substrDelim(rPos + 3, '"');
		currR = temp.stod();
	}
	readFigureProperties(currentCirc, currFill, currStroke, currStrokeWidth);
	newCirc->getInfo(currFill, currStroke, currStrokeWidth, currCx, currCy, currR);
	figures->addEntry(newCirc);
}

void Menu::readLine(String & currentLine)
{
	double currX1 = 0, currX2 = 0, currY1 = 0,currY2;
	String currFill = "white", currStroke = "white";
	unsigned int currStrokeWidth = 0;
	size_t openingPos = currentLine.find("line");
	size_t closingPos = currentLine.find("/>");
	size_t x1Pos = currentLine.find("x1");
	size_t x2Pos = currentLine.find("x2");
	size_t y1Pos = currentLine.find("y1");
	size_t y2Pos = currentLine.find("y2");
	Figures::Line* newLine = new Figures::Line;
	if (x1Pos > openingPos&&x1Pos < closingPos)
	{
		String temp = currentLine.substr(x1Pos + 4, '"');
		currX1 = temp.stod();
	}
	if (x2Pos > openingPos&&x2Pos < closingPos)
	{
		String temp = currentLine.substr(x1Pos + 4, '"');
		currX2 = temp.stod();
	}
	if (y1Pos > openingPos&&y1Pos < closingPos)
	{
		String temp = currentLine.substr(x1Pos + 4, '"');
		currY1 = temp.stod();
	}
	if (y2Pos > openingPos&&y2Pos < closingPos)
	{
		String temp = currentLine.substr(x1Pos + 4, '"');
		currY2 = temp.stod();
	}
	readFigureProperties(currentLine, currFill, currStroke, currStrokeWidth);
	newLine->getInfo(currFill, currStroke, currStrokeWidth, currX1, currY1, currX2, currY2);
	figures->addEntry(newLine);
}

Menu::Menu() :figures(nullptr)
{

}

Menu::~Menu()
{
	delete figures;
}

void Menu::main()
{
	printHeadLine();
	std::cout << "Type \"help\" for list of available commands " << std::endl;
	noFileOpened();
	return;
}
