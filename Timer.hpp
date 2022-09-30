#ifndef TIMERLIB_H
#define TIMERLIB_H
#include <Arduino.h>
#include <stdint.h>


class Timer
{
	public:
		Timer(bool InSeconds = false) : _inSeconds(InSeconds) {};
		void start(uint32_t Delay);
		void stop();
		void restart(uint32_t NewDelay = 0);
		bool isRunning();
		bool isOver(bool Restart = false, uint32_t NewDelay = 0);
	private:
		bool _inSeconds = false;
		uint32_t _time = 0;
		uint32_t _waitTime = 0;
		bool _isRunning = false;

};

#endif