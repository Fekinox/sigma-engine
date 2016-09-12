#include "main.hpp"

void App::OnCleanup()
{
	//DESTRUCTION//
	LOG("-- DESTRUCTION");

	SDL_SetRenderDrawColor(graphicsRenderer, 0x00, 0x00, 0x00, 0xFF);
	SDL_RenderClear(graphicsRenderer);
	SDL_RenderPresent(graphicsRenderer);

	statstext.free();

	delete gfont;
	gfont = nullptr;

	//Deleting spritebanks
	//rings.Cleanup();

	//Destroy window
	SDL_DestroyRenderer(graphicsRenderer);
	SDL_DestroyWindow(graphicsWindow);
	graphicsRenderer 	= nullptr;
	graphicsWindow 		= nullptr;

	//Quit SDL subsystems
	TTF_Quit();
	LOG("Quitting TTF");
	IMG_Quit();
	SDL_Quit();
}
