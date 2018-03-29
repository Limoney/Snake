#ifndef H_APPLE
#define H_APPLE
#include "stuff.h"

class Apple
{
public:
	Apple(int x, int y, char **m);
	~Apple();
	int getX();
	int getY();
	//void show();
private:
	int x;
	int y;
	int color;
};
#endif // !H_APPLE
