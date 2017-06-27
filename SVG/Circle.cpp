#include "Circle.h"


Circle::Circle()
{
	Figure::getInfo("white", "black", 1);
	cx = 0; cy = 0;
	r = 0;
}

Circle::~Circle()
{
	delete[] fill;
	delete[] stroke;
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

void Circle::translate(const double addX, const double addY)
{
	cx += addX;
	cy += addY;
}

bool Circle::withinRectangle(const double rectX, const double rectY, const double rectWidth, const double rectHeight)
{
	if (!pointInsideRectangle(cx, cy, rectX, rectY, rectWidth, rectHeight))
		return false;
	if (!pointInsideRectangle((cx+r), cy, rectX, rectY, rectWidth, rectHeight))
		return false;
	if (!pointInsideRectangle(cx, cy+r, rectX, rectY, rectWidth, rectHeight))
		return false;
	if (!pointInsideRectangle((cx-r), cy, rectX, rectY, rectWidth, rectHeight))
		return false;
	if (!pointInsideRectangle(cx, (cy-r), rectX, rectY, rectWidth, rectHeight))
		return false;
	return true;
}

bool Circle::withinCircle(const double circX, const double circY, const double circR)
{	
	double distX = (cx - circX)*(cx - circX);
	double distY = (cy - circY)*(cy - circY);
	double distanceCenters = sqrt(distX - distY);
	if (distanceCenters <= std::fabs(r - circR))
		return true;
	return false;
}



