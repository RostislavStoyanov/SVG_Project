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

void Figure::getInfo(const char *, const char *, const unsigned int)
{

}
