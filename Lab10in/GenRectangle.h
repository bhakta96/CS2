#ifndef GENRECTANGLE_H
#define GENRECTANGLE_H

#include "Quadrilateral.h"

class GenRectangle : public Quadrilateral
{

public:
	GenRectangle();
	void setPoints(GenPoint ul, GenPoint lr);
	double getArea();
	void print();
};

#endif
