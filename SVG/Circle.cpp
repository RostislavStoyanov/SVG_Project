#include "Circle.h"


Circle::Circle():cx(0),cy(0),
				r(0),Figure()
{
}

Circle::Circle(const String &nFill, const String & nStroke, const unsigned int nStrokeWidth, double nCx, double nCy, double nR):
																											cx(nCx),cy(nCy),r(nR),
																											Figure(nFill,nStroke,nStrokeWidth)
{
}

Circle::Circle(const char *nFill, const char *nStroke, const unsigned int nStrokeWidth, double nCx, double nCy, double nR):
																											cx(nCx), cy(nCy), r(nR),
																											Figure(nFill, nStroke, nStrokeWidth)
{
}


void Circle::getInfo(const char *nFill, const char *nStroke, const unsigned int nStrokeWidth, double nCx, double nCy, double nR)
{
	Figure::getInfo(nFill, nStroke, nStrokeWidth);
	cx = nCx;
	cy = nCy;
	r = nR;
}

void Circle::getInfo(const String &nFill, const String & nStroke, const unsigned int nStrokeWidth, double nCx, double nCy, double nR)
{
	Figure::getInfo(nFill, nStroke, nStrokeWidth);
	cx = nCx;
	cy = nCy;
	r = nR;
}

double Circle::getCx() const
{
	return cx;
}

double Circle::getCy() const
{
	return cy;
}

double Circle::getR() const
{
	return r;
}

void Circle::setCx(double nCx)
{
	cx = nCx;
}

void Circle::setCy(double nCy)
{
	cy = nCy;
}

void Circle::setR(double nR)
{
	r = nR;
}

void Circle::print()
{

	std::cout  <<"circle: x and y of center: "<<
		cx << " " << cy << " radius: " << r<<" fill: "<<
		fill << " stroke: " << stroke << " stroke-width: "
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



