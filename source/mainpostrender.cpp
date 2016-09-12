#include "main.hpp"

void App::OnPostRender()
{
	//If frame updated too quickly...
	int frametime = frameTicks.getTicks();
	if (frametime < MS_PER_FRAME)
	{
		SDL_Delay(MS_PER_FRAME - frametime);
	}
	
	programtime = programTicks.getTicks();
	if(programtime < TIMEFRAME)
	{
		cF++;
	}
	else
	{
		FTILT = cF+1;
		cF = 0;
		programTicks.start();
	}
	pF++;
}
