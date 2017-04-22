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
	if (fill&&stroke)
	{
		std::cout << fill << "," << stroke << ",";
	}
	std::cout << strokeWidth << "," <<
		cx << "," << cy << "," << r << std::endl;
}

std::ostream& operator<<(std::ostream& out, const Circle & circle)
{
	if (circle.fill&&circle.stroke)
	{
		out << circle.fill << "," << circle.stroke << ",";
	}
	out << circle.strokeWidth << "," <<
		circle.cx << "," << circle.cy << "," <<circle.r<<std::endl;
	return out;
}


