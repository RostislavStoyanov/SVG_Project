#pragma once
#include<iostream>
#include<cstring>
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

	virtual void getInfo(const char*,const char*,const unsigned int);
	void print();
};

