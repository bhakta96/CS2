// Asav Bhakta
// Lab review 

#include<iostream>
#include"Circle.h"
#include"graph1.h"

using namespace std;

int main()
{
	displayGraphics();

	Circle cir1;
	Circle cir2;
	Circle cir3;
	int x = 0;
	int y = 0;
	int radius = 0;
	bool value = false;

	cir1.draw();

	gout << setPos(cir1.getX(), cir1.getY() + 15) << "Area: " << cir1.getArea() << endg;
	gout << setPos(cir1.getX(), cir1.getY() + 30) << "Perimeter: " << cir1.getPerimeter() << endg;
	gout << setPos(cir1.getX(), cir1.getY() + 45) << "Type of Circle: " << cir1.getType() << endg;

	cout << "Enter x: ";
	cin >> x;

	cout << "Enter y: ";
	cin >> y;

	cout << "Enter radius: ";
	cin >> radius;

	cir2.setX(x);
	cir2.setY(y);
	cir2.setRadius(radius);

	cir2.draw();

	gout << setPos(cir2.getX(), cir2.getY() + cir2.getRadius()+ 15) << "Area: " << cir2.getArea() << endg;
	gout << setPos(cir2.getX(), cir2.getY() + cir2.getRadius()+ 30) << "Perimeter: " << cir2.getPerimeter() << endg;
	gout << setPos(cir2.getX(), cir2.getY() + cir2.getRadius() + 45) << "Type of Circle: " << cir2.getType() << endg;

	 value = (cir1 == cir2);

	 if (value)
	 {
		 gout << setPos((cir1.getX() + cir2.getX()) / 2, (cir1.getY() + cir2.getY()) / 2) << "The cir1 and cir2 are equal!" << endg;
	 }
	 if (!value)
	 {
		 gout << setPos((cir1.getX() + cir2.getX()) /2, (cir1.getY() + cir2.getY()) / 2) << "The cir1 and cir2 are not equal!" << endg;
	 }

	 cir3 =! cir2;

	 cir3.draw();
	 gout << setPos(cir3.getX(), cir3.getY() + cir3.getRadius() + 15) << "Area: " << cir3.getArea() << endg;
	 gout << setPos(cir3.getX(), cir3.getY() + cir3.getRadius() + 30) << "Perimeter: " << cir3.getPerimeter() << endg;
	 gout << setPos(cir3.getX(), cir3.getY() + cir3.getRadius() + 45) << "Type of Circle: " << cir3.getType() << endg;

}

