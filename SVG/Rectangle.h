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

	void getInfo(const char*, const char*, const unsigned int,double,double,double,double);
};

