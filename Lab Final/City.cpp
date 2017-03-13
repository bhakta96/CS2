#include<iostream>
#include"City.h"
#include"graph1.h"
#include<fstream>
#include <string>
#include <ctime>

const int City::NUMBER_CITIES = 31;

City::City()
{
	name = NULL;
	highway = NULL;
	location.setPoint(0, 0);
	elevation = 0;
}
City::~City()
{
	delete[] name;
	delete[] highway;
}
City::City(const City& city)
{
	name = new char[strlen(city.name) + 1];
	strcpy(name, city.name);

	highway = new char[strlen(city.highway) + 1];
	strcpy(highway, city.highway);
}
void City::setData(char* fn)
{
	char name[255];
	char highway[255];
	int elevation = 0;
	int length = 0;
	int noSides = 0;
	int x = 0;
	int y = 0;
	int line_count = 0;
	int rand_no = 0;

	//Open the fstream
	fstream in_file(fn, ios::in);

	//Check if opened correctly
	if (!in_file)
	{
		cout << "Cannot open fileName" << endl;
		exit(-1);
	}

	//Generate random #
	srand(time(0));

	//Generate the random #
	rand_no = rand() % NUMBER_CITIES-1;

	while (true)
	{
		in_file >> name >> x >> y >> highway >> elevation;

		if (in_file.eof())
			break;

		if (rand_no == line_count)
			break;

		line_count++;
	}

	//Set the pdfs to thedata read from the file
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->highway = new char[strlen(highway) + 1];
	strcpy(this->highway, highway);

	this->elevation = elevation;
	

	this->location.setPoint(x, y);
}
char* City::getName()
{
	return (name);
}
char* City::getHighway()
{
	return (highway);
}
GenPoint City::getLocation()
{
	return(location);
}
int City::getElevation()
{
	return (elevation);
}
double City::computeDistance()
{
	double distance = 0;
	double Total = 0;
	distance = sqrt(pow(306 - location.getX(), 2) + pow(240 - location.getY(), 2));

	Total = (distance * 0.6);

	return(Total);
}
void City::draw()
{
	int obj = 0;
	displayBMP("arkansas1.bmp",0, 0);
	obj = drawLine(306, 240, location.getX(), location.getY(), 2);
	setColor(obj, 0, 0, 255);
}