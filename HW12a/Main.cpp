// Asav Bhakta
// HW 12a
// we make a book and access it
#include<iostream>
#include"Line.h"
#include"Page.h"
#include"Book.h"

using namespace std;

int main()
{
	Line line;
	Page page;
	Book book;

	line.setLine("The brown fox ran thru the hollow log");
	
	for (int i = 0; i < 64; i++) // assigne all 64 line to the sentence above 
	{
		page.setLineAt(i, line);
	}

	for (int i = 0; i < 200; i++) // assign all pages to the sentence above
	{
		book.setPageAt(i, page);
	}

	 
	
}