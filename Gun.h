#pragma once
#include "Bullets.h"

class Gun
{
public: 
	Gun();
	Gun(int x, int y, int v, int length);

	void draw() const;
	Bullets shoot() const;

	void moveRight();
	void moveLeft();

	void setX(int x);
	int getX() const;

	void setY(int y);
	int getY() const;

	void setV(int v);
	int getV() const;

	void setLength(int length);
	int getLength() const;
protected:
	int x_; // bottom right corner of the gun
	int y_;

	int v_; // position step for each keyInput of movement
	int length_;
};