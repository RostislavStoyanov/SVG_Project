#pragma once
#include "Figure.h"
class Circle :
	public Figure
{
private:
	double cx;
	double cy;
	double r;
public:
	Circle();
	
	void getInfo(const char*, const char*, const unsigned int, double, double, double);
	void print();
	void printToFile(std::ofstream&);
	void translate(const double, const double);

	bool withinRectangle(const double, const double, const double, const double);
};

