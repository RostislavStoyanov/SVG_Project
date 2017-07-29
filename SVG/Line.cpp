#include "Line.h"
namespace Figures
{
	Line::Line() :
		x1(0), y1(0),
		x2(0), y2(0),
		Figure()
	{
	}

	Line::Line(const String &nFill, const String &nStroke, const unsigned int nStrokeWidth, double nX1, double nY1, double nX2, double nY2) :
		x1(nX1), y1(nY1), x2(nX2), y2(nY2),
		Figure(nFill, nStroke, nStrokeWidth)
	{
	}

	Line::Line(const char *nFill, const char *nStroke, const unsigned int nStrokeWidth, double nX1, double nY1, double nX2, double nY2) :
		x1(nX1), y1(nY1), x2(nX2), y2(nY2),
		Figure(nFill, nStroke, nStrokeWidth)
	{
	}


	void Line::getInfo(const char *nFill, const char *nStroke, const unsigned int nStrokeWidth, double nX1, double nY1, double nX2, double nY2)
	{
		Figure::getInfo(fill, stroke, strokeWidth);
		x1 = nX1;
		x2 = nX2;
		y1 = nY1;
		y2 = nY2;
	}

	void Line::getInfo(const String &nFill, const String &nStroke, const unsigned int nStrokeWidth, double nX1, double nY1, double nX2, double nY2)
	{
		Figure::getInfo(fill, stroke, strokeWidth);
		x1 = nX1;
		x2 = nX2;
		y1 = nY1;
		y2 = nY2;
	}

	double Line::getX1() const
	{
		return x1;
	}

	double Line::getY1() const
	{
		return y1;
	}

	double Line::getX2() const
	{
		return x2;
	}

	double Line::getY2() const
	{
		return y2;
	}

	void Line::setX1(double nX1)
	{
		x1 = nX1;
	}

	void Line::setY1(double nY1)
	{
		y1 = nY1;
	}

	void Line::setX2(double nX2)
	{
		x2 = nX2;
	}

	void Line::setY2(double nY2)
	{
		y2 = nY2;
	}

	void Line::print() const
	{
		std::cout << "line: coordinates of first point: " <<
			x1 << " " << y1 << " coordinates of second point: " << x2 << " " << y2 << " fill: "
			<< fill << " stroke: " << stroke << " stroke-width: " << strokeWidth
			<< std::endl;
	}

	void Line::printToFile(std::ofstream &out) const
	{
		out << '\t' << "<line x1=\"" << x1 << "\" y1=\"" << y1 << "\" x2=\"" << x2 << "\" y2=\"" << y2 << "\"";
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

	bool Line::withinCircle(const double cx, const double cy, const double r)
	{
		if (pointInsideCircle(x1, y1, cx, cy, r) && (pointInsideCircle(x2, y2, cx, cy, r)))
			return true;
		return false;
	}


}