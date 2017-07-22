#pragma once
#include"Circle.h"
#include"Rectangle.h"
#include"Line.h"

class FigureCollection
{
private:
	Figure ** collection; //polymorphic container for figures

	unsigned int numberOfEntries; //current number of figures in the current collection object
	
	unsigned int maxEntries; //maximum number of figures in the current collection object
public:
	FigureCollection(); //default constructor

	~FigureCollection(); //destructor

	void addEntry(Figure*); //adds a figure to the collection using pointer to it
		
	//void createFromLine(String&); //creates a figure using the data stored in a string object
	
	void deleteEntry(int id =-1); //deletes entry at a specific position(can also delete all of them)
	
	void translate(const int,const int,int id=-1); //translates a specific figure (can also translate all of the figures)
	
	void printToConsole() const; //prints every figure inside the figure collection
	
	void exportToFile(std::ofstream&) const; //prints the collection to a file

	void withinRectangle(const double, const double, const double, const double) const; //checks if there are figures inside a rectangle having its left
													//most point coordiantes and its height and width given and prints any figures inside that rectangle
	void withinCircle(const double, const double, const double) const; //checks if there are figures inside a circle having	its center point
																		//coordinates and radius given and print any figures inside that circle				
};

