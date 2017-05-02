#include "Rectangle.h"



Rectangle::Rectangle()
{
	Figure();
	x = 0; y = 0;
	height = 0;
	width = 0;
}

void Rectangle::getInfo(const char *fill, const char *stroke, const unsigned int strokeWidth, double x , double y, double width, double height,int type)
{
	Figure::getInfo(fill, stroke, strokeWidth,type);
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->type = type;
}

void Rectangle::print()
{
	std::cout  <<
		x << " " << y << " " << width << " " << height << " "
		<< fill << " " << stroke << " "
		<<strokeWidth << std::endl;
}


