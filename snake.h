#ifndef H_SNAKE
#define H_SNAKE
#include "Tile.h"
#include <vector>
class Snake
{
public:
	Snake(int size);
	~Snake();
	void update(char **m, std::vector<Apple> &a, int &score);
	//void show();
private:
	std::vector<Tile> body;
};
#endif // !H_SNAKE
