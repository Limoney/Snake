#include "snake.h"



Snake::Snake(int size)
{
	for(int i= size-1; i>=0;i--)
	{
		body.push_back(Tile(i+1, 1, 14));
	}
	body[0].setColor(10);
	body[0].setVelocity(1, 0);
}


Snake::~Snake()
{
}

void Snake::update(char **m, std::vector<Apple> &a,int &score)
{
	int amount = 0;
	for (int i = 0; i < body.size(); i++)
	{
		if (i == 0) 
		{ 
			body[i].control(); 
			amount = body[i].update(m,a);
		}
		else body[i].follow(body[i - 1],m);
	}
	for (int i = 0; i < amount; i++)
	{
		body.push_back
		(
			Tile(body[body.size() - 1].getLastX(),
				body[body.size() - 1].getLastY(),
				14)
		);
	}
	if (amount < 0)
	{
		while(body.size()!=5)
		{
			int x = body[body.size() - 1].getCurrentX();
			int y = body[body.size() - 1].getCurrentY();
			m[x][y] = ' ';
			body.pop_back();
		}
		score = 0;
	}
	if(amount>0)score += amount;
}

//void Snake::show()
//{
//	for (int i = body.size()-1; i>=0; i--)
//	{
//		body[i].show();
//	}
//}
