#include "main.h"

void App::OnPostRender()
{
    //If frame finished early
    int frameTicks = capTimer.getTicks();

    if(frameTicks < 1000/FPS)
    {
        //Wait remaining time
        SDL_Delay((1000/FPS) - frameTicks);
    }

    fpsc = 1 / (capTimer.getTicks() / 1000.f);
    if(fpsc > fpsp) fpsp = fpsc;

    timeTicks = ticks.getTicks();
    if(timeTicks < TIMEFRAME)
    {
        cF++;
    }
    else
    {
        FTILT = cF+1;
        cF = 0;
        ticks.start();
    }
    pF++;
}
