#include "ScoreBoard.h"
#include "graphics.h"
#include <string>

using namespace std;

ScoreBoard::ScoreBoard()
{
	scoreCount_ = 0;
	//displayScore_ = " ";
}

void ScoreBoard::draw(string score) const
{
	char* newResult = new char[score.size() + 1];
	copy(score.begin(), score.end(), newResult);
	newResult[score.size()] = '\0';
	setcolor(RGB(255, 0, 0));
	settextstyle(GOTHIC_FONT, HORIZ_DIR, 2);
	moveto(0, 0);
	outtext(newResult);

	delete[] newResult;

}
string ScoreBoard::addScore() 
{
	scoreCount_ += 10;

	string Result;
	ostringstream convert;
	convert << scoreCount_;
	Result = convert.str();
	return Result;
}

string ScoreBoard::deductScore()
{
	scoreCount_ -= 5;

	string Result;
	ostringstream convert;
	convert << scoreCount_;
	Result = convert.str();
	return Result;
}
void ScoreBoard::setDisplayScore(string displayScore)
{
	displayScore_ = displayScore;
}
string ScoreBoard::getDisplayScore() const
{
	string Result;
	ostringstream convert;
	convert << scoreCount_;
	Result = convert.str();
	return Result;
}

void ScoreBoard::setScore(int score)
{
	scoreCount_ = score;
}
int ScoreBoard::getScore() const
{
	return scoreCount_;
}
