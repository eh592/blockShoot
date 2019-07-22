#include "graphics.h"
#include "Bullets.h"
#include "Constants.h"


Bullets::Bullets(int x, int y, int v, int radius)
{
	x_ = x;
	y_ = y;
	v_ = v;
	radius_ = radius;
	color_ = BULLET_COLOR;
}

void Bullets::draw() const
{
	setcolor(WHITE);
	setfillstyle(SOLID_FILL, color_);
	fillellipse(x_, y_, radius_, radius_);
}
void Bullets::move()
{
	y_ -= v_;
}

void Bullets::setX(int x)
{
	x_ = x;
}
int Bullets::getX() const
{
	return x_;
}

void Bullets::setY(int y)
{
	y_ = y;
}
int Bullets::getY() const
{
	return y_;
}

void Bullets::setRadius(int radius)
{
	radius_ = radius;
}
int Bullets::getRadius() const
{
	return radius_;
}