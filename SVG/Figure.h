#pragma once
#include<iostream>
#include<cstring>
#include<fstream>

const double eps = 1e-5;

class Figure
{
protected:
	char *fill;
	char *stroke;
	unsigned int strokeWidth;
	void setValue(char*& p, const char* value);
	bool pointInsideRectangle(const double, const double, const double, const double, const double, const double);
public:
	Figure();
	~Figure();

	void getInfo(const char*,const char*,const unsigned int);
	virtual void print();

	virtual void printToFile(std::ofstream&);
	virtual void translate(const double ,const double)=0;
	virtual bool withinRectangle(const double,const double,const double,const double) = 0;
};

