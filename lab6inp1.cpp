// Asav Bhakta
// Lab6inp1
// Simple program that let user play a card game

#include <iostream>
#include <ctime>
#include "CardPlayer.h"
#include"graph1.h"

using namespace std;

void shuffle(int* deck, int no_cards);

int main()
{
	//Variable Declaration/Initialization
	int i = 0;
	int x = 0;
	int y = 0;
	int player1_score = 0;
	int player2_score = 0;
	const int TOTAL_CARDS = 13;
	int no_cards = 0;
	int* deck = new int[TOTAL_CARDS];

	//Declare both players with a capacity of 6
	CardPlayer cp1(6);
	CardPlayer cp2(6);
	
	//Prompt for the number of cards per hand
	cout << "Enter # of cards to deal to each player: ";
	cin >> no_cards;

	cout << "Enter x/y coordinate to display Player 1 cards: ";
	cin >> x >> y;

	//Display Grpaphics
	displayGraphics();


	//Shuffle the deck
	shuffle(deck, TOTAL_CARDS);

	//Deal the cards to the players

	for (i = 0; i < (no_cards * 2); i++)
	{
		if (i % 2 == 0)
			cp1.addCard(deck[i]);
		else
			cp2.addCard(deck[i]);
	}


	//Even to player 1 – odd to player 2

	//Display the Hands for both players
	cp1.displayHand(x, y);
	cp2.displayHand(x + 100, y);

	
	//Display the scores for both players

	gout << setPos(x, y-20) << "Player 1" << endg;
	gout << setPos(x+ 100, y-20) << "Player 2" << endg;

	gout << setPos(x, y+100+(20*no_cards) )<< "Score: " << cp1.computeScore() << endg; // player 1 score
	gout << setPos(x+100 , y + 100 + (20 * no_cards)) << "Score: " << cp2.computeScore() << endg; // player 2 score
	return 0;

}

void shuffle(int* deck, int no_cards)
{
	int i = 0;
	int j = 0;
	bool duplicate = false;


	//Set the seed
	srand(time(0));

	//Generate no_colors random numbers
	for (i = 0; i < no_cards; i++)
	{
		deck[i] = (rand() % 13) + 2;

		//Check all previous values
		do
		{
			//Set duplicate to false
			duplicate = false;

			//Check prvious values
			for (j = 0; j < i; j++)
			{
				if (deck[i] == deck[j])
				{
					deck[i] = (rand() % 13) + 2;
					duplicate = true;
				}
			}
		} while (duplicate);
	}
}

