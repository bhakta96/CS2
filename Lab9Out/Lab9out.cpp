// Asav Bhakta
// Lab9OutP1
// this program will process text information stored in a file 
#include <iostream>
#include <ctime>
#include <cstring>
#include <fstream>
#include "graph1.h"
#include "WordGame.h"

using namespace std;

int main()
{
	//Variable Declaration/Initialization
	int rand_no = 0;
	char fn[255];
	char repeat = 'y';
	int score, prev_score = 0;
	WordGame game;

	//Display graphics
	displayGraphics();

	//Initialize random # generator
	srand(time(0));

	//Run program as many times as desired
	do
	{

		//Generate random #
		rand_no = rand() % 1149;

		//Prompt for fn
		cout << "Enter filename that contains words: ";
		cin >> fn;

		//Set the filename
		game.setFileName(fn);

		//Set the word
		game.setWord(rand_no);

		//Draw the scene
		game.draw();

		//Get the word
		score = game.play();
		gout << setPos(100, 120) << "Score: " << score << endg;
		prev_score = prev_score + score;

		gout << setPos(100, 80) << "Total Score: " << prev_score << endg;

		//Display the actual word
		

		cout << "Repeat? (y/n): ";
		cin >> repeat;

		//Clear screen
		system("cls");
		clearGraphics();

		//Cleanup memory
		

	} while ((repeat == 'y') || (repeat == 'Y'));





	return 0;
}

