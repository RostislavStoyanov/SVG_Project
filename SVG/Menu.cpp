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
	for (size_t i = 0; i < (numberOfWhites); i++)
	{
		std::cout << " ";
	}
	std::cout << headline << std::endl;
}

void Menu::noFileOpened()
{
	std::cout << "For list of avaliable commands type help" << std::endl;
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
				existingFile(input);
				input.close();
				std::ofstream output;
				output.open(fileName);
				fileOpened(output);
			}
			else {
				std::cout << "Could not open :" << fileName << " - creating new file" << std::endl;
				input.close();
				std::ofstream output;
				output.open(fileName);
				newFile(output);
				fileOpened(output);
			}
			delete[]fileName;
		}
		else
			std::cout << "That is not a valid command, see help for list of available commands" << std::endl;
	}
	return;
}

void Menu::existingFile(std::ifstream &is)
{

}

void Menu::newFile(std::ofstream & os)
{
	os << "<?xml version=\"1.0\" standalone=\"no\"?> \n"
		<< "<!DOCTYPE svg PUBLIC \" -//W3C//DTD SVG 1.1//EN\" \n"
		<< "  \"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\"> \n"
		<< "<svg width = \"40cm\" height = \"20cm\" viewBox = \"0 0 1200 700\" \n"
		<<"\t xmlns = \"http://www.w3.org/2000/svg\" version = \"1.1\"> \n";
}

void Menu::fileOpened(std::ofstream & os)
{
	os.close();
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
	noFileOpened();
	return;
}
