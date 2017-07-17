#include "Figure.h"

bool Figure::pointInsideRectangle(const double x, const double y, const double rectX, const double rectY, const double rectWidth, const double rectHeight)
{

	if (((x >= (rectX + eps) && x <= (rectX + rectWidth - eps))) && (y >= (rectY + eps) && y <= (rectY + rectHeight - eps)))
		return true;
	return false;
}

bool Figure::pointInsideCircle(const double x,const double y,const double cx, const double cy, const double r)
{
	if (((x - cx) *(x-cx)) + ((y - cy)*(y-cy)) < r - eps) 
		return true;
	return false;
}

Figure::Figure()
{
	try {
		fill = "white";
	}
	catch (std::bad_alloc&)
	{
		std::cout << "Not enough memory" << std::endl;
		throw;
	}
	stroke = "black";
	strokeWidth = 1;
}

Figure::~Figure()
{

}

Figure::Figure(const char * newFill, const char *newStroke, const unsigned int newStrokeWidth) : fill("white"),
																								stroke("black"),
																								strokeWidth(1)
{
	try {
		fill = newFill;
	}
	catch (std::bad_alloc&)
	{
		std::cout << "Not enough memory" << std::endl;
		throw;
	}
	stroke = newStroke;
	strokeWidth = newStrokeWidth;
		
}

Figure::Figure(const String &nFill, const String &nStroke, const unsigned int nStrokeWidth) :fill("white"),
																							stroke("black"),
																							strokeWidth(1)
{
	try {
		fill = nFill;
	}
	catch (std::bad_alloc&)
	{
		std::cout << "Not enough memory" << std::endl;
		throw;
	}
	stroke = nStroke;
	strokeWidth = nStrokeWidth;
}

void Figure::getInfo(const char *nFill, const char *nStroke, const unsigned int nStrokeWidth)
{
	fill = nFill;
	stroke = nStroke;
	strokeWidth = nStrokeWidth;
}

void Figure::getInfo(const String & nFill, const String &nStroke, const unsigned int nStrokeWidth)
{
	fill = nFill;
	stroke = nStroke;
	strokeWidth = nStrokeWidth;
}

String Figure::getFill() const
{
	String toRet(fill);
	return toRet;
}

String Figure::getStroke() const
{
	String toRet(stroke);
	return toRet;
}

unsigned int Figure::getStrokeWidth() const
{
	return strokeWidth;
}

void Figure::print() const
{
	std::cout << "Fill: " << fill << " Stroke: " << stroke << " Stroke-width: " << strokeWidth << std::endl;
}

void Figure::printToFile(std::ofstream &out)
{
	out << '\t' << '\t' << "fill=\"" << fill << "\" stroke=\"" << stroke << "\" stroke-width=\"" << strokeWidth << "\" />\n";
	out << std::endl;
	return;
}


