#ifndef GAME_H
#define GAME_H

#include"Display.h"
#include "Cart.h"
#include"Rock.h"

class Game
{
private:
	Rock rock;
	Cart cart;
	Display display;
	int no_rocks;
	int score;


public:
	Game();
	void setRock(Rock rock);
	void setCart(Cart cart);
	void setDisplay(Display display);
	Cart getCart();
	Rock getRock();
	Display getDisplay();
	bool detectCollision(Cart cart, Rock rock);
	void play();
	void reset();


};

#endif
