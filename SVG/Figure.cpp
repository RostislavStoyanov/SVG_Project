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
		std::cerr << "Not enough memory!" << std::endl;
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
	if (nStrokeWidth == 0) strokeWidth = 1;
	else this->strokeWidth = nStrokeWidth;
	if (nStroke[0] == 0)
		setValue(stroke,"black");
	else setValue(stroke, nStroke);
	if (nFill[0] == 0)
		setValue(fill, "white");
	else setValue(fill,nFill);
}

void Figure::print()
{
	if (fill&&stroke) {
		std::cout << this->fill << std::endl;
		std::cout << this->stroke << std::endl;
	}
	std::cout << this->strokeWidth << std::endl;
}

void Figure::printToFile(std::ofstream &out)
{
	out << '\t' << '\t' << "fill=\"" << fill << "\" stroke=\"" << stroke << "\" stroke-width=\"" << strokeWidth << "\" />\n";
	out << std::endl;
	return;
}


