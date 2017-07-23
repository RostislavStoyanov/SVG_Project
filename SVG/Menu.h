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
	FigureCollection* figures; //holds the current figure collection for the opened file

	void noFileOpened(); //menu before a file is opened

	void readFile(std::istream&,int&); //reads file until <svg> tag and counts the line before that

	void fileOpened(std::ofstream&,int); //menu after a file is opened

	void readFromSvg(std::istream&); //reads file from <svg> to </svg> and calls the nessecery functions to create figures

	void readRectangle(String&); //creates rectangle from a String object read from a file

	void readCircle(String&); //creates circle from a String object read from a file

	void readLine(String&); //creates line from a String object read from a file
public:
	Menu(); //default constructor

	~Menu(); //destructor

	void main(); //starts the first menu loop
};

