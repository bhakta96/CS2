#include<iostream>
#include"graph1.h"

using namespace std;

class FilledCircle
{
private:
	int x;
	int y;
	int radius;

public:
	FilledCircle();
	FilledCircle(int x_val, int y_val, int r_val);
	bool setX(int x_val);
	int getX();
	bool setY(int y_val);
	int getY();
	bool setRadius(int r_val);
	int getRadius();
	void draw();
};

FilledCircle::FilledCircle()
{
	x = 100;
	y = 100;
	radius = 15;
}

FilledCircle::FilledCircle(int x_val, int y_val, int r_val)
{
	setX(x_val);
	setY(y_val);
	setRadius(r_val);
}

bool FilledCircle::setX(int x_val)
{
	if (x_val < 0)
	{
		x = 0;
		return false;
	}
	else if (x_val > 639)
	{
		x = 639;
		return false;
	}

	x = x_val;
	return true;
}

int FilledCircle::getX()
{
	return x;
}

bool FilledCircle::setY(int y_val)
{
	if (y_val < 0)
	{
		y = 0;
		return false;
	}
	else if (y_val > 479)
	{
		y = 479;
		return false;
	}

	y = y_val;
	return true;
}

int FilledCircle::getY()
{
	return y;
}

bool FilledCircle::setRadius(int r_val)
{
	if (r_val < 0)
	{
		radius = 0;
		return false;
	}
	else if (r_val > 30)
	{
		radius = 30;
		return false;
	}

	radius = r_val;
	return true;
}

int FilledCircle::getRadius()
{
	return radius;
}

void FilledCircle::draw()
{
	for (int i = 0; i < radius; i++)
	{
		drawCircle(i+1, x, y);
		
	}
}

int main()
{
	//Variable Declaration/Initialization
	int i = 0;
	int x = 0;
	int y = 0;
	int radius = 0;
	bool res1 = 0;
	bool res2 = 0;
	bool res3 = 0;
	char repeat = NULL;
	FilledCircle circle1;
	FilledCircle circle2(50, 50, 10);

	//Display the Graphics
	displayGraphics();
	do{
		//Prompt for the x/y coordinates
		cout << "Enter x/y coords: ";
		cin >> x >> y;

		//Prompt for the radius
		cout << "Enter radius: ";
		cin >> radius;

		//Set the x coord
		res1 = circle1.setX(x);

		if (!res1)
			cout << "Input for x-coord invalid -reset to a default value" << endl;

		//Set the y coord
		res2 = circle1.setY(y);

		if (!res2)
			cout << "Input for y-coord invalid -reset to a default value" << endl;


		//Set the radius
		res3 = circle1.setRadius(radius);

		if (!res3)
			cout << "Input for radius invalid -reset to a default value" << endl;

		//Draw the circle
		circle1.draw();

		//Display the coordinate info under the circle
		gout << setPos(circle1.getX()  -circle1.getRadius()- 12, circle1.getY() + circle1.getRadius() + 15)
			<< "(" << circle1.getX() << "," << circle1.getY() << ") " << endg;

		//Display the radius info
		gout << setPos(circle1.getX() - circle1.getRadius() - 12, circle1.getY() + circle1.getRadius() + 30)
			<< "Radius: " << circle1.getRadius() << endg;

		cout << "Repeat(y/n)? ";
		cin >> repeat;

	} while (repeat == 'y' || repeat =='Y');
}
