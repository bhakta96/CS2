#include<iostream>
#include"Circle.h"
#include"graph1.h"

Circle::Circle()
{
	x = 50;
	y = 50;
	radius = 5;
}
void Circle::setX(int x)
{
	if (x > 640)
	{
		x = 640;
	}
	if (x < 0)
	{
		x = 0;
	}

	this->x = x;
}
void Circle::setY(int y)
{
	if (y > 480)
	{
		y = 480;
	}
	if (y < 0)
	{
		y = 0;
	}

	this->y = y;
}
void Circle::setRadius(int radius)
{
	if (radius > 20)
	{
		radius = 20;
	}
	if (radius < 0)
	{
		radius = 0;
	}

	this->radius = radius;
}
int Circle::getX()
{
	return x;
}
int Circle::getY()
{
	return y;
}
int Circle::getRadius()
{
	return radius;
}
int Circle::getArea()
{
	int area = 0;

	area = (3.14 * radius * radius);

	return area;
}
int Circle::getPerimeter()
{
	int perimeter = 0;

	perimeter = (2 * 3.14 * radius);

	return perimeter;
}
char* Circle::getType()
{
	int i = 0;
	char circle_type1[] = "SMALL_CIRCLE";
	char circle_type2[] = "MEDIUM_CIRCLE";
	char circle_type3[] = "LARGE_CIRCLE";
	char* type = NULL;
	double area = getArea();

	if (area <= 100)
	{
		type = new char[strlen(circle_type1) + 1];
		strcpy(type, circle_type1);
		return type;
	}
	else if ((area > 100) && (area <= 300))
	{
		type = new char[strlen(circle_type2) + 1];
		strcpy(type, circle_type2);
		return type;
	}
	else if (area > 300)
	{
		type = new char[strlen(circle_type3) + 1];
		strcpy(type, circle_type3);
		return type;
	}
}
void Circle::draw()
{
	drawCircle(radius, x, y);
}
bool Circle::operator==(Circle rs)
{
	double area_ls = getArea();
	double area_rs = rs.getArea();

	if (area_ls == area_rs)
	{
		return true;
	}

	return false;
}
void Circle::operator=(Circle rs)
{
	this->x = rs.x;
	this->y = rs.y;
	this->radius = rs.radius;
}
Circle Circle::operator!()
{
	Circle result;

	result.radius = 20 - this->radius;
	result.x = 640 - this->x;
	result.y = 480 - this->y;

	return result;
}