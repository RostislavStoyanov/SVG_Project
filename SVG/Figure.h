#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
#include<cmath>
#include"String.h"
const double eps = 1e-20;

class Figure
{
protected:
	String fill; // contains the fill of the current figure 

	String stroke; //contains the stroke of the current figure

	unsigned int strokeWidth; //contains the stroke width of the current figure

	bool pointInsideRectangle(const double, const double, const double, const double, const double, const double); //private function used to
																												//check if a point is inside rectangle

	bool pointInsideCircle(const double,const double ,const double, const double, const double); //private function used to
																							//check if a point is inside circle
public:
	Figure(); //default-constructor 

	virtual ~Figure(); //virtual destructor

	Figure(const char*, const char*, const unsigned int); //create figure from 2 char arrays and an integer
	Figure(const String&, const String&, const unsigned int); // create figure using 2 string objects and an integer

	void getInfo(const char*,const char*,const unsigned int); //change all the figure data using char arrays
	void getInfo(const String&, const String&, const unsigned int); // change all the figure data using string objects

	String getFill() const ; //returns a newly created string object holding the current fill of the figure

	String getStroke() const ; //returns a newly created string object holding the current stroke of the figure

	unsigned int getStrokeWidth() const; //returns the current stroke width of the figure 

	virtual void print() const; //prints the fill,stroke and strokeWidth of the figure to console

	virtual void printToFile(std::ofstream&); //prints the fill,stroke and strokeWidth of the figure to a file 

	virtual void translate(const double ,const double)=0; //pure virtual function used to translate a figure

	virtual bool withinRectangle(const double, const double, const double, const double) = 0; //pure virtual function used to determine if a figure is
																							//inside a rectangle

	virtual bool withinCircle(const double, const double, const double) = 0; //pure virtual function used to determine if a figure is	
																			//inside a rectangle

};

