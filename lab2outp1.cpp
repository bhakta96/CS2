// Asav Bhakta	
// Assignment # Lab2outP1
// This Program is a short card game

#include<iostream>
#include<ctime>
#include"graph1.h"

using namespace std;

// Function Prototypes
void getWager(int* wager);
void deal(int* pc1_no, int* pc2_no, int* deal1_no, int* deal2_no);
int computeScore(int card1_no, int card2_no);
int computeScoreofDealer(int dealercard1_no, int dealercard1_no);
void displayResults(int pc1_no, int pc2_no, int deal1_no, int deal2_no, int player_score, int dealer_score);

int main()
{
	displayGraphics(); // will display canvas

	// variable decleratrion 
	int wager = 0;
	int pc1_no, pc2_no, deal1_no, deal2_no = 0;
	int player_score, dealer_score = 0;

	// calling function
	getWager(&wager);
	
	deal(&pc1_no, &pc2_no, &deal1_no, &deal2_no);

	player_score= computeScore( pc1_no, pc2_no );
	dealer_score = computeScoreofDealer(deal1_no, deal2_no);

	displayResults(pc1_no, pc2_no, deal1_no, deal2_no, player_score, dealer_score);

}

void getWager(int* wager) // this function will ask user to input amount 
{
	cout << "Enter your wager: ($5 minimum): ";
	cin >> *wager;

	while (*wager < 5)
	{
		cout << "Enter your wager: ($5 minimum): ";
		cin >> *wager;
	}
}

void deal(int* pc1_no, int* pc2_no, int* deal1_no, int* deal2_no) // this function will generate random # between 1 to 13
{
	srand(time(0));

	*pc1_no = rand() % 13+1;
	
	*pc2_no = rand() % 13 + 1;

	*deal1_no = rand() % 13 + 1;

	*deal2_no = rand() % 13 + 1;
}

int computeScore(int card1_no, int card2_no) // this function will compute score of player
{
	// variable declaration
	int card_1_points, card_2_points, total_points = 0;

	// player card1 point calculation 
	card_1_points = card1_no;

	if (card_1_points == 1)
	{
		card_1_points = 11;
	}
	else if (card_1_points == 11)
	{
		card_1_points = 10;
	}
	else if (card_1_points == 12)
	{
		card_1_points = 10;
	}
	else if (card_1_points == 13)
	{
		card_1_points = 10;
	}

	// player card2 point calculation 
	
	card_2_points = card2_no;
	
	if (card_2_points == 1)
	{
		card_2_points = 11;
	}
	else if (card_2_points == 11)
	{
		card_2_points = 10;
	}
	else if (card_2_points == 12)
	{
		card_2_points = 10;
	}
	else if (card_2_points == 13)
	{
		card_2_points = 10;
	}

	total_points = card_1_points + card_2_points;

	return total_points;
	
}

int computeScoreofDealer(int dealercard1_no, int dealercard2_no) // this function will compute score of dealer 
{
	// variable declaration
	int card_1_points, card_2_points, total_points = 0;

	// dealer card1 point calculation 
	card_1_points = dealercard1_no;
	if (card_1_points == 1)
	{
		card_1_points = 11;
	}
	else if (card_1_points == 11)
	{
		card_1_points = 10;
	}
	else if (card_1_points == 12)
	{
		card_1_points = 10;
	}
	else if (card_1_points == 13)
	{
		card_1_points = 10;
	} 

	// dealer card2 point calculation 

	card_2_points = dealercard1_no;

	if (card_2_points == 1)
	{
		card_2_points = 11;
	}
	else if (card_2_points == 11)
	{
		card_2_points = 10;
	}
	else if (card_2_points == 12)
	{
		card_2_points = 10;
	}
	else if (card_2_points == 13)
	{
		card_2_points = 10;
	}

	total_points = card_1_points + card_2_points;

	return total_points;
}

void displayResults(int pc1_no, int pc2_no, int deal1_no, int deal2_no, int player_score, int dealer_score) // this function will display cards and result
{

	gout << setPos(75, 90) << "Your Cards" << endg;
	gout << setPos(400, 90) << "Dealer Cards" << endg;

	displayBMP("back.bmp", 75, 100);
	displayBMP("back.bmp", 400, 100);

	if (pc1_no == 1) // displays players card 1
	{
		displayBMP("h14.bmp", 150, 100);
	}
	else if (pc1_no == 2)
	{
		displayBMP("h2.bmp", 150, 100);
	}
	else if (pc1_no == 3)
	{
		displayBMP("h3.bmp", 150, 100);
	}
	else if (pc1_no == 4)
	{
		displayBMP("h4.bmp", 150, 100);
	}
	else if (pc1_no == 5)
	{
		displayBMP("h5.bmp", 150, 100);
	}
	else if (pc1_no == 6)
	{
		displayBMP("h6.bmp", 150, 100);
	}
	else if (pc1_no == 7)
	{
		displayBMP("h7.bmp", 150, 100);
	}
	else if (pc1_no == 8)
	{
		displayBMP("h8.bmp", 150, 100);
	}
	else if (pc1_no == 9)
	{
		displayBMP("h9.bmp", 150, 100);
	}
	else if (pc1_no == 10)
	{
		displayBMP("h10.bmp", 150, 100);
	}
	else if (pc1_no == 11)
	{
		displayBMP("h11.bmp", 150, 100);
	}
	else if (pc1_no == 12)
	{
		displayBMP("h12.bmp", 150, 100);
	}
	else if (pc1_no == 13)
	{
		displayBMP("h13.bmp", 150, 100);
	}

	// display players card 2

	if (pc2_no == 1)
	{
		displayBMP("d14.bmp", 225, 100);
	}
	else if (pc2_no == 2)
	{
		displayBMP("d2.bmp", 225, 100);
	}
	else if (pc2_no == 3)
	{
		displayBMP("d3.bmp", 225, 100);
	}
	else if (pc2_no == 4)
	{
		displayBMP("d4.bmp", 225, 100);
	}
	else if (pc2_no == 5)
	{
		displayBMP("d5.bmp", 225, 100);
	}
	else if (pc2_no == 6)
	{
		displayBMP("d6.bmp", 225, 100);
	}
	else if (pc2_no == 7)
	{
		displayBMP("d7.bmp", 225, 100);
	}
	else if (pc2_no == 8)
	{
		displayBMP("d8.bmp", 225, 100);
	}
	else if (pc2_no == 9)
	{
		displayBMP("d9.bmp", 225, 100);
	}
	else if (pc2_no == 10)
	{
		displayBMP("d10.bmp", 225, 100);
	}
	else if (pc2_no == 11)
	{
		displayBMP("d11.bmp", 225, 100);
	}
	else if (pc2_no == 12)
	{
		displayBMP("d12.bmp", 225, 100);
	}
	else if (pc2_no == 13)
	{
		displayBMP("d13.bmp", 225, 100);
	}

	// displays dealers card 1

	if (deal1_no == 1)
	{
		displayBMP("c14.bmp", 475, 100);
	}
	else if (deal1_no == 2)
	{
		displayBMP("c2.bmp", 475, 100);
	}
	else if (deal1_no == 3)
	{
		displayBMP("c3.bmp", 475, 100);
	}
	else if (deal1_no == 4)
	{
		displayBMP("c4.bmp", 475, 100);
	}
	else if (deal1_no == 5)
	{
		displayBMP("c5.bmp", 475, 100);
	}
	else if (deal1_no == 6)
	{
		displayBMP("c6.bmp", 475, 100);
	}

	else if (deal1_no == 7)
	{
		displayBMP("c7.bmp", 475, 100);
	}
	else if (deal1_no == 8)
	{
		displayBMP("c8.bmp", 475, 100);
	}
	else if (deal1_no == 9)
	{
		displayBMP("c9.bmp", 475, 100);
	}
	else if (deal1_no == 10)
	{
		displayBMP("c10.bmp", 475, 100);
	}
	else if (deal1_no == 11)
	{
		displayBMP("c11.bmp", 475, 100);
	}
	else if (deal1_no == 12)
	{
		displayBMP("c12.bmp", 475, 100);
	}
	else if (deal1_no == 13)
	{
		displayBMP("c13.bmp", 475, 100);
	}

	// displays dealers card 2

	if (deal2_no == 1)
	{
		displayBMP("s14.bmp", 550, 100);
	}
	else if (deal2_no == 2)
	{
		displayBMP("s2.bmp", 550, 100);
	}
	else if (deal2_no == 3)
	{
		displayBMP("s3.bmp", 550, 100);
	}
	else if (deal2_no == 4)
	{
		displayBMP("s4.bmp", 550, 100);
	}
	else if (deal2_no == 5)
	{
		displayBMP("s5.bmp", 550, 100);
	}
	else if (deal2_no == 6)
	{
		displayBMP("c6.bmp", 550, 100);
	}

	else if (deal2_no == 7)
	{
		displayBMP("s7.bmp", 550, 100);
	}
	else if (deal2_no == 8)
	{
		displayBMP("s8.bmp", 550, 100);
	}
	else if (deal2_no == 9)
	{
		displayBMP("s9.bmp", 550, 100);
	}
	else if (deal2_no == 10)
	{
		displayBMP("s10.bmp", 550, 100);
	}
	else if (deal2_no == 11)
	{
		displayBMP("s11.bmp", 550, 100);
	}
	else if (deal2_no == 12)
	{
		displayBMP("s12.bmp", 550, 100);
	}
	else if (deal2_no == 13)
	{
		displayBMP("s13.bmp", 550, 100);
	}

	// dispaly total points of player

	gout << setPos(75, 215) << "Your Total: " << player_score << endg;
	
	// dispaly total points of dealer

	gout << setPos(400, 215) << "Dealer Total: " << dealer_score << endg;

	if (player_score > dealer_score)
	{
		gout << setPos(290, 300) << "You Win!" << endg;
	}
	else if (player_score < dealer_score)
	{
		gout << setPos(290, 300) << "You Loose!" << endg;
	}
	else if (player_score >= dealer_score)
	{
		gout << setPos(290, 300) << "Tie!" << endg;
	}
}
