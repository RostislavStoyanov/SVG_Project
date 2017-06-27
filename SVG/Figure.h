#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
#include<cmath>
const double eps = 1e-20;

class Figure
{
protected:
	char *fill;
	char *stroke;
	unsigned int strokeWidth;
	void setValue(char*& p, const char* value);
	bool pointInsideRectangle(const double, const double, const double, const double, const double, const double);
	bool pointInsideCircle(const double,const double ,const double, const double, const double);
public:
	Figure();
	virtual ~Figure();

	void getInfo(const char*,const char*,const unsigned int);
	virtual void print();

	virtual void printToFile(std::ofstream&);
	virtual void translate(const double ,const double)=0;
	virtual bool withinRectangle(const double,const double,const double,const double) = 0;
	virtual bool withinCircle(const double, const double, const double) = 0;
};

