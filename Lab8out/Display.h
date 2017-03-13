#ifndef DISPLAY_H
#define DISPLAY_H

class Display
{
private:
	int cart;
	int rock;
	int brokenRock;
	int rockInCart;

public:
	Display();
	int getCart();
	int getRock();
	int getBrokenRock();
	int getRockInCart();
	void displayInitialScene();

};

#endif
