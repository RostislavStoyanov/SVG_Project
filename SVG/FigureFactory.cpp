#include "FigureFactory.h"
namespace Figures
{
	Rectangle * FigureFactory::createRect()
	{
		return new Rectangle;
	}
	Circle * FigureFactory::createCirc()
	{
		return new Circle;
	}
	Line * FigureFactory::createLine()
	{
		return new Line;
	}
}