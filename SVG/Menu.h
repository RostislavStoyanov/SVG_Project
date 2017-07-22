#pragma once
#define _WIN32_WINNT 0x0500
#define SCREENWIDTH getmaxx()
#include"FigureCollection.h"
#include<Windows.h>
#include<WinBase.h>
#include<wincon.h>
class Menu
{
private:
	FigureCollection* figures;

	void noFileOpened();

	void existingFile(std::ifstream&);

	void newFile(std::ofstream&);

	void fileOpened(std::ofstream&);
public:
	Menu(); //default constructor

	~Menu(); //destructor

	void main(); //starts the first menu loop
};

