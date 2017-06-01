#include "Circle.h"


Circle::Circle()
{
	Figure::getInfo("white", "black", 1);
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

void Circle::printToFile(std::ofstream &out)
{
	out << "\t" << "<circle cx=\"" << cx << "\" cy=\"" << cy << "\" r=\"" << r << "\"";
	out << std::endl;
	Figure::printToFile(out);
}

void Circle::translate(const int addX, const int addY)
{
	cx += addX;
	cy += addY;
}



