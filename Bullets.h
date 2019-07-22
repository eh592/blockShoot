#pragma once

class Bullets 
{
public:
	Bullets(int x, int y, int v , int radius);
		

	void draw() const;
	void move();

	void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;

	void setRadius(int radius);
	int getRadius() const;


private:
	int x_;
	int y_;
	int v_;

	int radius_;
	int color_;
};