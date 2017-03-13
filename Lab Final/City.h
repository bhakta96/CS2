#ifndef CITY_H
#define CITY_H
#pragma warning(disable : 4996)
#include"GenPoint.h"

class City
{
private: 
	char* name;
	char* highway;
	GenPoint location;
	int elevation;
	const static int NUMBER_CITIES;

public:
	City();
	~City();
	City(const City& city);
	void setData(char* fn);
	char* getName();
	char* getHighway();
	GenPoint getLocation();
	int getElevation();
	double computeDistance();
	void draw();

};

#endif