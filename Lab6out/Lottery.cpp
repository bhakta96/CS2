#include <iostream>
#include "Lottery.h"
#include"graph1.h"
#include <ctime>

using namespace std;

Lottery::Lottery()
{
	// all private variable set to null/0
	no_balls = 0;
	yourNumbers = NULL;
	winningNumbers = NULL;
	matches = 0;
	
}
Lottery::~Lottery()
{
	delete[] yourNumbers;
	delete[] winningNumbers;
}
int Lottery::getNoBalls()
{
	return no_balls;
}
bool Lottery::setNoBalls(int no_balls)
{
	this->no_balls = no_balls;
	// if statement to make sure no invalid input is been added

	if (no_balls < 3)
	{
		no_balls = 3;
		yourNumbers = new int[no_balls];
		return false;
	}

	if (no_balls > 10)
	{
		no_balls = 10;
		yourNumbers = new int[no_balls];
		return false;
	}

	yourNumbers = new int[no_balls]; // dynamically allcoted yourNumber
	
	return true;

}
bool Lottery::addNumber(int num)
{
	
	do
	{
		yourNumbers[v] = num; 

		for (int i = 0; i < v; i++) // loop to make sure user dont enter same units
		{
			if (yourNumbers[i] == num)
			{
				return false;
			}
		}


		if (yourNumbers[v] < 1) // if statment to make sure input is in range
		{
			return false;
		}
		if (yourNumbers[v] > 40)
		{
			return false;
		}



		
		v++;
	} while (v < 0);


	return true; // if above condition is ture it will return true 

	
}
void Lottery::displayYourNumbers()
{
	// variable intialization/decelaration
	char balls_0[255]; 
	int x = 70;
	int y = 350;

	for (int a = 0; a < no_balls; a++) // loop to disply bmp images 
	{
		sprintf(balls_0,  "%d.bmp", yourNumbers[a]);
		displayBMP(balls_0, x, y);
		x += 50;
		
	}
	
	gout << setPos(75, 400) << "Your Numbers" << endg; 
}
void Lottery::processWinningNumbers()
{
	srand(time(0));

	winningNumbers = new int[no_balls]; // dynamically allocated winningNumbers

	// variable intialization/decelaration
	bool duplicate = false;
	char balls_1[255];
	char balls[255];
	int x = 70;
	int y = 250;
	int x1 = 70;
	int y1 = 250;
	
	for (int i = 0; i < no_balls; i++) // loop to create random unique winning #
	{
		do{
			duplicate = false;
			winningNumbers[i] = rand() % 40 + 1;

			for (int j = 0; j < i; j++)
			{
				if (winningNumbers[i] == winningNumbers[j])
				{
					winningNumbers[i] = rand() % 40 + 1;
					duplicate = true;
				}
			}

		} while (duplicate);
	}

	for (int a = 0; a < no_balls; a++) // will display random winning numbers
	{
		sprintf_s(balls_1, "%d.bmp", winningNumbers[a]);
		displayBMP(balls_1, x, y);

		x += 50;
		Sleep(1000);
	}

	Sleep(3000); // 3 seconds pause before next thing is displayed

	insertionSort(); // will call this class to short out the winning #
	
	
	
	for (int a = 0; a < no_balls; a++) // will display shorted bmp images
	{
	sprintf(balls, "%d.bmp", winningNumbers[a]);
	displayBMP(balls, x1, y1);

	x1+= 50;
	Sleep(1000);
	}
	
	gout << setPos(75, 300) << "Winning Numbers" << endg;

}
void Lottery::selectionSort()
{
	// variable intialization/decelaration
	int i = 0;
	int j= 0;
	int sm_index = 0;
	int smallest = 0;
	int temp1 = 0;
	int temp2 = 0;
	

	for (i = 0; i < no_balls - 1; i++)	       // size-1 = number of passes
	{
		smallest = yourNumbers[i];
		sm_index = i;

		for (j = i + 1; j < no_balls; j++)    // size = # elem. to look at
		{
			if (yourNumbers[j] < smallest)
			{
				smallest = yourNumbers[j];
				sm_index = j;
			}
		}

		if (smallest < yourNumbers[i])
		{
			temp1 = yourNumbers[i];
			yourNumbers[i] = yourNumbers[sm_index];
			yourNumbers[sm_index] = temp1;
		}
	}

	
}
void Lottery::insertionSort()
{
	// variable intialization/decelaration
	int x = 70;
	int y = 250;
	int i = 0;
	int j = 0;
	int v = 0;
	char balls[255];

	// For each element after the first:
	for (i = 1; i < no_balls; i++)
	{
		// Look back through the previous (sorted) elts.
		// Insert this elt after first that is smaller,
		// moving the others up as you go by them.
		v = winningNumbers[i];

		for (j = i - 1; j >= 0 && winningNumbers[j] > v; j--)
		{
			// a[j] is bigger; move it up
			winningNumbers[j + 1] = winningNumbers[j];
		}

		// a[j] <= v; put v after a[j]
		winningNumbers[j + 1] = v;
	}
	
}
int Lottery::getMatches()
{
	return matches;
}
int Lottery::binarySearch(int target)
{
	// variable intialization/decelaration
	int low = 0;
	int high = 0;
	int middle = 0;
	bool found = false;
	int index = -1;

	//Initialize low/high
	low = 0;
	high = no_balls - 1;

	while ((low <= high) && (!found)) // loop to match similar numbers
	{
		middle = (low + high) / 2;

		if (yourNumbers[middle] == target)
			found = true;

		else if (target > yourNumbers[middle])
			low = middle + 1;

		else
			high = middle - 1;
	}

	if (!found) // if !true index = -1
	{
		index = -1;
	}
	else 
	{
		index = middle;
	}
	return(index);

}
int Lottery::computeWinnings()
{
	// variable intialization and declaration 
	int check [10];
	float winnings = 0.0;
	
	for (int i = 0; i < no_balls; i++) // collect return values in array called check
	{
		check[i] = binarySearch(winningNumbers[i]);
	}

	for (int j = 0; j < no_balls; j++) // if check is -1 then there is no match 
	{
		if (check[j] == -1)
		{
		}
		else // else there is match
		{
			matches++;
		}
			
	}

	winnings = pow(10.00, matches); // formulae to calculate the winnings based on matches

	return  winnings;
	
}
