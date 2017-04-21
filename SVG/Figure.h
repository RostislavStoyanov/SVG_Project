#pragma once
#include<stddef.h>
#include<iostream>
class Figure
{
protected:
	char* fill;
	char* stroke;
	unsigned int strokeWidth;
public:
	Figure();
	~Figure();
};

