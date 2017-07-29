#pragma once
#include "Figure.h"
namespace Figures
{
	class Line : public Figure
	{
	private:
		double x1; //holds the x-axis coordinate of the left point of the line 

		double y1; //holds the y-axis coordinate of the left point of the line

		double x2; //holds the x-axis coordinate of the right point of the line

		double y2; //holds the y-axis coordinate of the right point of the line
	public:
		Line(); //default constuctor

		Line(const String&, const String&, const unsigned int, double, double, double, double); //creates line object using string 
		Line(const char*, const char*, const unsigned int, double, double, double, double); //creates line object using char*

		void getInfo(const char*, const char*, const unsigned int, double, double, double, double); //sets all the fields of the current object using char*
		void getInfo(const String&, const String&, const unsigned int, double, double, double, double); //sets all the fileds of the current object using string

		double getX1() const; //gets the x-axis coordinate of the left point of the line 

		double getY1() const; //gets the y-axis coordinate of the left point of the line 

		double getX2() const; //gets the x-axis coordinate of the right point of the line

		double getY2() const; //gets the y-axis coordinate of the right point of the line

		void setX1(double); //sets the x1 property of the current object

		void setY1(double); //sets the y1 property of the current object

		void setX2(double); //sets the x2 property of the current object

		void setY2(double); //sets the y2 property of the current object

		void print() const; //prints the current line object to console

		void printToFile(std::ofstream&) const; //prints the current line object to file

		void translate(const double, const double); //translates the current object

		bool withinRectangle(const double, const double, const double, const double); // checks if the current objects is within a rectangle
																					//which has the x,y,height and width properties given
		bool withinCircle(const double, const double, const double); // checks if the current object is within a circle 
																	//which has the x,y and radius properties given
	};
}
