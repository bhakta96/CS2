#ifndef WORD_H
#define WORD_H
#pragma warning (disable:4996)

class Word
{
private:
	char* word;
	


public:
	Word();
	~Word();
	Word(const Word& word);
	void setWord(char* word);
	char* getWord();
	void draw();
};

#endif
