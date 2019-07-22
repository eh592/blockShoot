#pragma once 

class Enemy
{
public:
	Enemy();

	void draw() const;
	void move();

	void changeVelocity();

	void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;

	void setVX(int vx);
	int getVX() const;

	void setVY(int vy);
	int getVY() const;
	
	void setColor(int color);
	int getColor() const; 

	void setRadius(int radius);
	int getRadius() const;


private:
	int x_;
	int y_;
	int vx_;
	int vy_;
	int color_;
	int radius_;
};