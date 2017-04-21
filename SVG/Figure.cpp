#include "Figure.h"

Figure::Figure()
{
	fill = NULL;
	stroke = NULL;
	strokeWidth = 0;
}

Figure::~Figure()
{
	delete[] fill;
	delete[] stroke;
}

void Figure::getInfo(const char *fill, const char *stroke, const unsigned int strokeWidth)
{
	this->strokeWidth = strokeWidth;
	int fillLen, strokeLen;
	fillLen = std::strlen(fill) + 1;
	strokeLen = std::strlen(stroke) + 1;
	char* newFill = new char[fillLen];
	strcpy_s(newFill,fillLen, fill);
	delete[] this->fill;
	this->fill = newFill;
	char* newStroke = new char[strokeLen];
	strcpy_s(newStroke,strokeLen, stroke);
	delete[] this->stroke;
	this->stroke = newStroke;
}
