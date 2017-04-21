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
	line.getInfo("red", "blue", 2, 2, 2, 2, 2);
	std::cout << line;
	return 0;
}