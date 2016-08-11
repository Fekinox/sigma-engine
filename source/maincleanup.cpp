#include "main.h"

void App::OnCleanup()
{
    //Free used sprites
    spr.free();

    //Free used textures
    statstext.free();

    //Free global font
    TTF_CloseFont(globalFont);
    globalFont = NULL;

    //Destroy window
	SDL_DestroyRenderer(graphicsRenderer);
	SDL_DestroyWindow(graphicsWindow);
	graphicsRenderer = 0;
	graphicsWindow = 0;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
