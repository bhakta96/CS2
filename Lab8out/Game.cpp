#include <iostream>
#include <ctime>
#include<cstdlib>
#include "graph1.h"
#include "Rock.h"
#include "Display.h"
#include"Cart.h"
#include "Game.h"

Game::Game() // intialize 
{
	rock.setX(0);
	rock.setY(0);


	display.getRock();
	display.getCart();
	display.getRockInCart();
	

	cart.setX(0);
	cart.setY(0);

	no_rocks = 0;
	score = 0;

}
void Game::setRock(Rock rock) // setter
{
	this->rock = rock;
}
void Game::setDisplay(Display display) // setter
{
	this->display = display;
}
void Game::setCart(Cart cart)
{
	this->cart = cart;
}
Rock Game::getRock() // getter
{
	return rock;
}
Cart Game::getCart()
{
	return cart;
}
Display Game::getDisplay() // getter
{
	return display;
}
bool Game:: detectCollision(Cart cart, Rock rock)
{
	int cart_x = cart.getX();
	int cart_y = cart.getY();
	int rock_x = rock.getX();
	int rock_y = rock.getY();
	
	if ((cart_x < rock_x +22) && (cart_x + 60 > rock_x) && (cart_y < rock_y))//&&(cart_y + 10 > rock_y))
	{
		return true;
	}
	
	return false;
}
void Game::play()
{
	double distance = 0.0;
	double time_v = 0.0;
	const double G = 9.86;
	int speed = 0;
	bool check = false;
	int start, end, obj = 0;
	
	//Initialize seed
	srand(time(0));

	Rock rock_check;
	Cart cart_check;
	

	// set the pos for the 1st rock to be dropped


	rock.setX(rand() % 595);
	rock.setY(0);
	
	start = time(0);
	obj = drawRect(250, 0, 90, 40);
	setColor(obj, 255, 255, 255);

	do
	{
		end = time(0);
		gout << setPos(260, 30) << setColor(0, 0, 0) << "Time: " << end - start << endg;


		distance = G * time_v* time_v;

		// set the y to dis
	//	speed = 60;
		rock.setY(distance);
	//	cart.setX(speed);
		moveObject(display.getRock(), rock.getX(), rock.getY());
		
		Sleep(10);

		// increment the time 

		time_v += 0.1;

		// see if rock hits
		if (rock.getY() > 435)
		{
			// move the broken rock to the rock
			no_rocks++;
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
		if (left()) // if pressed left arrow key it move left 60pxl
		{
			cart.setX(-60 + speed);
			cart.setY(360);
			moveObject(display.getCart(), cart.getX(), cart.getY());
			
			speed -= 60;
			cart.setX(speed);

			if (speed < 0)
				speed = 0;
			
			

		}
		if (right()) //if pressed right arrow key it move right 60pxl
		{
			cart.setX(60+ speed);
			cart.setY(360);
			moveObject(display.getCart(), cart.getX(), cart.getY());
			
			speed += 60;
			cart.setX(speed);

			if (speed > 600)
				speed = 600;
		}
		check = detectCollision(cart,rock);
		cart.setY(360);
		if (check)
		{
			
			
			replaceObject(display.getCart(),display.getRockInCart());
		
			moveObject(display.getRock(), 650, 0);
			moveObject(display.getRockInCart(), cart.getX(), cart.getY());
		
			Sleep(500);
		
			replaceObject(display.getRockInCart(), display.getCart());
			
			moveObject(display.getCart(), cart.getX(), cart.getY());
			

			replaceObject(display.getBrokenRock(), display.getRock());

			time_v = 0;

			rock.setX(rand() % 595);
			rock.setY(0);
			
			// move the rock to a new spot 
			moveObject(display.getRock(), rock.getX(), rock.getY());
			//increment score 
			score++;
			no_rocks++; 
		}
		
		//Create Score Box Statement
		

		gout << setPos(260, 10) << setColor(0, 0, 0) << "Score: " << score << endg;
		gout << setPos(260, 20) << setColor(0, 0, 0) << "Rocks: " << no_rocks << endg;
		
	




	} while ((end - start) < 30);

	gout << setPos(260, 30) << setColor(0, 0, 0) << "Game Over!"  << endg;
	
	
}
void Game::reset()
{
	//intialize to intial value 
	rock.setX(0);
	rock.setY(0);
	cart.setX(0);
	cart.setY(360);
	no_rocks = 0;
	score = 0;

	display.getRock();
	display.getCart();
	moveObject(display.getCart(), cart.getX(), cart.getY());
	display.getRockInCart();
	display.getBrokenRock();


	

	
}