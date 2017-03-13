#include"Display.h"
#include"Rock.h"
#ifndef GAME_H
#define GAME_H

class Game
{
private:
	Rock rock;
	Display display;

public:
	Game();
	void setRock(Rock rock);
	void setDisplay(Display display);
	Rock getRock();
	Display getDisplay();
	void play();

};

#endif
