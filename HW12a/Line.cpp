#include<iostream>
#include"Line.h"

Line::Line()
{
	letters = new char[255];
}
char* Line::getLine()
{
	return letters;
}
char Line::getCharAt(int index)
{
	//char obj = NULL;

	return letters[index];
}
void Line::setLine(char *line)
{
	strcpy(letters, line);
}
Line::Line(const Line &obj)// copy constructor
{
	this->letters= new char[255];
	this->setLine(obj.letters);
}
Line::~Line()// destructor
{
	delete[] letters;
}