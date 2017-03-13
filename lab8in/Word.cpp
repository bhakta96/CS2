#include <iostream>
#include "graph1.h"
#include "Word.h"
#include <cstring>

Word::Word()
{
	word = NULL;
}
Word::~Word()
{
	delete[] word;
}
Word::Word(const Word& word)
{
	this->word = new char[strlen(word.word) + 1];
	strcpy(this->word, word.word);
}
void Word:: setWord(char* word)
{
	
	

	this->word = new char[strlen(word) + 1];
	strcpy(this ->word, word);

	

	//for (int i = 0; i < strlen(word); i++)
	//{
	//	sprintf(this->word, "%c.bmp", word[i]);
		//displayBMP(this -> word, x, y);
		//x += 35;
	//}
	
}
char* Word::getWord()
{
	char* copy = new char[strlen(word) + 1];
	strcpy(copy, word);

	return copy;
}
void Word::draw()
{
	int x = 100;
	int y = 100;
	int i ;
	char buffer[255];

	for ( i = 0 ; i < strlen(word) ; i++)
	{
		x += 35;
		sprintf( buffer, "%c.bmp", word[i]);
		displayBMP(buffer, x, y);
		
	}

	//for ( i = 0; i < strlen(word); i++);
	//{
		//sprintf(buffer,  "%c.bmp", word[i]);
		//displayBMP(buffer , x, y);
		//x += 35;
		

	
	//}
	
	
}