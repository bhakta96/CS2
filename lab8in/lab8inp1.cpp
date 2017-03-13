// Asav Bhakta
// Lab8inp1
// this program will display letters bmp after user input a word
#include <iostream>
#include "graph1.h"
#include "Word.h"
#include <cstring>

using namespace std;

void reverseWord(Word word);

int main()
{
	// variable decelaration

	char word1[255];
	Word word;
	char repeat = 0;

	// display graphics
	displayGraphics();

	// prompt for the word
	cout << "Enter any Word: ";
	cin >> word1;


	// set the Word;

	word.setWord(word1);
	// Draw the word in the graphics window 

	word.draw();

	// Reverse the word
	reverseWord(word);

	// repeat

}
void reverseWord(Word word)
{
	int x = 0;
	char* word_1 = word.getWord();
	char word_2[255];

	for (int i = strlen(word_1) - 1; i > 0; i--)
	{
		word_2[x] = word_1[i];
		x++;
	
	}

	word.setWord(word_2);
	word.draw();
}