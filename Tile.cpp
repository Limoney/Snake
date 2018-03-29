#include "Tile.h"



Tile::Tile(int x, int y, unsigned int color)
{
	this->x = x;
	this->y = y;
	xvel = 0;
	yvel = 0;
	lastx = 0;
	lasty = 0;
	draw = '@';
	this->color = color;
}


Tile::~Tile()
{
}

//void Tile::show()
//{
//	setTextColor(color);
//	gotoxy(x, y);
//	std::cout << draw;
//}

int Tile::update(char **m,std::vector<Apple> &a)
{
	int piecesToAdd=0;
	lastx = x;
	lasty = y;
	x += xvel;
	y += yvel;
	if (x > mapWidth - 2)x = 1;
	else if (x == 0)x = mapWidth - 2;
	if (y > mapHeight - 2)y = 1;
	else if (y == 0)y = mapHeight - 2;
	if (m[x][y] == '@')
	{
		piecesToAdd = -1;
	}
	else if (m[x][y] == 'A') 
	{ 
		for (int i = 0; i < a.size(); i++)
		{
			if (a[i].getX() == x&&a[i].getY() == y)
			{
				a.erase(a.begin() + i);
				piecesToAdd++;
			}
			//dodaæ nowy kawalek ogona
		}
	}
	m[x][y] = '$';
	m[lastx][lasty] = ' ';//potrzebne?

	
	return piecesToAdd;
}

void Tile::follow(Tile t, char **m)
{
	lastx = x;
	x= t.lastx;
	lasty = y;
	y = t.lasty;
	m[x][y] = '@';
	m[lastx][lasty] = ' ';
}

void Tile::control()
{
	if (GetAsyncKeyState(87) && yvel!=1) { xvel = 0; yvel = -1; }
	else if (GetAsyncKeyState(83) && yvel != -1) { xvel = 0; yvel = 1; }
	else if (GetAsyncKeyState(65) && xvel != 1) { xvel = -1; yvel = 0; }
	else if (GetAsyncKeyState(68) && xvel != -1) { xvel = 1; yvel = 0; }
}

void Tile::setColor(unsigned int c)
{
	color = c;
}

void Tile::setVelocity(int x, int y)
{
	xvel = x;
	yvel = y;
}

int Tile::getLastX()
{
	return lastx;
}
int Tile::getLastY()
{
	return lasty;
}

int Tile::getCurrentX()
{
	return x;
}

int Tile::getCurrentY()
{
	return y;
}
