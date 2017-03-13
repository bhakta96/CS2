// Asav Bhakta
// Lab8inB
// rocks droping and breaking game
#include <iostream>
#include <ctime>
#include "graph1.h"
#include "Rock.h"
#include "Display.h"
#include "Game.h"

using namespace std;

int main()
{
	//Variable Declaration/Initialization
	Rock rock;
	Display display;
	Game game;
	char repeat = 'y';

	//Display Graphics
	displayGraphics();

	//Set up the display
	display.displayInitialScene();


	//Set the objects
	game.setDisplay(display);
	game.setRock(rock);
	srand(time(0));

	do
	{
		//Play the game
		game.play();

		//Repeat?
		cout << "Repeat the program? (y/n): ";
		cin >> repeat;

	} while ((repeat == 'y') || (repeat == 'Y'));


	return 0;
}

