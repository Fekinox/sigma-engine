#include "main.hpp"

void App::OnRender()
{
    SDL_SetRenderDrawColor(graphicsRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderClear(graphicsRenderer);

    rings.Render();

    statstext.Render((SCREEN_WIDTH-statstext.Width())/2, rings.BBBottom());

    SDL_SetRenderDrawColor(graphicsRenderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawLine(graphicsRenderer, SCREEN_WIDTH/2, 0, SCREEN_WIDTH/2, SCREEN_HEIGHT);
    SDL_RenderDrawLine(graphicsRenderer, 0, SCREEN_HEIGHT/2, SCREEN_WIDTH, SCREEN_HEIGHT/2);

    SDL_SetRenderDrawColor(graphicsRenderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_Rect bb = {rings.BBLeft(), rings.BBTop(), rings.BB().hbox.BBWidth(), rings.BB().hbox.BBHeight()};
    SDL_RenderDrawRect(graphicsRenderer, &bb);

    SDL_RenderPresent(graphicsRenderer);
}
