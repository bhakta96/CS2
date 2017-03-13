// Asav Bhakta
// Assignment # Lab1outP1
// This Program will dispaly Bar Graph of sales data

#include<iostream>
#include "graph1.h"

using namespace std;

// Function Prototype 
int getNoMonths();
void getSales(int sales[], int no_months);
int getMax(int sales[], int no_months);
int getMin(int sales[], int no_months);
double getAverage(int sales[], int no_months);
void displayResults(int sales[], int no_months, int max, int min, double avg);


int main()
{
	displayGraphics(); // This Will display blank canvas

	// Created required variable 
	int no_months = 0;
	const int months = 10;
	int sales[months];
	int max_sales = 0;
	int min_sales = 0;
	int average = 0;

	// Calling function 
	no_months = getNoMonths();
	getSales(sales, no_months);
	max_sales= getMax(sales, no_months);
	min_sales=  getMin( sales,  no_months);
	average = getAverage( sales, no_months);
	displayResults( sales, no_months, max_sales, min_sales, average);

}

int getNoMonths() // this function will take number of months of sales data from user
{
	int months_of_sales = 0;
	
	while (months_of_sales < 3 || months_of_sales > 6) // this loop will make sure user input right amount of months
	{
		cout << "Enter number of months to process: (between 3 and 6 inclusive) : ";
		cin >> months_of_sales;
	}

	return months_of_sales; // it will return input value of user
}

void getSales(int sales[], int no_months) // This function will get sales value from user
{
	for (int x = 0; x < no_months; x++) // crated loop for getting sales data and it will be stored in "sales" array
	{
		cout << "Enter sales for month # " << x + 1 << " : ";
		cin >> sales[x];

	}
}

int getMax(int sales[], int no_months) // This function will return Max sales value 
{
	int data = 0; // data represent max value 

	for (int x = 0; x < no_months; x++) // created loop to figure out the Max value 
	{
		if (sales[x] > data) 
			data = sales[x];
	
	}
	 
	return data; // this will return max value 
}

int getMin(int sales[], int no_months) // This function will return least sales value
{
	int min = 0;

	min = sales[0]; // Assign the first sales value to Minimum
	
	for (int x = 0; x < no_months; x++) 
	{
		if (sales[x] < min) // This statement help find the least sales data
			min = sales[x];

	}

	return min;
}

double getAverage(int sales[], int no_months) // this function will return average 
{
	int sum = 0; // created required variables
	int avg = 0;

	for (int x = 0; x < no_months; x++) // created loop to add each sales data 
	{
		sum = sum + sales[x];
		
	}
	
	avg = sum / no_months; // average finding formula
	
	return avg; // will return average 
}

void displayResults(int sales[], int no_months, int max, int min, double avg) // this function will display everthing on canvas
{
	// created required array
	double height[6];
	int x_axis = 0;
	int object[6];

	 displayBMP("sales1.bmp",250,25); // it will display sales bmp image 
	
	 gout << setPos(375, 26) << "Sales for " << no_months << " months" << endg; // this will give heading 
	
	 // this will create x-axis and y-axis 
	 drawLine(200, 280, 648, 280, 2);
	 drawLine(200, 280, 200, 90, 2);
	 
	// this will name y-axis
	 gout << setPos(140, 240) << "Monthly" << endg;
	 gout << setPos(140, 250) << "Sales" << endg;
	// this will name x-axis
	 gout << setPos(400, 300) << "Months" << endg;

	 for (int x = 0; x < no_months; x++) // this loop will draw rectangles which will represent bar in bar graph
	 {
		 
		 height[x] = ((double)sales[x] / max) * 100.0; // formula to find height of a bar
		 
		 if (height[x] < 1) // if height is smaller than 1, then height will be set to 1
		 {
			 height[x] = 1;
		 }
		
		 object[x] = drawRect(200 + x_axis, 280 - height[x], 50, height[x]); // this will display bar in bar graph
		 x_axis = x_axis + 75;
	 } 
	 
	 // if and else if satment to set color and name for the bar 
	 if (no_months == 1) 
	 {
		 setColor(object[0], 255, 0, 0); // this will set color to bar

		 gout << setPos(200, 275 - height[0]) << "Jan" << endg; // this will set name to bar 

	 }

	 else if (no_months == 2)
	 {
		 setColor(object[0], 255, 0, 0);
		 setColor(object[1], 0, 255, 0);
		 
		 gout << setPos(200, 275 - height[0]) << "Jan" << endg;
		 gout << setPos(275, 275 - height[1]) << "Feb" << endg;
		
	 }
	
	 else if (no_months == 3)
	 {
		 setColor(object[0], 255, 0, 0);
		 setColor(object[1], 0, 255, 0);
		 setColor(object[2], 0, 0, 255);
		
		 gout << setPos(200, 275 - height[0]) << "Jan" << endg;
		 gout << setPos(275, 275 - height[1]) << "Feb" << endg;
		 gout << setPos(350, 275 - height[2]) << "Mar" << endg;
	 }

	 else if (no_months == 4)
	 {
		 setColor(object[0], 255, 0, 0);
		 setColor(object[1], 0, 255, 0);
		 setColor(object[2], 0, 0, 255);
		 setColor(object[3], 255, 255, 0);

		 gout << setPos(200, 275 - height[0]) << "Jan" << endg;
		 gout << setPos(275, 275 - height[1]) << "Feb" << endg;
		 gout << setPos(350, 275 - height[2]) << "Mar" << endg;
		 gout << setPos(425, 275 - height[3]) << "Apr" << endg;
	 }

	 else if (no_months == 5)
	 {
		 setColor(object[0], 255, 0, 0);
		 setColor(object[1], 0, 255, 0);
		 setColor(object[2], 0, 0, 255);
		 setColor(object[3], 255, 255, 0);
		 setColor(object[4], 255, 0, 255);

		 gout << setPos(200, 275 - height[0]) << "Jan" << endg;
		 gout << setPos(275, 275 - height[1]) << "Feb" << endg;
		 gout << setPos(350, 275 - height[2]) << "Mar" << endg;
		 gout << setPos(425, 275 - height[3]) << "Apr" << endg;
		 gout << setPos(500, 275 - height[4]) << "May" << endg;
	 }

	 else if (no_months == 6)
	 {
		 setColor(object[0], 255, 0, 0);
		 setColor(object[1], 0, 255, 0);
		 setColor(object[2], 0, 0, 255);
		 setColor(object[3], 255, 255, 0);
		 setColor(object[4], 255, 0, 255);
		 setColor(object[5], 0, 255, 255);
		
		 gout << setPos(200, 275 - height[0]) << "Jan" << endg;
		 gout << setPos(275, 275 - height[1]) << "Feb" << endg;
		 gout << setPos(350, 275 - height[2]) << "Mar" << endg;
		 gout << setPos(425, 275 - height[3]) << "Apr" << endg;
		 gout << setPos(500, 275 - height[4]) << "May" << endg;
		 gout << setPos(575, 275 - height[5]) << "June" << endg;
	 }

	 // This will draw a box underneath the bar graph 
	 drawLine(200, 345, 425, 345, 2);
	 drawLine(200, 345, 200, 450, 2); 
	 drawLine(200, 450, 425, 450, 2);
	 drawLine(425, 345, 425, 450, 2);

	 // This will display: Max Sales, Least Sales and average sales 
	 gout << setPos(250, 340) << "Sales Statistics" << endg;
	 gout << setPos(210, 380) << "Max Sales: $" << max << endg;
	 gout << setPos(210, 400) << "Min Sales: $" << min << endg;
	 gout << setPos(210, 420) << "Avg Sales: $" << avg << endg;

}

