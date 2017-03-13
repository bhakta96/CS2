// Asav Bhakta
// Lab4inP1
// Will display user phone, address and name on canvas

#include <iostream>
#include <cstring>
#include <cctype>
#include "graph1.h"

using namespace std;

//Prototypes are below:
char* getString(char* prompt);
bool validateName(char* name);
bool validateAddress(char* address);
bool validatePhone(char* phone);
char* convertToUpper(char* string);
void displayFields(char* name, char* address, char* phone);

int main()
{
	//Variable Declaration/Initialization
	char* name = NULL;
	char* address = NULL;
	char* phone = NULL;
	char* upperName = NULL;
	bool res = false;



	//Display graphics window
	displayGraphics();

	//Get the fields - validate based on function
	do
	{
		//Get the name
		name = getString("Enter Name: ");

		//validate the name
		res = validateName(name);

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
		//Get the phone
		phone = getString("Enter Phone: ");
		
		//validate the phone
		res = validatePhone(phone);

	} while (!res);

	cout << endl << endl << endl;

	//Convert the name to all uppercase
	upperName = convertToUpper(name);

	//Display the fields
	displayFields(upperName, address, phone);

	// cleanUP name, addreass, phone , Upper name

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
			if (isspace(name[i]) == 0)
			{
				return(false);
			}

		}
	}
	return (true);
}
bool validateAddress(char* address)
{
	int i = 0;

	for (i = 0; address[i] != NULL; i++) // will make sure no special charaters are entered
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
bool validatePhone(char* phone) 
{
	int i = 0;
	
	for (i = 0; phone[i] != NULL; i++) // will make sure there are only numbers
	{

		if (isdigit(phone[i]) == 0)
		{
			return(false);
		}
		
	}
	
	if (i == 10)
	{
		return (true);
	}

	else
	{
		return (false);
	
	}

	
}

char* convertToUpper(char* string)
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
void displayFields(char* name, char* address, char* phone)
{
	int object1, object2, object3 = 0; 

	// will display the name, address, and phone  
	gout << setPos(150, 100) << "Name:" << endg;
	gout << setPos(150, 140) << "Address:" << endg;
	gout << setPos(150, 180) << "Phone:" << endg;

	// will draw rectangle 
	object1 = drawRect(230, 85, 125, 25); 
	object2 = drawRect(230, 125, 150, 25);
	object3 = drawRect(230, 165, 125, 25);

	// will set color gray to rectangle 
	setColor(object1, 128, 128, 128);
	setColor(object2, 128, 128, 128);
	setColor(object3, 128, 128, 128);

	// will display the user information 
	gout << setPos(230, 100) << name << endg;
	gout << setPos(230, 140) << address << endg;
	gout << setPos(230, 180) << phone << endg;
}