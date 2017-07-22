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
		String input1, input2;
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
			std::cin >> input2;
			std::cout << input2 << std::endl;
		}
		else
			std::cout << "That is not a valid command, see help for list of available commands" << std::endl;
	}
	return;
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
