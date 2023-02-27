#include "Timer.hpp"

void Timer::start(uint32_t Delay)
{
	if(Delay != 0 && !_isRunning)
	{
		_waitTime = _inSeconds ? Delay * 1000 : Delay;
		_isRunning = true;
		_time = millis();
	}
}

void Timer::stop()
{
	_isRunning = false;
	_time = 0;
}

bool Timer::elapsed()
{
	if(_isRunning)
	{
		if(millis() - _time >= _waitTime){
			return true;
		}else {
			return false;
		}
	}
	return false;
}

void Timer::restart(uint32_t NewDelay)
{
	if(NewDelay != 0 && NewDelay != _waitTime)
	{
		_waitTime = _inSeconds ? NewDelay * 1000 : NewDelay;
	}
	_time = millis();
	_isRunning = true;
}

bool Timer::isRunning()
{
	return _isRunning;
}

bool Timer::isOver(bool Restart, uint32_t NewDelay)
{
	bool End = false;
	if(elapsed())
	{
		End = true;
		stop();
		if(Restart)
		{
			restart(NewDelay);
		}
	}
	return End;
}