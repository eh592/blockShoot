#include "Square.h"
#include "Constants.h"
#include "graphics.h"


Square::Square()
{
	width_ = SQUARE_WIDTH;
	x_ = (rand() % (WINDOW_WIDTH - 2*SQUARE_WIDTH)) +SQUARE_WIDTH;
	color_ = rand() % 16;
	y_ = 0;
}
void Square::draw() const
{
	int tempArray[8];

	tempArray[0] = x_;
	tempArray[1] = y_;

	tempArray[2] = x_ + width_;
	tempArray[3] = y_;

	tempArray[4] = x_ + width_;
	tempArray[5] = y_ + width_;

	tempArray[6] = x_;
	tempArray[7] = y_ + width_;

	setcolor(RED);
	setfillstyle(SOLID_FILL, color_);
	fillpoly(4, tempArray);
}
void Square::moveDown()
{
	y_ += width_;
}
void Square::setX(int x)
{
	x_ = x;
}
int Square::getX() const
{
	return x_;
}
void Square::setY(int y)
{
	y_ = y;
}
int Square::getY() const
{
	return y_;
}

void Square::setWidth(int width)
{
	width_ = width;
}
int Square::getWidth() const
{
	return width_;
}
