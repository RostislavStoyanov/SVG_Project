#include "Rectangle.h"

namespace Figures
{
	Rectangle::Rectangle() :height(0), width(0),
		x(0), y(0), Figure()
	{
	}

	Rectangle::Rectangle(const String &nFill, const String &nStroke, const unsigned int nStrokeWidth, double nX, double nY, double nWidth, double nHeight) :
		x(nX), y(nY), height(nHeight), width(nWidth),
		Figure(nFill, nStroke, nStrokeWidth)
	{
	}

	Rectangle::Rectangle(const char *nFill, const char *nStroke, const unsigned int nStrokeWidth, double nX, double nY, double nWidth, double nHeight) :
		x(nX), y(nY), height(nHeight), width(nWidth),
		Figure(nFill, nStroke, nStrokeWidth)
	{
	}


	void Rectangle::getInfo(const char *nFill, const char *nStroke, const unsigned int nStrokeWidth, double nX, double nY, double nWidth, double nHeight)
	{
		Figure::getInfo(nFill, nStroke, nStrokeWidth);
		x = nX;
		y = nY;
		width = nWidth;
		height = nHeight;
	}

	void Rectangle::getInfo(const String &nFill, const String &nStroke, const unsigned int nStrokeWidth, double nX, double nY, double nWidth, double nHeight)
	{
		Figure::getInfo(nFill, nStroke, nStrokeWidth);
		x = nX;
		y = nY;
		width = nWidth;
		height = nHeight;
	}

	double Rectangle::getX() const
	{
		return x;
	}

	double Rectangle::getY() const
	{
		return y;
	}

	double Rectangle::getWidth() const
	{
		return width;
	}

	double Rectangle::getHeight() const
	{
		return height;
	}

	void Rectangle::setX(const double nX)
	{
		x = nX;
	}

	void Rectangle::setY(const double nY)
	{
		y = nY;
	}

	void Rectangle::setWidth(const double nWidth)
	{
		width = nWidth;
	}

	void Rectangle::setHeight(const double nHeight)
	{
		height = nHeight;
	}

	void Rectangle::print() const
	{
		std::cout << "rectangle: x=" <<
			x << " y= " << y << " width= " << width << " height= " << height << "\n \t fill: "
			<< fill << " stroke: " << stroke << " stroke-width: "
			<< strokeWidth << std::endl;
	}

	void Rectangle::printToFile(std::ofstream &out) const
	{
		out << "\t<rect x=\"" << x << "\" y=\"" << y << "\" width=\"" << width << "\" height=\"" << height << "\"";
		out << std::endl;
		Figure::printToFile(out);
		return;
	}

	void Rectangle::translate(const double addX, const double addY)
	{
		x += addX;
		y += addY;
	}

	bool Rectangle::withinRectangle(const double rectX, const double rectY, const double rectWidth, const double rectHeight)
	{
		if ((pointInsideRectangle(x, y, rectX, rectY, rectWidth, rectHeight)) && pointInsideRectangle((x + width), (y + height), rectX, rectY, rectWidth, rectHeight)
			&& pointInsideRectangle(x + width, y, rectX, rectY, rectWidth, rectHeight) && pointInsideRectangle(x, y + height, rectX, rectY, rectWidth, rectHeight))
			return true;
		return false;
	}

	bool Rectangle::withinCircle(const double cx, const double cy, const double r)
	{
		if (pointInsideCircle(x, y, cx, cy, r) && pointInsideCircle(x + width, y + height, cx, cy, r) &&
			pointInsideCircle(x + width, y, cx, cy, r) && pointInsideCircle(x, y + height, cx, cy, r))
			return true;
		return false;
	}


}