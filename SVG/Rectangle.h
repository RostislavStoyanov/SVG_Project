#pragma once
#include "Figure.h"
class Rectangle :
	public Figure
{
protected:
	double x;
	double y;
	double width;
	double height;
public:
	Rectangle();
	~Rectangle();

	void getInfo(const char*, const char*, const unsigned int,double,double,double,double);

	void print();
	void printToFile(std::ofstream&);

	void translate(const double, const double);

	bool withinRectangle(const double, const double, const double, const double);
	bool withinCircle(const double, const double, const double);
};

