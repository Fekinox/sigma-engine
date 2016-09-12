#ifndef __TIMER_H__
#define __TIMER_H__

#include <SDL2/SDL.h>

class Timer
{
	public:
		//Initializes variables
		Timer();

		//Various clock actions
		void start();
		void stop();
		void pause();
		void unpause();

		//Gets the timer's time
		Uint32 getTicks();

		//Checks timer status
		bool isStarted();
		bool isPaused();
	private:
		//Clock time when timer started
		Uint32 startTicks;
		//Ticks stored when the timer was paused
		Uint32 pausedTicks;

		//Timer status
		bool paused;
		bool started;
};

#endif //TIMER_H
