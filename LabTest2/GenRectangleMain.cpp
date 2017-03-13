// Asav Bhakta
// Lab test 2
// this program will display colored hollow rectangle and show their area and perimeter
#include<iostream>
#include"graph1.h"
#include"GenRectangle.h"

using namespace std;

int main()
{
	displayGraphics(); // display graphics

	GenRectangle rect1; // default constructor
	GenRectangle rect2;

	int x = 0;
	int y = 0;
	int width = 0;
	int height = 0;

	rect1.draw(); // draw first rect

	// will display area , perimeter and rect type
	gout << setPos(rect1.getX(), rect1.getY() + rect1.getHeight() + 15) << "rect1 "  << endg;
	gout << setPos(rect1.getX(), rect1.getY() + rect1.getHeight() + 30) << "Area: " << rect1.getArea() << endg;
	gout << setPos(rect1.getX(), rect1.getY() + rect1.getHeight() + 45) << "Perimeter: " << rect1.getPerimeter() << endg;
	gout << setPos(rect1.getX(), rect1.getY() + rect1.getHeight() + 60) << "Type: " << rect1.getType() << endg;

	cout << "Enter x/y coordinate: ";
	cin >> x >> y;

	cout << "Enter width for rectangle: ";
	cin >> width;

	cout << "Enter height for rectangle: ";
	cin >> height;

	// will set input to respected field
	rect2.setX(x);
	rect2.setY(y);
	rect2.setHeight(height);
	rect2.setWidth(width);

	rect2.draw(); // display rect2

	// will display area , perimeter and rect type for rect2
	gout << setPos(rect2.getX(), rect2.getY() + rect2.getHeight() + 15) << "rect2 " << endg;
	gout << setPos(rect2.getX(), rect2.getY() + rect2.getHeight() + 30) << "Area: " << rect2.getArea() << endg;
	gout << setPos(rect2.getX(), rect2.getY() + rect2.getHeight() + 45) << "Perimeter: " << rect2.getPerimeter() << endg;
	gout << setPos(rect2.getX(), rect2.getY() + rect2.getHeight() + 60) << "Type: " << rect2.getType() << endg;



}