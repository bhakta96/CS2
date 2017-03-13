#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
private:
	int cart;
	int rock;
	int brokenRock;
	int tracks;

public:
	Display();
	int getCart();
	int getRock();
	int getBrokenRock();
	void displayInitialScene();

};

#endif
