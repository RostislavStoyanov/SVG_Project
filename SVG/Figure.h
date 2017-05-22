#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
class Figure
{
protected:
	char *fill;
	char *stroke;
	unsigned int strokeWidth;
	void setValue(char*& p, const char* value);
public:
	Figure();
	~Figure();

	void getInfo(const char*,const char*,const unsigned int);
	virtual void print();

	virtual void printToFile(std::ofstream&);
};

