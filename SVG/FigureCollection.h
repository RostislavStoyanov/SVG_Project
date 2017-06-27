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
		
	void createFromLine(char *);
	void deleteEntry(int id =-1);
	
	void translate(const int,const int,int id=-1);
	
	void printToConsole() const;
	void exportToFile(std::ofstream&) const;

	void withinRectangle(const double, const double, const double, const double) const;
	void withinCircle(const double, const double, const double) const;
};

