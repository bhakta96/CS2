#include<iostream>
#include"Page.h"
#include"Book.h"

Book::Book()
{
	pages = new Page[1000];
}
Page Book::getPageAt(int index)
{
	return pages[index];
}
void Book::setPageAt(int index, Page p)
{
	/*Line temp_lines[64];
	for (int i = 0; i < 1000; i++)
	{
		temp_lines[i] = p.getLineAt[i];
	}*/
	pages[index] = p;
	
}
Book::Book(const Book &obj)// copy constructor
{
	this->pages = new Page[1000];
}
Book::~Book()// destructor
{
	delete[] pages;

}