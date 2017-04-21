#include "Line.h"



Line::Line()
{
	Figure();
	x1 = 0; y1 = 0;
	x2 = 0; y2 = 0;
}

void Line::getInfo(const char *fill, const char *stroke, const unsigned int strokeWidth, const double x1, const double y1, const double x2, const double y2)
{
	this->x1 = x1;
	this->x2 = x2;
	this->y1 = y1;
	this->y2 = y2;
}

std::ostream & operator<<(std::ostream& out, const Line &line)
{
	out << line.fill << "," << line.stroke << "," << line.strokeWidth << "," <<
		line.x1 << "," << line.y1 << "," << line.x2 << "," << line.y2 << std::endl;
	return out;
}
