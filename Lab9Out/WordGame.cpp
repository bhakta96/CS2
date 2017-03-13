#include<iostream>
#include"WordGame.h"
#include"graph1.h"
#include<cstring>
#include<fstream>

using namespace std;

WordGame::WordGame()
{
	fileName = NULL;
	word = NULL;

}
WordGame::~WordGame()
{
	delete[] word;
	delete[] fileName;
}
WordGame::WordGame(const WordGame& wg)
{
	this->setFileName(wg.fileName);

	this->word = new char[strlen(wg.word) + 1];
	strcpy(this->word, wg.word);
}
char* WordGame::getFileName()
{
	char* copy = new char[strlen(fileName) + 1];
	strcpy(copy, fileName);


	return(copy);
}
void WordGame::setFileName(char* fn) // setter
{
	this->fileName = new char[strlen(fn) + 1];
	strcpy(this->fileName, fn);

}
void WordGame::setWord(int rand_no) // setter
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
char* WordGame::getWord() // getter
{
	char* copy = new char[strlen(word) + 1];
	strcpy(copy, word);


	return(copy);
}
void WordGame::draw()  // will draw the text on display
{
	char word[255];
	int x = 100;
	int y = 200;
	int i = 0;
	int *obj = new int[strlen(word) + 1];

	for ( i = 0; i < strlen(this->word); i++)
	{

		//sprintf(word, "%c.bmp", this->word[i]);
		//displayBMP(word, x, y);
		//x += 50;
		obj[i] = drawRect(x , y, 32, 32);
		//setColor(obj[i], 255, 255, 255);
		x += 37;
		

	}
	
	Sleep(2000);
}

int WordGame::play() // play method 
{
	char word[255];
	char guess_word [255];
	int count = 0;
	int x = 100;
	int y = 200;
	int obj = 0;
	int guess = 1;
	int num = strlen(this->word)-1;
	int score= 0;
	int j = 0;
	int i = 0;
	bool check = false;
	bool* letters = new bool[strlen(this->word) + 1];


	// 1st Hint
	sprintf(word, "%c.bmp", this->word[0]);
	letters[0] = false;
	displayBMP(word, x, y);
	x += 37;
	

	for (int i = 1; i < strlen(this->word); i++)
	{

		if (this->word[i] == 'a')
		{
			
			displayBMP("a.bmp", x , y);
			num--;
			letters[i] = false;
			
		}
		else if (this->word[i] == 'e')
		{
			
			displayBMP("e.bmp", x , y);
			num--;
			letters[i] = false;
				
		}
		else if (this->word[i] == 'i')
		{
			
			displayBMP("i.bmp", x , y);
			num--;
			letters[i] = false;
			
		}
		else if (this->word[i] == 'o')
		{
			
			displayBMP("o.bmp", x , y);
			num--;
			letters[i] = false;
			
		}
		else if (this->word[i] == 'u')
		{
			
			displayBMP("u.bmp", x , y);
			num--;
			letters[i] = false;
				
		}

		x += 37;
		
	}
	
	x = 137;
	while(true)  // infinite loop until break
	{
	
		cout << "Guess # " << guess << endl;
		cout << "What is the word? ";
		cin >> guess_word;
		i++;

		gout << setPos(100, 120) << "Guess Number: " << guess << endg;

		if (strcmp(guess_word, this->word)==0)
		{
			for (int i = 0; this->word[i] != NULL; i++)
			{
				if (letters[i] != false)
				{
					score += 10;
				}
			}
			gout << setPos(100, 100) << "!!! Correct!!!" << endg;
			break;

		}

		if (num <= 1)
		{
			gout << setPos(100, 100) << "!!Incorrect!!" << endg;
			break;
		}

		if (count % 2 == 0)
		{
			for (int a = 0; a< strlen(this->word); a++)
			{
				if (letters[a] != false)
				{
					if (this->word[a] == 'a' || this->word[a] == 'e' || this->word[a] == 'i' || this->word[a] == 'o' || this->word[a] == 'u')
					{
						a++;
						
					}
					
					sprintf(word, "%c.bmp", this->word[a]);
					displayBMP(word, 100 + (a * 37), y);
					num--;
					letters[a] = false;
					x += 37;
					
					break;
				}
			}
		}

		else
		{
			for (int i = (strlen(this->word) - 1); i>0; i--)
			{
				if (letters[i] != false)
				{
					if (this->word[i] == 'a' || this->word[i] == 'e' || this->word[i] == 'i' || this->word[i] == 'o' || this->word[i] == 'u')
					{
						i++;
						
					}
					sprintf(word, "%c.bmp", this->word[i]);
					displayBMP(word, 100+(i*37), y);
					num--;
					//x += 37;
					letters[i] = false;
					
					break;
				}
			}
		}
		count++;
		guess++;
		
		//j++;
		
		
		
	}

	return score; // will return score 
}