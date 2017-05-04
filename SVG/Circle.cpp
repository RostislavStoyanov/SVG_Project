#include "Circle.h"


Circle::Circle()
{
	Figure();
	cx = 0; cy = 0;
	r = 0;
}

void Circle::getInfo(const char *fill, const char *stroke, const unsigned int strokeWidth, double cx, double cy, double r)
{
	Figure::getInfo(fill, stroke, strokeWidth);
	this->cx = cx;
	this->cy = cy;
	this->r = r;
}

void Circle::print()
{

	std::cout  <<"circle "<<
		cx << " " << cy << " " << r<<" "<<
		fill << " " << stroke << " "
		<< strokeWidth<< std::endl;
}



