#pragma once
#include "Figure.h"
class Rectangle :
	public Figure
{
protected:
	double x; //the x-axis coordinate of the left most point of the rectangle

	double y; //the y-axis coordiante of the left most point of the rectangle

	double width; //the width of the rectangle

	double height; //the height of the rectangle
public:
	Rectangle(); //default constructor
	
	Rectangle(const String&, const String&, const unsigned int, double, double, double, double); //creates Rectangle using String objects
	Rectangle(const char*, const char*, const unsigned int, double, double, double, double); //creates Rectangle using char arrays

	void getInfo(const char*, const char*, const unsigned int,double,double,double,double); //sets all the fields in rectangle objects using char arrays
	void getInfo(const String&, const String&, const unsigned int, double, double, double, double); //sets all the fileds using string objects

	double getX() const; //returns the x-axis coordinate of the left most point of the rectangle

	double getY() const; //returns the y-axis coordinate of the left most point of the rectangle
	
	double getWidth() const; //returns the width of the rectangle
	
	double getHeight() const; //retruns the height of the rectangle

	void setX(const double); //sets the x attribute of the rectangle object

	void setY(const double); //sets the y attribute of the rectangle object

	void setWidth(const double); //sets the width attribute of the rectangle object

	void setHeight(const double); //sets the height attribute of the rectangle object

	void print(); //prints the current Rectangle object to the console

	void printToFile(std::ofstream&); //prints the current Rectangle object to a file

	void translate(const double, const double); //translates the current object 

	bool withinRectangle(const double, const double, const double, const double); // checks if the current objects is within a rectangle
																				//which has the x,y,height and width properties given
	bool withinCircle(const double, const double, const double); // checks if the current object is within a circle 
																//which has the x,y and radius properties given
};

