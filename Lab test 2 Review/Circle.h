#ifndef CIRCLE_H
#define CIRCLE_H
#pragma warning (disable:4996)

class Circle
{
private:
	int x;
	int y;
	int radius;

public:
	Circle();
	void setX(int x);
	void setY(int y);
	void setRadius(int radius);
	int getX();
	int getY();
	int getRadius();
	int getArea();
	int getPerimeter();
	char* getType();
	void draw();
	bool operator==(Circle rs);
	void operator=(Circle rs);
	Circle operator!();
};

#endif
