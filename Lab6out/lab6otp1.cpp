// Asav Bhakta
//Lab6OutP1
// this program will simulate lottery game

#include <iostream>
#include <ctime>
#include "Lottery.h"
#include"graph1.h"

using namespace std;

int main()
{
	
	displayGraphics();
	Lottery play;
	// Varaiable intialization/ decleration
	int numbers = 0;
	int balls[10];
	bool res1 = 0;
	bool res2 = 0;
	int num = 0;
	float winnings = 0.0;
	int matches = 0;
	char repeat = NULL;
	
	do{
		cout << "How many Lottery balls do you want to play: ";
		cin >> numbers;

		res1 = play.setNoBalls(numbers);

		if (!res1) // if and else if statment for invalid input
		{
			cout << "Invalid Input! Number have set to the Lowest or Highest value depending on the value you entered";
			cout << endl;
			if (numbers < 3)
			{
				numbers = 3;
				res1 = play.setNoBalls(numbers);
			}
			else if (numbers > 10)
			{
				numbers = 10;
				res1 = play.setNoBalls(numbers);
			}
		}

		for (int i = 0; i < numbers; i++) // for loop to ask for repeating question
		{
			cout << "Enter Lottery #" << i + 1 << " (between 1 and 40): ";
			cin >> num;

			balls[i] = num;
			res2 = play.addNumber(balls[i]);

			do
			{
				if (!res2) // will check if the value is repeated or is outside of range 
				{
					cout << "Invalid Input! Please reenter: ";
					cin >> balls[i];
					res2 = play.addNumber(balls[i]);
				}
			} while (!res2);
		}

		// calling necessacery classes
		play.selectionSort();
		play.displayYourNumbers();
		play.processWinningNumbers();

		winnings = play.computeWinnings(); // return value will be stored in winnings variable

		if (winnings < 10)
		{
			winnings = 0;
		}

		matches = play.getMatches(); // will count the matches using log 

		

		gout << setPos(150, 50) << "Number of Ball Played: " << numbers << endg;
		gout << setPos(150, 75) << "Number of Matches: " << matches << endg;
		gout << setPos(150, 100) << "Your Payout: " << winnings << endg;

		cout << "Play Again (y/n)? ";
		cin >> repeat;

		if (repeat == 'y' || repeat == 'Y')
		{
			clearGraphics();
			play.~Lottery();
		}
	} while (repeat == 'y' || repeat == 'Y');
}