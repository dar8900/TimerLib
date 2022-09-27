#include "Timer.hpp"

void Timer::start(uint32_t Delay)
{
	if(Delay != 0)
	{
		_waitTime = Delay;
		_isRunning = true;
		_time = millis();
	}
}

void Timer::stop()
{
	_isRunning = false;
	_time = 0;
}

void Timer::restart(uint32_t NewDelay = 0)
{
	if(NewDelay != 0 && NewDelay != _waitTime)
	{
		_waitTime = NewDelay;
	}
	_time = millis();
	_isRunning = true;
}

bool Timer::isRunning()
{
	return _isRunning;
}

bool Timer::isOver(bool Restart = false, uint32_t NewDelay)
{
	bool End = false;
	if(_isRunning)
	{
		if(millis() - _time >= _waitTime)
		{
			End = true;
			stop();
			if(Restart)
			{
				restart(NewDelay);
			}
		}
	}
	return End;
}