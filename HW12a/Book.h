#ifndef BOOK_H
#define BOOK_H
#pragma warning (disable:4996)
#include"Page.h"

class Book
{
private:
	Page* pages;
public:
	Book();
	Page getPageAt(int index);
	void setPageAt(int index, Page p);
	Book(const Book &obj); // copy constructor
	~Book(); // destructor
};

#endif
