#pragma once

class Square
{
public:

	Square();

	void draw() const;
	void moveDown();

	void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;

	void setWidth(int width);
	int getWidth() const;

private:
	int x_;
	int y_;
	int width_;
	int color_;
};