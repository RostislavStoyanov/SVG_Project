#pragma once
#include "Figure.h"
class Circle :
	public Figure
{
private:
	double cx; //the x-axis coordinate of the center of the circle object

	double cy; //the y-axis coordinste of the center of the circle object
	
	double r; //the radius of the circle object
public:
	Circle(); //default constructor

	Circle(const String&, const String&, const unsigned int, double, double, double); //creates circle object using string
	Circle(const char*, const char*, const unsigned int, double, double, double); //creates circle object using char*

	void getInfo(const char*, const char*, const unsigned int, double, double, double); //sets all the fields in the current object using char*
	void getInfo(const String&, const String&, const unsigned int, double, double, double); //sets all the fileds in the current object using string

	double getCx() const; //gets the x-axis coordinate of the center of the circle object 

	double getCy() const; //gets the y-axis coordinate of the center of the circle object

	double getR() const; //gets the radius of the circle object
	
	void setCx(double); //sets the cx property of the circle object

	void setCy(double); //sets the cy property of the circle object

	void setR(double); //sets the radius property of the circle object

	void print() const; //prints the current circle object to console

	void printToFile(std::ofstream&) const; //prints the current circle object to a file

	void translate(const double, const double); //translate the current circle object

	bool withinRectangle(const double, const double, const double, const double); // checks if the current objects is within a rectangle
																				//which has the x,y,height and width properties given
	bool withinCircle(const double, const double, const double); // checks if the current object is within a circle 
																//which has the x,y and radius properties given
};

