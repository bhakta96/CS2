#include<iostream>
#include"GenRectangle.h"
#include"graph1.h"

GenRectangle::GenRectangle() // intialize/ declare private data field to their reaspected values
{
	x = 100;
	y = 25;
	width = 20;
	height = 30;
}
int GenRectangle::getWidth()
{
	return width; // return width of rectangle 
}
int GenRectangle::getHeight()
{
	return height;// return height of rectangle 
}
int GenRectangle::getX()
{
	return x; // return x coord
}
int GenRectangle::getY()
{
	return y; // return y coord
}
int GenRectangle::getArea()
{
	double area = 0.0; 

	area = width * height;

	return area; // will return area of rect
}
int GenRectangle::getPerimeter()
{
	double perimeter = 0.0;
	perimeter = 2 * (height + width);

	return perimeter; // will return perimeter of rect
}
void GenRectangle::setWidth(int width) // will clip the value
{
	if (width > 50)
	{
		width = 50;
	}
	if (width < 1)
	{
		width = 1;
	}

	this->width = width;
}
void GenRectangle::setHeight(int height)// will clip the value
{
	if (height > 50)
	{
		height = 50;
	}
	if (height < 1)
	{
		height = 1;
	}

	this->height = height;
}
void GenRectangle::setX(int x)// will clip the value
{
	if (x > 539)
	{
		x = 539;
	}
	if (x < 100)
	{
		x = 100;
	}

	this->x = x;
}
void GenRectangle::setY(int y)// will clip the value
{
	if (y > 455)
	{
		y = 455;
	}
	if (y < 25)
	{
		y = 25;
	}

	this->y = y;

}
char* GenRectangle::getType()
{
	int i = 0;
	char rect_type1[] = "SMALL_RECTANGLE";
	char rect_type2[] = "MEDIUM_RECTANGLE";
	char rect_type3[] = "LARGE_RECTANGLE";
	char* type = NULL;
	double area = getArea();

	if (area < 300 && area > 0)   // will define the size of rectangle 
	{
		type = new char[strlen(rect_type1) + 1];
		strcpy(type, rect_type1);
		return type;
	}
	else if ((area >= 300) && (area < 1000))
	{
		type = new char[strlen(rect_type2) + 1];
		strcpy(type, rect_type2);
		return type;
	}
	else if (area >= 1000)
	{
		type = new char[strlen(rect_type3) + 1];
		strcpy(type, rect_type3);
		return type;
	}
}
void GenRectangle::draw()
{
	double area = getArea();
	int obj1 = 0;
	int obj2 = 0;
	int obj3 = 0;
	int obj4 = 0;
	
	// will draw lines to draw hallow rectangle and set their color repectively
	if (area < 300 && area > 0) 
	{
		obj1 = drawLine(x, y, x + width, y, 2);
		obj2 = drawLine(x, y + height, x + width, y + height, 2);
		obj3 = drawLine(x, y, x, y + height, 2);
		obj4 = drawLine(x + width, y, x + width, y + height, 2);
		setColor(obj1, 255, 0, 0);
		setColor(obj2, 255, 0, 0);
		setColor(obj3, 255, 0, 0);
		setColor(obj4, 255, 0, 0);
	}
	else if ((area >= 300) && (area < 1000))
	{
		
		
		obj1 = drawLine(x, y, x + width, y, 2);
		obj2 = drawLine(x, y + height, x + width, y + height, 2);
		obj3 = drawLine(x, y, x , y + height, 2);
		obj4 = drawLine(x + width, y, x + width, y + height, 2);
		setColor(obj1, 0, 255, 0);
		setColor(obj2, 0, 255, 0);
		setColor(obj3, 0, 255, 0);
		setColor(obj4, 0, 255, 0);
		
		

	}
	else if (area >= 1000)
	{
		obj1 = drawLine(x, y, x + width, y, 2);
		obj2 = drawLine(x, y + height, x + width, y + height, 2);
		obj3 = drawLine(x, y, x, y + height, 2);
		obj4 = drawLine(x + width, y, x + width, y + height, 2);
		setColor(obj1, 0, 0, 255);
		setColor(obj2, 0, 0, 255);
		setColor(obj3, 0, 0, 255);
		setColor(obj4, 0, 0, 255);
	}
}