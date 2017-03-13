#ifndef LINE_H
#define LINE_H
#pragma warning (disable:4996)
class Line
{
private:
	char* letters;
public:
	Line();
	char* getLine();
	char getCharAt(int index);
	void setLine(char *line);
	Line(const Line &obj); // copy constructor
	~Line(); // destructor

};

#endif