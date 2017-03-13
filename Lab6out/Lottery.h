#ifndef LOTTERY_H
#define LOTTERY_H
#pragma warning(disable : 4996)
class Lottery
{
private:
	int no_balls;
	int* yourNumbers;
	int* winningNumbers;
	int matches;
	int v = 0;

public:
	Lottery();
	~Lottery();
	int getNoBalls();
	bool setNoBalls(int no_balls);
	bool addNumber(int num);
	void displayYourNumbers();
	void processWinningNumbers();
	void selectionSort();
	void insertionSort();
	int getMatches();
	int binarySearch(int target);
	int computeWinnings();
};

#endif