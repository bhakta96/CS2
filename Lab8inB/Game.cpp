#include <iostream>
#include <ctime>
#include<cstdlib>
#include "graph1.h"
#include "Rock.h"
#include "Display.h"
#include "Game.h"

Game::Game() // intialize 
{
	rock.setX(0);
	rock.setY(0);

	display.getRock();

	
}
void Game::setRock(Rock rock) // setter
{
	this->rock = rock;
}
void Game::setDisplay(Display display) // setter
{
	this->display = display;
}
Rock Game::getRock() // getter
{
	return rock;
}
Display Game::getDisplay() // getter
{
	return display;
}
void Game::play()
{
	double distance = 0.0;
	double time_v = 0.0;
	const double G = 9.86;

	// set the pos for the 1st rock to be dropped

	
	rock.setX(rand() % 595);
	rock.setY(0);
	while (true)
	{
		
		distance = G * time_v* time_v;

		// set the y to dis

		rock.setY(distance);

		moveObject(display.getRock(), rock.getX(), rock.getY());
		Sleep(10);

		// increment the time 

		time_v += 0.1;

		// see if rock hits
		if (rock.getY() > 435)
		{
			// move the broken rock to the rock
			moveObject(display.getBrokenRock(), rock.getX(), rock.getY());
			replaceObject(display.getRock(), display.getBrokenRock());
			Sleep(500);

			replaceObject(display.getBrokenRock(), display.getRock());

			time_v = 0;

			rock.setX(rand() % 595);
			rock.setY(0);

			// move the rock to a new spot 
			moveObject(display.getRock(), rock.getX(), rock.getY());
		}

		
		
		
	}
}