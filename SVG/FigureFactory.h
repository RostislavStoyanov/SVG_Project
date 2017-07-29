#pragma once
#include"Figure.h"
#include"Rectangle.h"
#include"Circle.h"
#include"Line.h"
namespace Figures
{
	class FigureFactory
	{
	public:
		static Figure* createFigure(const char*);
	};
}

