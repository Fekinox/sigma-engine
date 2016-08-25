#include "main.h"

void App::OnRender()
{
    SDL_SetRenderDrawColor(graphicsRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(graphicsRenderer);

    currentSprite->Render(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

    statstext.Render((SCREEN_WIDTH-statstext.Width())/2, currentSprite->BBBottom());

    fpstext.Render(0, 0);

    peak_fpstext.Render(0, 20);

    stable_fpstext.Render(0, 40);

    SDL_SetRenderDrawColor(graphicsRenderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawLine(graphicsRenderer, SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT);
    SDL_RenderDrawLine(graphicsRenderer, 0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2);

    SDL_SetRenderDrawColor(graphicsRenderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_Rect bb = {currentSprite->BBLeft(), currentSprite->BBTop(), currentSprite->BBWidth(), currentSprite->BBHeight()};
    SDL_RenderDrawRect(graphicsRenderer, &bb);

    SDL_RenderPresent(graphicsRenderer);
}
