#ifndef PAGE_H
#define PAGE_H
#pragma warning (disable:4996)
#include"Line.h"

class Page
{
private:
	Line* lines;
public:
	Page();
	Line getLineAt(int index);
	void setLineAt(int index, Line line);
	Page(const Page &obj); // copy constructor
	~Page(); // destructor
};

#endif