#include"Figure.h"
#include"Circle.h"
#include"Rectangle.h"
#include"Line.h"

int main()
{
	Figure fig;
	fig.getInfo("red", "black", 2);
	fig.print();
	Line line;
	line.getInfo("red", "blue", 2, 3, 4, 5, 6);
	std::cout << line;
	Circle cir;
	cir.getInfo("black", "yellow", 4, 2, 0, 42);
	std::cout << cir;
	return 0;
}