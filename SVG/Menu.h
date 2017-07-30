#pragma once
#include<Windows.h>
#include"FigureCollection.h"
#include"FigureFactory.h"
#include"Rectangle.h"
class Menu
{
private:
	Figures::FigureCollection* figures; //holds the current figure collection for the opened file

	Figures::FigureFactory fact;//creates diffrent figures

	void readFigureProperties(String&, String&, String&, unsigned int&); //reads fill ,stroke and strokewidth from string line

	void noFileOpened(); //menu before a file is opened

	void readFile(std::istream&,int&); //reads file until <svg> tag and counts the line before that

	void fileOpened(String&,int); //menu after a file is opened

	void readFromSvg(std::istream&); //reads file from <svg> to </svg> and calls the nessecery functions to create figures

	void readRectangle(String&); //creates rectangle from a String object read from a file

	void readCircle(String&); //creates circle from a String object read from a file

	void readLine(String&); //creates line from a String object read from a file
public:
	Menu(); //default constructor

	~Menu(); //destructor

	void main(); //starts the first menu loop
};

