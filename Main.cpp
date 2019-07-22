#include "graphics.h"
#include "Constants.h"
#include "Bullets.h"
#include "Gun.h"
#include "Timer.h"
#include "Enemy.h"
#include "Square.h"
#include "ScoreBoard.h"

#include <vector>

using namespace std;

bool checkingBulletSquareCollision(const Bullets& bullet, const Square& square);
double distance(int x1, int y1, int x2, int y2);

int main()
{
	srand(GetTickCount());
	Gun gun(START_POSITION_X, START_POSITION_Y, STEP_MOVEMENT_VALUE, SIDE_LENGTH_VALUES_GUN);
	Timer bulletTimer;
	Timer spawnTimer;
	Timer fallTimer;
	ScoreBoard scoreboard;
	//Enemy enemy;
	initwindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Practice Exam");
	char keyInput = NULL;
	vector <Bullets> shotBullets;
	bool gameOver = false;
	vector<int> indexedForEraseSquares;
	vector<int> indexedForEraseBullets;
	vector<Timer> spawnSquaresTimerFall;
	vector<Square> spawnSquares;
	int randomTime = rand() % 3;
	//int waitVelocityChange = (rand()%6) + 1;

	int d = 0; // variable to store distance between enemy and the bullet

	int page = 0;
	setactivepage(page);

	while (keyInput != ESC && !gameOver)
	{
		
		keyInput = NULL;
		while (kbhit())
		{
			keyInput = getch();
		}
		/*
		if (enemy.getX() + enemy.getRadius() > WINDOW_WIDTH ||
			enemy.getX() - enemy.getRadius() < 0)
		{
			enemy.setVX(-1 * enemy.getVX());
		}
		if (enemy.getY() + enemy.getRadius() > (WINDOW_HEIGHT - 2 * gun.getLength()) ||
			enemy.getY() - enemy.getRadius() < 0)
		{
			enemy.setVY(-1 * enemy.getVY());
		}*/
		for (int i = 0; i < shotBullets.size(); i++) // checks for the collision of the bullets and enemy
		{
			for (int j =  i ; j < spawnSquares.size(); j++)
			{
				if (checkingBulletSquareCollision(shotBullets[i], spawnSquares[j]))
				{
					indexedForEraseBullets.push_back(i);
					indexedForEraseSquares.push_back(j);
				//	shotBullets.erase(shotBullets.begin() + i);
				//	spawnSquares.erase(spawnSquares.begin() + j);
				}
			}
		}

		if (indexedForEraseSquares.size() > 0)
		{
			for (int i = 0; i < indexedForEraseSquares.size(); i++)
			{
				shotBullets.erase(shotBullets.begin() + indexedForEraseBullets[i]);
				spawnSquares.erase(spawnSquares.begin() + indexedForEraseSquares[i]); 
				spawnSquaresTimerFall.erase(spawnSquaresTimerFall.begin() + indexedForEraseBullets[i]);
				scoreboard.draw(scoreboard.addScore());
				// update my score here 
			}

			indexedForEraseBullets.erase(indexedForEraseBullets.begin(), indexedForEraseBullets.end());
			indexedForEraseSquares.erase(indexedForEraseSquares.begin(), indexedForEraseSquares.end());
		}
		
		for (int i = 0; i < shotBullets.size(); i++)// checks for bullets going out of range and deleting it if it does. 
		{
			if (shotBullets[i].getY() - shotBullets[i].getRadius() <= 0)
			{
				shotBullets.erase(shotBullets.begin()+i);
			}
		}
		for (int i = 0; i < spawnSquares.size(); i++)
		{
			if (spawnSquares[i].getY() + spawnSquares[i].getWidth() >= gun.getY() - 2 * gun.getLength())
			{
				spawnSquares.erase(spawnSquares.begin() + i);
				spawnSquaresTimerFall.erase(spawnSquaresTimerFall.begin() + i);
				scoreboard.draw(scoreboard.deductScore());
			}
		}
		
		// draw stuff

		//enemy.draw();
		//enemy.move();
		gun.draw();
		for (int i = 0; i < shotBullets.size(); i++)
		{
			shotBullets[i].draw();
			shotBullets[i].move();
		}
		for (int i = 0; i < spawnSquares.size(); i++)
		{
			spawnSquares[i].draw();
		}

		scoreboard.draw(scoreboard.getDisplayScore());
		
		// page flipping
		delay(FRAME_RATE_DELAY);
		setvisualpage(page);
		page = !page;
		setactivepage(page);
		cleardevice();
		line(0, gun.getY() - 3 * gun.getLength(), WINDOW_WIDTH, gun.getY() - 3 * gun.getLength());
		// randomly randomizes the velocity
		/*if (enemyTimer.returnPassedTime() >= waitVelocityChange)
		{
			enemy.changeVelocity();
			enemyTimer.reset();
			waitVelocityChange = (rand() % 6) + 1;
		}*/
		

		if (spawnTimer.returnPassedTime() >= randomTime)
		{
			spawnSquares.push_back(Square());
			spawnSquaresTimerFall.push_back(Timer());
			spawnTimer.reset();
			randomTime = rand() % 3;
		}


		for (int i = 0; i < spawnSquaresTimerFall.size(); i++)\
		{
			if (spawnSquaresTimerFall[i].returnPassedTime() >= randomTime)
			{
				spawnSquares[i].moveDown();
				spawnSquaresTimerFall[i].reset();
				randomTime = rand() % 3;
			}
		}
		/*if (fallTimer.returnPassedTime() >= 1)
		{
			for (int i = 0; i < spawnSquares.size(); i++)
			{
 				spawnSquares[i].moveDown();
 			}
			fallTimer.reset();
		}*/
		// processes the keyInput
	if (bulletTimer.returnPassedTime() >= 0.7)
		{
			switch (keyInput)
			{
			case RIGHT:
				if (gun.getX()+2*gun.getLength() != WINDOW_WIDTH)
				{
					gun.moveRight();
				}
				break;
			case LEFT:
				if (gun.getX() != 0)
				{
					gun.moveLeft();
				}
				break;
			case SPACE:
				shotBullets.push_back(gun.shoot());
				bulletTimer.reset();
				break;
			}
		}
	}
	return 0;
}



double distance(int x1, int y1, int x2, int y2)
{
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

bool checkingBulletBallCollision(const Bullets& bullet1, const Enemy& enemy)
{
	double d = distance(bullet1.getX(), bullet1.getY(), enemy.getX(), enemy.getY());

	if (d <= (enemy.getRadius() + bullet1.getRadius() )) 
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool checkingBulletSquareCollision(const Bullets& bullet, const Square& square)
{
	double distanceBottomLeftCorner = distance(bullet.getX(), bullet.getY(), 
									square.getX(), square.getY()+square.getWidth());

	double distanceBottomRightCorner = distance(bullet.getX(), bullet.getY(),
									square.getX() + square.getWidth(), square.getY() + square.getWidth());

	if (distanceBottomLeftCorner <= (bullet.getRadius()) || distanceBottomRightCorner <= (bullet.getRadius()))
	{
		return true;
	}
	else
	{
		return false;
	}
}
