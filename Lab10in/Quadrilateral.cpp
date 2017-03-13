#include<iostream>
#include"Quadrilateral.h"
#include"Color.h"
#include"GenPoint.h"
#include"graph1.h"

Quadrilateral::Quadrilateral()//Sets all points/colors to 0
{
	this->a.setPoint(0, 0);
	this->b.setPoint(0, 0);
	this->c.setPoint(0, 0);
	this->d.setPoint(0, 0);
	this->color.setColor(0, 0, 0);
}
void Quadrilateral::setPoints(GenPoint a, GenPoint b, GenPoint c, GenPoint d) // setter
{
	this->a.setPoint(a.getX(), a.getY());
	this->b.setPoint(b.getX(), b.getY());
	this->c.setPoint(c.getX(), c.getY());
	this->d.setPoint(d.getX(), d.getY());
	
}
void Quadrilateral::setColor(Color color)
{
	this->color.setColor(color.getRed(), color.getGreen(), color.getBlue());
}
double Quadrilateral::getPerimeter() // getter 
{
	double line1 = sqrt(pow(a.getX() - b.getX(), 2.0) + pow(a.getY() - b.getY(), 2.0));
	double line2 = sqrt(pow(b.getX() - c.getX(), 2.0) + pow(b.getY() - c.getY(), 2.0));
	double line3 = sqrt(pow(c.getX() - d.getX(), 2.0) + pow(c.getY() - d.getY(), 2.0));
	double line4 = sqrt(pow(d.getX() - a.getX(), 2.0) + pow(d.getY() - a.getY(), 2.0));

	//  do other 3

	return (line1 + line2 + line3 + line4);
}
void Quadrilateral::print() // will print the basic details
{
	int x = 0;
	for (int i = 0; i < 640; i++)
	{
		gout << setPos(x, 400) << " - " << endg;
		x += 15;
	}

	gout << setPos(200, 405) << "Shape info Follows for: Quadrilateral" << endg;
	gout << setPos(200, 420) << "Point a: ( " << a.getX() << " , " << a.getY() << " )" << endg;
	gout << setPos(200, 435) << "Point b: ( " << b.getX() << " , " << b.getY() << " )" << endg;
	gout << setPos(200, 450) << "Point c: ( " << c.getX() << " , " << c.getY() << " )" << endg;
	gout << setPos(200, 465) << "Point d: ( " << d.getX() << " , " << d.getY() << " )" << endg;
	gout << setPos(200, 480) << "Perimeter: " << getPerimeter() << endg;

}
void Quadrilateral::draw() // will draw Quadrilateral
{
	int obj1, obj2, obj3, obj4 = 0;

	obj1 = drawLine(a.getX(), a.getY(), b.getX(), b.getY(), 2);
	obj2 = drawLine(b.getX(), b.getY(), c.getX(), c.getY(), 2);
	obj3 = drawLine(c.getX(), c.getY(), d.getX(), d.getY(), 2);
	obj4 = drawLine(d.getX(), d.getY(), a.getX(), a.getY(), 2);

	::setColor(obj1, color.getRed(), color.getGreen(), color.getBlue());
	::setColor(obj2, color.getRed(), color.getGreen(), color.getBlue());
	::setColor(obj3, color.getRed(), color.getGreen(), color.getBlue());
	::setColor(obj4, color.getRed(), color.getGreen(), color.getBlue());
}