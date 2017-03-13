#include <iostream>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

using namespace std;



int main ( void )
{
	int value = 278;
	char* string1;
	char* string2;
	char string3[255] = "7-11 E-Z Mart";
	char string4[255] = "923";
	char* new_string1;
	char* new_string2;
	char* new_string3;
	char* new_string4;
	int i;


	//Q1
	string1 = new char[strlen("Hello World") + 1];
	strcpy(string1,"Hello World");
	
	
	//Q2
	string2 = new char[strlen("Now") + 1];
	strcpy(string2,"Now");
	
	
	//Q3
	if(strcmp(string1,string2) == 0)
	{
	  cout << "They are equal";
	}
	
	//Q4
	new_string1 = new char[strlen(string1) + strlen(string2) + 1];
	strcat(new_string1,"Hello World Now",string1,string2);

	//Q5
	int word_start;
	int word_end;
	for(i = 0; i < strlen(string1); i++)
	{
    //Locate first space in string1
	  if(isspace(string1[i]))
	    break;
	}
	word_start = ++i;
	
	new_string2 = new char[strlen(string1) + 1];
	
	strcpy(new_string2, string1);

	
	
	//Q6
	new_string3 = new char[3];
	
	strncpy(new_string3,string2,2);
	new_string3[2] = NULL;
	
	//Q7
	new_string4 = new char[strlen(string1) + strlen(string2) + strlen(string3)+4];
  strcat(new_string4,"%s,%s,%s",string1,string2,string3);
	cout << new_string4 << endl;
	
	//Q8
	for(i = 0; i < strlen(string3); i++)
	{
    //Locate digit
	  if(isdigit(string3[i]))
	  {
	    cout << "Numbers found" << endl;
	    break;
	  }
    ;
	}
	
	//Q9
	for(i = 0; i < strlen(string3); i++)
	{
	  string3[i] = islower(string3[i]);
   
	}  
	cout << string3 << endl;
	
	//Q10
	for(i = 0; i < strlen(string2); i++)
	{
	  string2[i] = isupper(string2[i]);
	}
	cout << string2 << endl;
	
	//Q11
	for(i = 0; i < strlen(string3); i++)
	{
    //Locate 1st alpha
	  if(isalpha(string3[i]))
	  {
	    cout << string3[i] << " is first alpha character in string." << endl;
	    break;
	  }
	}
	
	//Q12
	for(i = 0; i < strlen(string1); i++)
	{
    //Locate 1st lowercase letter
	  if(islower(string1[i]))
	  {
	    cout << string1[i] << " is first lowercase alpha character in string." << endl;
	    break;
	  }
	}
	
	
	
	//Q13
	value = atoi(string4);
	cout << value << endl;
	
	return 0;
}