#include <iostream>
#include <ctime>
#include "graph1.h"
#include "Display.h"

Display::Display()
{
	// intialize all to 0
	cart = 0;
	brokenRock = 0;
	rock = 0;
	rockInCart = 0;
}
int Display::getCart() // getter
{
	return cart;
}
int Display::getRock() // getter
{
	return rock;

}
int Display::getBrokenRock() // getter
{
	return brokenRock;
}
int Display::getRockInCart() // getter
{
	return rockInCart;
}
void Display::displayInitialScene() // will diplay the scene 
{
	int tracks = 0;
	displayPNG("stonebackground.png", 0, 0);
	tracks = displayPNG("tracks.png", 0, 0);
	rock = displayPNG("rock.png", 650, 0);
	rockInCart = displayPNG("cartWithRock.png", 650, 0);
	brokenRock = displayPNG("brokenrock.png", 650, 0);

	cart = displayPNG("cart.png", 0, 360);



}