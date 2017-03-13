#include <iostream>
#include "graph1.h"

using namespace std;


void getData(int* r, int* g, int* b, int* radius, int* no_circles);
int* drawChain(int radius, int no_circles);
void colorChain(int* objects, int no_circles, int r, int g, int b);

int main()
{
	displayGraphics();
	int* objects = 0;

	int r = 0;
	int g = 0;	
	int b = 0;
	int radius = 0;
	int no_circles = 0;
	

	getData( &r,  &g,  &b,  &radius,  &no_circles);
	objects = drawChain( radius,  no_circles);
	colorChain(objects,  no_circles,  r,  g, b);
	
}

void getData(int* r, int* g, int* b, int* radius, int* no_circles)
{
	cout << "enter rgb color: ";
	cin >> *r;
	cin >> *g;
	cin >> *b;
	
	cout << "Enter radius: ";
	cin >> *radius;

	cout << "Enter # of circles: ";
	cin >> *no_circles;


}
int* drawChain(int radius, int no_circles)
{
	int x = 100;
	int y = 100;
	int* object = 0;
	object = new int[no_circles];

	for (int i = 0; i < no_circles; i++)
	{
		object[i] = drawCircle(radius, x, y);
		
		x = x + radius;
	
	}

	return object;
}

void colorChain(int* objects, int no_circles, int r, int g, int b)
{
	
	for (int i = 0; i < no_circles; i++)
	{
		if (objects[i] % 2 == 0)
		{
			setColor(objects[i], r, g, b);
		}
		
	}
}