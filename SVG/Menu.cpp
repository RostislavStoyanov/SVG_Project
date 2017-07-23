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
			figures = new FigureCollection;
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
		if (currentFigure.find("<cicle") != String::npos)
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
	double currentX, currentY, currentHeight, currentWidth;
	unsigned int currentStrokeWidth;
	size_t openingPos = currentRect.find("<rect");
	size_t closingPos = currentRect.find("/>");
	size_t widthPos = currentRect.find("width");
	size_t heightPos = currentRect.find("height");
	size_t xPos = currentRect.find("x=");
	size_t yPos = currentRect.find("y=");

}

void Menu::readCircle(String & currentCirc)
{

}

void Menu::readLine(String & currentLine)
{

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
