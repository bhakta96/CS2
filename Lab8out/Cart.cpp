#include <iostream>
#include <ctime>
#include "graph1.h"
#include "Cart.h"

Cart::Cart()
{
	x = 0;
	y = 0;
}
void Cart::setX(int x) // setter and will clip the value 
{
	if (x < 0)
	{
		x = 0;

	}

	if (x > 570)
	{
		x = 570;
	}
	this->x = x;
}
void Cart::setY(int y) // setter and will clip the value 
{
	if (y < 0)
	{
		y = 0;

	}

	if (y > 440)
	{
		y = 440;
	}
	this->y = y;
}
int Cart::getX() // getter
{
	return x;
}
int Cart::getY() // getter
{
	return y;
}

