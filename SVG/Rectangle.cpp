#include "Rectangle.h"



Rectangle::Rectangle()
{
	Figure::getInfo("white", "black", 1);
	x = 0; y = 0;
	height = 0;
	width = 0;
}

void Rectangle::getInfo(const char *fill, const char *stroke, const unsigned int strokeWidth, double x , double y, double width, double height)
{
	Figure::getInfo(fill, stroke, strokeWidth);
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

void Rectangle::print()
{
	std::cout  <<"rectangle "<<
		x << " " << y << " " << width << " " << height << " "
		<< fill << " " << stroke << " "
		<<strokeWidth << std::endl;
}

void Rectangle::printToFile( std::ofstream &out)
{
	out << "\t<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\"";
	out << std::endl;
	Figure::printToFile(out);
	return;
}

void Rectangle::translate(const double addX, const double addY)
{
	x += addX;
	y += addY;
}

bool Rectangle::withinRectangle(const double rectX, const double rectY, const double rectWidth, const double rectHeight)
{
	if ((pointInsideRectangle(x, y, rectX, rectY, rectWidth, rectHeight)) && pointInsideRectangle((x + width), (y + height), rectX, rectY, rectWidth, rectHeight))
		return true;
	return false;	
}


