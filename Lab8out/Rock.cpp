#include <iostream>
#include <ctime>
#include "graph1.h"
#include "Rock.h"

Rock::Rock()
{
	x = 0;
	y = 0;

}
void Rock::setX(int x)
{
	if (x < 0)
	{
		x = 0;

	}

	if (x > 595)
	{
		x = 595;
	}
	this->x = x;

}
void Rock::setY(int y)
{
	if (y < 0)
	{
		y = 0;

	}

	if (y > 436)
	{
		y = 436;
	}
	this->y = y;
}
int Rock::getX()
{
	return x;

}
int Rock::getY()
{
	return y;

}