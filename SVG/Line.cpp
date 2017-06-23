#include "Line.h"

Line::Line()
{
	Figure::getInfo("white", "black", 1);
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

void Line::printToFile(std::ofstream &out)
{
	out <<'\t'<<"<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\"";
	out << std::endl;
	Figure::printToFile(out);
}

void Line::translate(const double addX1, const double addY1)
{
	x1 += addX1;
	x2 += addX1;
	y1 += addY1;
	y2 += addY1;
}

bool Line::withinRectangle(const double x, const double y, const double width, const double height)
{
	
	if (pointInsideRectangle(x1, y1, x, y, width, height) && pointInsideRectangle(x2, y2, x, y, width, height)) 
		return true;
	return false;
}


