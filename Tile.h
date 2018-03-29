#ifndef H_TILE
#define H_TILE
#include "stuff.h"
#include <vector>
#include "Apple.h"
class Tile
{
public:
	Tile(int x, int y, unsigned int color);
	~Tile();
	//void show();
	int update(char **m,std::vector<Apple> &a);
	void follow(Tile t, char **m);
	void control();
	char draw;
	void setColor(unsigned int c);
	void setVelocity(int x, int y);
	int getLastX();
	int getLastY();
	int getCurrentX();
	int getCurrentY();
private:
	int x;
	int y;
	int xvel;
	int yvel;
	int lastx;
	int lasty;
	unsigned int color;
};
#endif // !H_TILE
