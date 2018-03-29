#include "Apple.h"



Apple::Apple(int x, int y,char **m)
{
	this->x = x;
	this->y = y;
	color = 12;
	m[x][y] = 'A';
}


Apple::~Apple()
{
}

int Apple::getX()
{
	return x;
}

int Apple::getY()
{
	return y;
}

//void Apple::show()
//{
//	setTextColor(color);
//	gotoxy(x, y);
//	std::cout << "A";
//}
