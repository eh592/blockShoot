#pragma once
#include <string>

using namespace std;

class ScoreBoard
{
public:
	ScoreBoard();
	
	void draw(string score) const; //std::string score

	string addScore() ; // each successive hit should add 10 to the score count

	string deductScore();

	void setDisplayScore(string displayScore);
	string getDisplayScore() const;

	void setScore(int score);
	int getScore() const;
	
private:
	string displayScore_;
	int scoreCount_;
};