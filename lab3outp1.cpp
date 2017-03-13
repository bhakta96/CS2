// Asav Bhakta
// Lab3outp1
// Bug zapper game

#include <iostream>
#include <ctime>
#include "graph1.h"

using namespace std;

//Protoypes
int getNoObjects();
int* getXCoords(int no_objects);
int* getYCoords(int no_objects);
int* displayObjects(int* x_coords, int* y_coords, int no_objects);
void play(int* x, int* y, int* objects, int no_objects);



int main()
{
	// variable intialization and declaration.
	int no_objects = 0;
	int* objects = NULL;
	int* x_coords = NULL;
	int* y_coords = NULL;
	char repeat;

	int start, end = 0;

	// do while loop if player want to play the game again
	do{ 
		//Initialize seed
		srand(time(0));

		//Display graphics
		displayGraphics();
		
		start = time(0);

		do{
			end = time(0);
			displayPNG("intro.png", 0, 0);

		  } while ((end - start) < 5);


		//1. Get the number of objects to be displayed
		no_objects = getNoObjects();

		displayPNG("grass.png", 0, 0);

		//2. Generate the x-coords for each object
		x_coords = getXCoords(no_objects);

		//3. Generate the y-coords for each object
		y_coords = getYCoords(no_objects);


		//4. Display the objects at the randomly generated coordinates
		objects = displayObjects(x_coords, y_coords, no_objects);



		//5. User will start playing the game

		play(x_coords, y_coords, objects, no_objects);
		
		cout << "Play again? : ";
		cin >> repeat;

		if (repeat == 'y' || repeat == 'Y')
		{
			delete[] x_coords;
			delete[] y_coords;
			delete[] objects;
		}
		
	} while (repeat == 'Y' || repeat == 'y');
		

	
	
	return 0;
}

//This funtion will ask user to enter the number of bugs they want to display 
int getNoObjects()
{
	int getObjects = 0;

	cout << "Enter # bugs to display (between 30 and 50): ";
	cin >> getObjects;

	while (getObjects < 30 || getObjects > 50) // loop to make sure user dont enter diffenrent number
		{
			cout << "Enter # bugs to display (between 30 and 50): ";
			cin >> getObjects;
		}
	
	return getObjects; 
}

int* getXCoords(int no_objects) // will generate random x cordinate to display bug
{
	int i = 0;
	int* x = NULL;

	x = new int[no_objects];

	for (i = 0; i < no_objects; i++)
	{
		x[i] = rand() % (640 - 64);
	}
	return x;
}
int* getYCoords(int no_objects) // will generate random y cordinate to display bug
{
	int i = 0;
	int* y = NULL;

	y = new int[no_objects];

	for (i = 0; i < no_objects; i++)
	{
		y[i] = rand() % (440-65) + 40;
	}
	return y;
}
int* displayObjects(int* x_coords, int* y_coords, int no_objects) // will display bugs 
{

	int* object = 0;
	int rectangle= 0;
	object = new int[no_objects];

	for (int i = 0; i < no_objects; i++)
	{
		
			object[i] = displayPNG("bugs.png", x_coords[i], y_coords[i]);
		
	}

	rectangle = drawRect(250, 0, 200, 40);
	setColor(rectangle, 255, 255, 255);

	return object;

}

void play(int* x, int* y, int* objects, int no_objects) // will let user play the game 
{
	// variable decleration 
	int pos_x, pos_y, start, end, score   = 0;
	
	start = time(0);
	
	do // do while loop for 10 second play
	{
		end = time(0);

		gout << setPos(360, 20) << " Time: " << end - start << endg; // this will count the time in sec
		
		if (leftMouse(pos_x, pos_y)) // mouse function 
		{
			for (int i = 0; i < no_objects; i++)
			{
				if ((pos_x > x[i]) && (pos_x < x[i] + 64) && (pos_y > y[i]) && (pos_y < y[i] + 64)) // if the mouse courser is on the bug it will remove the bug
				{
					removeObject(objects[i]);
					score++;
					
					// increment the x and y value to -1 so score will be accurate 
					x[i] = -1;
					y[i] = -1;
					
				}
				
				gout << setPos(285, 20) << "Score: " << score << endg;
			}

		}
	} while ((end - start) < 10);
	
	gout << setPos(285, 35) << "Game Over!" << endg;
}
