#include <vector>
#include <Windows.h>
#include "snake.h"
#include "Apple.h"
#include "stuff.h"
#include <time.h>
void fillMap(char **m);
void showMap(char **m);
void spawnApple(std::vector<Apple>&a, char **m);
int score = 0;

int main()
{
	//SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, PCONSOLE_FONT_INFOEX());
	char **map = new char*[mapWidth];
	for (int i = 0; i < mapWidth; i++)
	{
		map[i] = new char[mapHeight];
	}
	fillMap(map);
	srand(time(NULL));
	Snake snake(5);
	std::vector<Apple>apples;
	while (true)
	{
		
		Sleep(100);
		system("cls");
		showMap(map);
		//for (Apple apple : apples)
		//{
		//	apple.show();
		//}
		//zrobiæ sprawdzanie wygranej
		snake.update(map,apples,score);
		if (apples.size() < 2) spawnApple(apples, map);
		gotoxy(mapWidth + 1, mapHeight / 2); std::cout << "Score: " << score;
		//snake.show();
	}
	return 0;
}

void fillMap(char ** m)
{
	for (int y =0;y<mapHeight;y++)
	{
		for (int x=0;x<mapWidth;x++)
		{
			if(y==0 || y==mapHeight-1)m[x][y] = '-';
			if (x == 0 || x == mapWidth - 1)m[x][y] = '|';
			if (x > 0 && x < mapWidth - 1 && y>0 && y < mapHeight - 1)m[x][y] = ' ';
		}
		std::cout << std::endl;
	}
}

void showMap(char **m)
{
	setTextColor(3);
	for (int y = 0; y<mapHeight; y++)
	{
		for (int x = 0; x<mapWidth; x++)
		{
			if(m[x][y]=='$')setTextColor(10);
			else if (m[x][y] == '@')setTextColor(14);
			else if (m[x][y] == 'A')setTextColor(12);
			else setTextColor(3);
			std::cout << m[x][y];
		}
		std::cout << std::endl;
	}
}

void spawnApple(std::vector<Apple>& a, char ** m)
{
	//poprawiæ pêtle - je¿eli zostanie 1 wolne miejsce to pêtelka siê bêdzie wykonywaæ wiecznie ;/
	int x;
	int y;
	do
	{
		x= (rand() % (mapWidth - 2)) + 1;
		y= (rand() % (mapHeight - 2)) + 1;
	} while (m[x][y]!=' ');
	
	a.push_back(Apple(x,y,m));
}
