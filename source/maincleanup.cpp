#include "main.h"

void App::OnCleanup()
{
    //Free used sprites
    rings.Cleanup();

    //Free used textures
    fpstext.free();
    peak_fpstext.free();
    statstext.free();

    //Free global font
    TTF_CloseFont(globalFont);
    globalFont = NULL;

    //Destroy window
	SDL_DestroyRenderer(graphicsRenderer);
	SDL_DestroyWindow(graphicsWindow);
	graphicsRenderer = NULL;
	graphicsWindow = NULL;

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();
}
