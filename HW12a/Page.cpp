#include<iostream>
#include "Page.h"

Page :: Page()
{
	lines = new Line[64];

}
Line Page::getLineAt(int index)
{
	return lines[index];
}
void Page::setLineAt(int index, Line line)
{
	char* temp_array [64];
	for (int i = 0; i < 64; i++)
	{
		//this->lines[i].setLine(line.getCharAt);
		temp_array[i] = line.getLine();
		lines[index].setLine(temp_array[i]);
	}
	//lines[index].setLine(temp_array);
	
}
Page::Page(const Page &obj)// copy constructor
{
	this->lines = new Line[64];
	/*for (int i = 0; i < 64; i++)
	{
		lines[i].setLine(obj.getLineAt);
	}*/
	//for (int i = 0; i < 64; i++)
//		this->setLineAt(i, obj.getLineAt);

}
Page ::~Page()// destructor
{
	delete[] lines;
}