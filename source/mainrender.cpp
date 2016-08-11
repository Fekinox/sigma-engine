#include "main.h"

void App::OnRender()
{
    SDL_SetRenderDrawColor(graphicsRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(graphicsRenderer);

    spr.Render(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

    statstext.Render((SCREEN_WIDTH-statstext.GetWidth())/2, spr.BBBottom());

    SDL_SetRenderDrawColor(graphicsRenderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_Rect bb = {spr.BBLeft(), spr.BBTop(), spr.BBWidth(), spr.BBHeight()};
    SDL_RenderDrawRect(graphicsRenderer, &bb);

    SDL_SetRenderDrawColor(graphicsRenderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawLine(graphicsRenderer, SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT);
    SDL_RenderDrawLine(graphicsRenderer, 0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2);

    SDL_RenderPresent(graphicsRenderer);

    //If frame finished early
    int frameTicks = capTimer.getTicks();
    if(frameTicks < 1000/FPS)
    {
        //Wait remaining time
        SDL_Delay((1000/FPS) - frameTicks);
    }
}
