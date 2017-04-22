#include "Figure.h"

void Figure::setValue(char *& p, const char * value)
{
	try {
		size_t valueSize = strlen(value) + 1;
		char* newValue = new char[valueSize];
		delete[] p;
		p = newValue;
		strcpy_s(p, valueSize, value);
	}
	catch (std::bad_alloc&)
	{
		std::cerr << "Not enough memory!\n";
	}
}

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

void Figure::getInfo(const char *nFill, const char *nStroke, const unsigned int nStrokeWidth)
{
	this->strokeWidth = nStrokeWidth;
	setValue(stroke, nStroke);
	setValue(fill,nFill);
}

void Figure::print()
{
	if (fill&&stroke) {
		std::cout << this->fill << std::endl;
		std::cout << this->stroke << std::endl;
	}
	std::cout << this->strokeWidth << std::endl;
}

std::ostream & operator<<(std::ostream& out, const Figure *)
{
	return out;
}
