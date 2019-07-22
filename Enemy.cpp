#include "Enemy.h"
#include "graphics.h"
#include "Constants.h"

Enemy::Enemy()
{
	radius_ = ENEMY_BALL_RADIUS;
	x_ = (rand() % (WINDOW_WIDTH-radius_)) + radius_;
	y_ = (rand() % (WINDOW_HEIGHT-radius_)) + radius_;
	vx_ = (rand() % 20) - 10;
	vy_ = (rand() % 20) - 10;
	color_ = RED;
}
void Enemy::draw() const
{
	setcolor(color_);
	setfillstyle(SOLID_FILL, BLUE);
	fillellipse(x_, y_, radius_, radius_);
}
void Enemy::move()
{
	x_ += vx_;
	y_ += vy_;
}

void Enemy::changeVelocity()
{
	vx_ = (rand() % 20) - 10;
	vy_ = (rand() % 10) - 5; 
}
void Enemy::setX(int x)
{
	x_ = x;
}
int Enemy::getX() const
{
	return x_;
}
void Enemy::setY(int y)
{
	y_ = y;
}
int Enemy::getY() const
{
	return y_;
}

void Enemy::setVX(int vx)
{
	vx_ = vx;
}
int Enemy::getVX() const
{
	return vx_;
}

void Enemy::setVY(int vy)
{
	vy_ = vy;
}
int Enemy::getVY() const
{
	return vy_;
}

void Enemy::setColor(int color)
{
	color_ = color;
}
int Enemy::getColor() const
{
	return color_;
}
void Enemy::setRadius(int radius)
{
	radius_ = radius;
}
int Enemy::getRadius() const
{
	return radius_;
}
