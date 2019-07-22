#pragma once 

class Timer
{
public:
	Timer();

	int returnPassedTime() const; // returns passed time in seconds
	void reset();
private:
	int startTime_;
};