#include "FigureFactory.h"
namespace Figures
{
	Figure * FigureFactory::createFigure(const char *figure)
	{
		if (!strcmp(figure, "rect") || !strcmp(figure, "rectangle"))
			return new Rectangle;
		if (!strcmp(figure, "circ") || !strcmp(figure, "circle"))
			return new Circle;
		if (!strcmp(figure, "line"))
			return new Line;
		return nullptr;
	}
}