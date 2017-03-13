#include<iostream>
#include"GenPoint.h"
#include"graph1.h"
#include"GenRectangle.h"

GenRectangle::GenRectangle()
{
	cout << "In GenRectangle constructor" << endl;
}
void GenRectangle::setPoints(GenPoint ul, GenPoint lr)
{
	this->a.setPoint(ul.getX(), ul.getY());
	this->b.setPoint(lr.getX(), ul.getY());
	this->c.setPoint(lr.getX(), lr.getY());
	this->d.setPoint(ul.getX(), lr.getY());
}
double GenRectangle::getArea()
{
	double area = 0.0;
	area = ((b.getX() - a.getX())  *  (c.getY() - b.getY())); // will get the area
	return area; // return area
}
void GenRectangle::print()
{
	// will print
	Quadrilateral::print();
	gout << setPos(a.getX(), a.getY() - 25) << "Rectangle Information" << endg;
	gout << setPos(a.getX(), a.getY() - 10) << "Area: " << getArea() << endg;
}