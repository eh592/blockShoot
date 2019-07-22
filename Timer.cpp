#include "Timer.h"
#include "graphics.h"

Timer::Timer()
{
	startTime_ = GetTickCount();
}

int Timer::returnPassedTime() const
{
	return (GetTickCount() - startTime_)/1000;
}

void Timer::reset()
{
	startTime_ = GetTickCount();
}