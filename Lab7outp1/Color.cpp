#include <iostream>
#include "graph1.h"
#include "Color.h"

Color::Color()
{
	int r = 0;
	int g = 0;
	int b = 0;
}
Color::Color(int r, int g, int b) // initialized private field to their respected values
{
	this->r = r;
	this->g = g;
	this->b = b;

}

void Color::setColor(int r, int g, int b) // this will clip the value if to min - max accordingly 
{
	if (r < 0)
	{
		r = 0;
	}
	if (r > 255)
	{
		r = 255;
	}

	if (g < 0)
	{
		g = 0;
	}
	if (g > 255)
	{
		g = 255;
	}

	if (b < 0)
	{
		b = 0;
	}
	if (b > 255)
	{
		b = 255;
	}

	this->r = r;
	this->g = g;
	this->b = b;

}
int Color::getRed() // getters will return respected value 
{
	return r;
}
int Color::getGreen()
{
	return g;
}
int Color::getBlue()
{
	return b;
}
Color Color ::operator+(Color right)
{
	Color result;
	result.r = r + right.r;
	result.g = g + right.g;
	result.b = b + right.b;

	// clip the values

	if (result.r > 255)
		result.r = 255;

	if (result.g > 255)
		result.g = 255;

	if (result.b > 255)
		result.b = 255;

	return result;

}
Color Color ::operator-(Color right)
{
	Color result;
	result.r = r - right.r;
	result.g = g - right.g;
	result.b = b - right.b;

	// clip the values

	if (result.r < 0)
		result.r < 0;

	if (result.g < 0)
		result.g < 0;

	if (result.b < 0)
		result.b < 0;

	return result;
}
Color Color ::operator/(int right)
{
	Color result;

	result.r = r / right;
	result.g = g / right;
	result.b = b / right;

	return result;
}
Color Color ::operator*(int right)
{
	Color result;

	result.r = r * right;
	result.g = g * right;
	result.b = b * right;

	if (result.r > 255)
		result.r = 255;

	if (result.g > 255)
		result.g = 255;

	if (result.b > 255)
		result.b = 255;

	return result;

}
bool Color ::operator==(Color right)
{
	Color result;

	this->r = right.r;
	this->g = right.g;
	this->b = right.b;

	if (result.r == right.r && result.g == right.g && result.b == right.b)
	{
		return true;
	}



	return false;



}
bool Color ::operator!=(Color right)
{
	Color result;

	if (result.r != right.r && result.g != right.g && result.b != right.b)
	{
		return true;
	}




	return false;

}
void Color ::operator=(Color right)
{
	r = right.r;
	g = right.g;
	b = right.b;
}
Color Color :: operator!()
{
	Color result;

	result.r = 255 - r;
	result.g = 255 - g;
	result.b = 255 - b;

	return result;

}
Color Color:: operator++() // prefix
{
	r+= 25;
	g += 25;
	b += 25;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;

	return(*this);
}
Color Color::operator++(int dummy) // postfix
{
	Color orig = (*this);
	r += 25;
	g += 25;
	b += 25;

	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;

	return orig;
}
Color Color::operator--() //prefix
{
	r -= 25;
	g -= 25;
	b -= 25;

	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;

	return(*this);


}
Color Color::operator--(int dummy) //postfix
{
	Color orig = (*this);
	r -= 25;
	g -= 25;
	b -= 25;

	if (r < 0)
		r = 0;
	if (g < 0)
		g = 0;
	if (b < 0)
		b = 0;

	return orig;

}
bool Color::operator<(Color right)
{
	double mag = 0;
	double mag2 = 0;

	mag = sqrt((pow(r, 2)) + pow(g, 2) + pow(b, 2)); // formula for magnitude
	mag2 = sqrt((pow(right.r , 2)) + pow(right.g, 2) + pow(right.b, 2));

	if (mag < mag2)
		return true;
	else
	return false;
}
bool Color::operator>(Color right) // this will compare two color boxes and display result accordingly 
{
	double mag = 0;
	double mag2 = 0;

	mag = sqrt((pow(r, 2)) + pow(g, 2) + pow(b, 2)); // formula for magnitude
	mag2 = sqrt((pow(right.r, 2)) + pow(right.g, 2) + pow(right.b, 2));

	if (mag > mag2)
		return true;
	else
		return false;
}
void Color::draw(int x, int y, int w, int h) // draw the colored boxes
{
	int obj = 0;



	obj = drawRect(x, y, w, h);
	::setColor(obj, r, g, b);
}