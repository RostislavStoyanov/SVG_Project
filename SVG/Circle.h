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
	friend std::ostream& operator<<(std::ostream&, const Circle&);
	void print();
};

