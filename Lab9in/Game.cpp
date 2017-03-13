#include<iostream>
#include"Game.h"
#include"graph1.h"
#include<cstring>
#include<fstream>

using namespace std;

Game::Game()
{
	fileName = NULL;
	word = NULL;

}
Game::~Game()
{
	delete[] word;
	delete[] fileName;
}
Game::Game(const Game& game)
{
	this->setFileName(game.fileName);

	this->word = new char[strlen(game.word) + 1];
	strcpy(this->word, game.word);
}
char* Game::getFileName()
{
	char* copy = new char[strlen(fileName) + 1];
	strcpy(copy, fileName);


	return(copy);
}
void Game::setFileName(char* fn) // setter
{
	this->fileName = new char[strlen(fn) + 1];
	strcpy(this->fileName, fn);

}
void Game::setWord(int rand_no) // setter
{
	// declaration
	int word_count = 0;
	char word[100];

	//open file
	fstream in_file(this->fileName, ios::in);

	// test to see if it open correctly 
	// do you own

	/*in_file.open("words1.txt");

	if (in_file.is_open())
	{
		cout << "File successfully open" << endl;
		in_file.close();


	}
	else
	{
		cout << "problem opening file!";


	}*/

	// read one line at a time

	while (true)
	{
		in_file >> word;

		//test for eof

		if (in_file.eof())
			break;

		// see if the word_count matches

		if (word_count == rand_no)
			break;

		// increment word count
		word_count++;

	
	}

	// save off the word
	this->word = new char[strlen(word) + 1];
	strcpy(this->word, word);

}
char* Game::getWord() // getter
{
	char* copy = new char[strlen(word) + 1];
	strcpy(copy, word);


	return(copy);
}
void Game::draw()  // will draw the text on display
{
	char word[255];
	int x = 70;
	int y = 350;

	for (int i = 0; i < strlen(this-> word); i++)
	{

		sprintf(word, "%c.bmp", this->word[i]);
		displayBMP(word, x, y);
		x += 50;

	}
}