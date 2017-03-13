// Asav Bhakta
// Lab40utp1
// This program will implement a postage adressing system

#include <iostream>
#include <cstring>
#include <cctype>
#include "graph1.h"

using namespace std;

//Prototypes are below:
char* getString(char* prompt);
bool validateName(char* name);
bool validateAddress(char* address);
bool validateCity(char* city);
bool validateState(char* state);
bool validateZip(char* zip);
char* convertToUpper(char* string);
void displayLetter(char* fn, char* ln, char* addr, char* city, char* state, char* zip, int weight);

int main()
{
	
		//Variable Declaration/Initialization
		char* fn = NULL;
		char* ln = NULL;
		char* address = NULL;
		char* city = NULL;
		char* state = NULL;
		char* zip = NULL;
		char* firstName = NULL; 
		char* lastName = NULL;
		char* upperState = NULL;
		char repeat = NULL;
		int weight = NULL;
		bool res = false;



		//Display graphics window
		displayGraphics();

	
	
		do{
			//Get the fields - validate based on function
			do
			{
				//Get first name
				fn = getString("Enter First Name: ");

				//validate first name
				res = validateName(fn);

			} while (!res);
			
			
			
			do
			{
				//Get last name
				
				ln = getString("Enter Last Name: ");

				//validate last name
				res = validateName(ln);

			} while (!res);

			do
			{
				//Get the address
				address = getString("Enter Address: ");

				//validate the address
				res = validateAddress(address);

			} while (!res);

			do
			{
				//Get City
				city = getString("Enter City: ");

				//validate the City
				res = validateCity(city);
				city[0] = toupper(city[0]);

			} while (!res);

			do
			{
				//Get State
				state = getString("Enter State: ");

				//validate the State
				res = validateState(state);

			} while (!res);

			do
			{
				//Get Zip
				zip = getString("Enter Zip: ");

				//validate the Zip
				res = validateZip(zip);

			} while (!res);

			do{
				cout << "Enter weight: ";
				cin >> weight;
			} while (weight < 0 || weight > 6);

			cout << endl << endl << endl;

			//Converts required letter to uppercase
			firstName = convertToUpper(fn);
			lastName = convertToUpper(ln);
			upperState = convertToUpper(state);
			

			//Display the mail
			displayLetter(firstName, lastName, address, city, upperState, zip, weight);

			cout << "Run program again (y/n): ";
			cin >> repeat;

			if (repeat == 'y' || repeat == 'Y')
			{
				
				clearGraphics();
				delete[] fn;
				delete[] ln;
				delete[] address;
				delete[] city;
				delete[] zip;
				delete[] state;
				
				
			}
			
		}while (repeat == 'y'|| repeat == 'Y');
    
	return 0;
}

//Function implementation goes here
char* getString(char* prompt)
{
	int i = 0;
	char* string = NULL;
	char buffer[255];

	// prompt the user for data

	cout << prompt;
	cin.getline(buffer, sizeof(buffer));

	// get the num of char the user enter
	for (i = 0; buffer[i] != NULL; i++)
	{
		;
	}

	// dynamiclly allocate to match what the user type in
	string = new char[i + 1];

	// copy the contents of buffer to string 
	for (i = 0; buffer[i] != NULL; i++)
	{
		string[i] = buffer[i];

	}

	string[i] = NULL;
	return string;
	
}

bool validateName(char* name) // will validate the name dont have any special charaters or numbers
{
	int i = 0;

	for (i = 0; name[i] != NULL; i++)
	{
		if (isalpha(name[i]) == 0)
		{
			
				return(false);
			

		}
	}
	return (true);
}
bool validateAddress(char* address) // address validation function
{ 
	int i = 0;

	for (i = 0; address[i] != NULL; i++) 
	{
		if (isalpha(address[i]) == 0)
		{
			if (isspace(address[i]) == 0)
			{
				if (isdigit(address[i]) == 0)
				{
					return(false);
				}
			}

		}
	}
	return (true);
}
bool validateCity(char* city) // city validation function 
{
	int i = 0;

	for (i = 0; city[i] != NULL; i++) 
	{

		if (isalpha(city[i]) == 0)
		{
			return(false);
		}

	}
	
	return (true);


}

bool validateState(char* state) // state validation function 
{
	int i = 0;

	for (i = 0; state[i] != NULL; i++) 
	{

		if (isalpha(state[i]) == 0)
		{
			return(false);
		}

	}

	if (i == 2)
	{
		return (true);
	}

	
		return (false);
	

}

bool validateZip(char* zip) // zip validation function
{
	int i = 0;

	for (i = 0; zip[i] != NULL; i++) 
	{

		if (isdigit(zip[i]) == 0) // will make sure there are only numbers
		{
			return(false);
		}

	}
	
	if (i == 5)
	{
		return (true);
	}

	else
	{
		return (false);
	}
}

char* convertToUpper(char* string) // will convert lower case to upper case
{
	int i = 0;
	char *upper = NULL;
	upper = new char[i + 1];


	for (i = 0; string[i] != NULL; i++) // will make lowe case letters upper case
	{
		upper[i] = toupper(string[i]);
	}

	upper[i] = NULL;

	return upper;
}

void displayLetter(char* fn, char* ln, char* addr, char* city, char* state, char* zip, int weight) // will display result on canvas
{
	float cost = 0.0 ;

	// will display background and mailing address
	displayBMP("envelope.bmp", 0, 0);
	displayBMP("returnAddress.bmp", 43, 26);

	// will display user data
	gout << setPos(315, 210) << fn << " " << ln << endg;
	gout << setPos(315, 225) << addr << endg;
	gout << setPos(315, 240) << city << ", " << state << " " << zip << endg;

	if (weight == 1) // if and else if statmnt for stamp
	{
		displayBMP("stamp.bmp", 525, 20);
	}
	else if (weight == 2)
	{
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 525, 20);
	}
	else if (weight == 3)
	{
		displayBMP("stamp.bmp", 375, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 525, 20);
	}
	else if (weight == 4)
	{
		displayBMP("stamp.bmp", 375, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 525, 99);
	}
	else if (weight == 5)
	{
		displayBMP("stamp.bmp", 375, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 525, 99);
		displayBMP("stamp.bmp", 450, 99);
	}
	else if (weight == 6)
	{
		displayBMP("stamp.bmp", 375, 20);
		displayBMP("stamp.bmp", 450, 20);
		displayBMP("stamp.bmp", 525, 20);
		displayBMP("stamp.bmp", 525, 99);
		displayBMP("stamp.bmp", 450, 99);
		displayBMP("stamp.bmp", 375, 99);
	}

	// will display a box
	drawLine(200, 385, 490, 385, 2);
	drawLine(200, 385, 200, 475, 2);
	drawLine(200, 475, 490, 475, 2);
	drawLine(490, 385, 490, 475, 2);

	cost = weight * .47 ; // will calculate the cost of the mail

	gout << setPos(207, 400) << "Weight: " << weight << " ounces" << endg;
	gout << setPos(207, 420) << "Cost of First Class Stamp: 47 Cents" << endg;
	gout << setPos(207, 440) << "Total Mailing Cost $ " << cost << endg;
}