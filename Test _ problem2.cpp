#include <iostream>
#include "graph1.h"

using namespace std;

void getData(int* no_rects);
int* getXCoords(int no_rects);
int* getYCoords(int no_rects);
void displayRectangles(int no_rects, int* x, int* y);

int main()
{
	displayGraphics();

	int no_rects = 0;
	int* x = 0;
	int * y = 0;

	getData(&no_rects);
	x = getXCoords(no_rects);
	y= getYCoords(no_rects);
	displayRectangles( no_rects, x,  y);
}

void getData(int* no_rects)
{
	cout << "Enter # of boxes: ";
	cin >> *no_rects;

}
int* getXCoords(int no_rects)
{
	int* x_coords = 0;
	int z = 0;
	x_coords = new int[no_rects];

	for (int i = 0; i < no_rects; i++)
	{
		cout << "Enter x-coord for box # " << z + 1 << " :";
		cin >> x_coords[i];
		z++;
	}

	return x_coords;
}
int* getYCoords(int no_rects)
{
	int* y_coords = 0;
	int z = 0;
	y_coords = new int[no_rects];

	for (int i = 0; i < no_rects; i++)
	{
		cout << "Enter y-coord for box # " << z + 1 << " :";
		cin >> y_coords[i];
		z++;
	}

	return y_coords;
}
void displayRectangles(int no_rects, int* x, int* y)
{
	int *object = 0;
	object = new int[no_rects];

	for (int i = 0; i < no_rects; i++)
	{
		object[i]= drawRect(x[i], y[i], 50, 25);

		if (object[i] % 2 == 0)
		{
			setColor(object[i], 255, 0, 0);

		}

		else
		{
			setColor(object[i], 0, 0, 255);
		}
	}
}