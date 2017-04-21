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
