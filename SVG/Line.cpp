#include "Line.h"

Line::Line()
{
	Figure();
	x1 = 0; y1 = 0;
	x2 = 0; y2 = 0;
}

void Line::getInfo(const char *fill, const char *stroke, const unsigned int strokeWidth, const double x1, const double y1, const double x2, const double y2)
{
	Figure::getInfo(fill, stroke, strokeWidth);
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

void Line::print()
{
	std::cout <<"line "<<
		x1 << " " << y1 << " " << x2 << " " << y2 <<" " 
		<< fill << " " << stroke << " " << strokeWidth
			<< std::endl;
}


