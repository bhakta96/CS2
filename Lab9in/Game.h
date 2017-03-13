#ifndef GAME_H
#define GAME_H
#pragma warning(disable : 4996)

class Game
{
private:
	char* fileName;
	char* word;


public:
	Game();
	~Game();
	Game(const Game& game);
	char* getFileName();
	void setFileName(char* fn);
	void setWord(int rand_no);
	char* getWord();
	void draw();
};

#endif
