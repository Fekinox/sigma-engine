#include "timer.h"

Timer::Timer()
{
    //Initialize values
    startTicks = 0;
    pausedTicks = 0;

    paused = false;
    started = false;
}

void Timer::start()
{
    //Start the timer
    started = true;

    //Unpause the timer
    paused = false;

    //Get the current clock time
    startTicks = SDL_GetTicks();
    pausedTicks = 0;
}

void Timer::stop()
{
    //Stop the timer
    started = false;

    //Unpause the timer
    paused = false;

    //Reset clock values
    startTicks = 0;
    pausedTicks = 0;
}

void Timer::pause()
{
    //If timer is running and unpaused
    if(started && !paused)
    {
        //Pause the timer
        paused = true;

        //Get the time paused for
        pausedTicks = SDL_GetTicks() - startTicks;
        startTicks = 0;
    }
}

void Timer::unpause()
{
    //If timer is running and paused
    if(started && paused)
    {
        //Pause the timer
        paused = false;

        //Reset starting ticks and paused ticks
        startTicks = SDL_GetTicks() - startTicks;
        pausedTicks = 0;
    }
}

Uint32 Timer::getTicks()
{
    //Actual timer time
    Uint32 time = 0;
    //If timer is running
    if(started)
    {
        //If timer is paused
        if(paused)
        {
            //Return the number of ticks when the timer was paused
            time = pausedTicks;
        }
        else
        {
            //Return the current time minus the start time
            time = SDL_GetTicks() - startTicks;
        }
    }

    return time;
}

bool Timer::isStarted()
{
    //Timer is running and paused/unpaused
    return started;
}

bool Timer::isPaused()
{
    //Timer is running and paused/unpaused
    return paused;
}
