#ifndef GENRECTANGLE_H
#define GENRECTANGLE_H
#pragma warning (disable:4996)

class GenRectangle 
{
private:
	int x; // x coordinate
	int y; // y coordinate
	int width;//width of rectangle 
	int height;  //height of rectangle 

public:
	GenRectangle();
	int getWidth();
	int getHeight();
	int getX();
	int getY();
	int getArea();
	int getPerimeter();
	void setWidth(int width);
	void setHeight(int height);
	void setX(int x);
	void setY(int y);
	char* getType();
	void draw();
};

#endif
