#include "Gun.h"
#include "graphics.h"
#include "Constants.h"

Gun::Gun()
{
	x_ =  START_POSITION_X ;
	y_= START_POSITION_Y ;
	v_= STEP_MOVEMENT_VALUE ; // number of pixels moved when keyINput moves the gun
	length_ = SIDE_LENGTH_VALUES_GUN;
}

Gun::Gun(int x, int y, int v, int length)
{
	x_ = x;
	y_ = y;
	v_ = v;
	length_ = length;
}

void Gun::draw() const
{
	int tempDrawArray[10]; 

	tempDrawArray[8] = x_ + 2 * length_;
	tempDrawArray[9] = y_;


	tempDrawArray[6] = x_ + 2 * length_;
	tempDrawArray[7] = y_ - length_;

	tempDrawArray[4] = x_ + length_;
	tempDrawArray[5] = y_ - 2 * length_;

	tempDrawArray[2] = x_;
	tempDrawArray[3] = y_ - length_;


	tempDrawArray[0] = x_;
	tempDrawArray[1] = y_;

	setcolor(COLOR(255, 0, 0));
	setfillstyle(SOLID_FILL, WHITE);
	fillpoly(5, tempDrawArray);

}

Bullets Gun::shoot() const
{
	return Bullets(x_ + length_, y_ - 2 * length_, BULLET_VELOCITY, BULLET_RADIUS);
}

void Gun::moveRight()
{
	x_ += v_;
}
void Gun::moveLeft()
{
	x_ -= v_;
}

void Gun::setX(int x)
{
	x_ = x;
}
int Gun::getX() const
{
	return x_;
}

void Gun::setY(int y)
{
	y_ = y;
}
int Gun::getY() const
{
	return y_;
}

void Gun::setLength(int length)
{
	length_ = length;
}
int Gun::getLength() const
{
	return length_;
}