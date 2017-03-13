// Asav Bhakta
// Lab Final
// This program will use map and calculate distance from little rock

#include <iostream>
#include "graph1.h"
#include "City.h"

using namespace std;

int main()
{
	//Variable Declaration/Initialization
	char fileName[255];
	char repeat = 'y';
	City city;

	//Display graphics
	displayGraphics();

	//Run program as many times as desired
	do
	{
		//Prompt for fn
		cout << "Enter filename that contains words: ";
		cin >> fileName;

		//Set the filename
		city.setData(fileName);

		//Draw the scene
		city.draw();

		cout << "Distance between Little Rock and " << city.getName() << " located on " << city.getHighway() << endl;
		cout << "with an elevation  of " << city.getElevation() << " feet is " << city.computeDistance() << " miles" << endl;
		cout << "Repeat? (y/n): ";
		cin >> repeat;

		//Clear screen

		system("cls");
		clearGraphics();

	} while ((repeat == 'y') || (repeat == 'Y'));

	return 0;
}