#pragma once
#include "Figure.h"
class Line : public Figure
{
private:
	double x1;
	double y1;
	double x2;
	double y2;
public:
	Line();
	
	void getInfo(const char*,const char*,const unsigned int, const double, const double, const double, const double);
	void print();

	void printToFile(std::ofstream&);
	void translate(const double, const double);
	bool withinRectangle(const double, const double, const double, const double);
};

