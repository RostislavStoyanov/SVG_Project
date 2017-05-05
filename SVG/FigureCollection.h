#pragma once
#include"Figure.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Line.h"

class FigureCollection
{
private:
	Figure ** collection;
	unsigned int numberOfEntries;
	unsigned int maxEntries;
public:
	FigureCollection();
	~FigureCollection();

	void addEntry(Figure*);
	void printToConsole() const;	
	void createFromLine(char *);
	void deleteEntry(int id =-1);
};

