#include "main.h"

bool App::OnInit()
{
	//Initialize SDL
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL failed to initialize! Details: %s\n", SDL_GetError());
		return false;
	}
    else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create a window
		graphicsWindow = SDL_CreateWindow("Densite", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(graphicsWindow == NULL)
		{
			printf("Window failed to display! Details: %s\n", SDL_GetError());
			return false;
		}
		else
		{
			//Create renderer for window
			graphicsRenderer = SDL_CreateRenderer(graphicsWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(graphicsRenderer == NULL)
			{
				printf("Renderer failed to be created! Details: %s\n", SDL_GetError());
				return false;
			}
			else
			{
				SDL_SetRenderDrawColor(graphicsRenderer, 0xFF, 0x66, 0x66, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					printf("SDL_image failed to initialize! Details: %s\n", IMG_GetError());
					return false;
				}

				//Initialize SDL_ttf
				if (TTF_Init() == -1)
				{
					printf("SDL_ttf could not initialize!");
					return false;
				}
			}
		}
	}

    globalFont = TTF_OpenFont("media/font/ProggyCleanCE.ttf", 16);
    if(globalFont == NULL)
    {
        printf("Failed to load font!");
        return false;
    }

	//Make some sprites
	//Initialize spritebank
	if(!rings.Init(graphicsRenderer))
	{
		printf("Failed to load sprites!");
	}

	//Add two sprites
	std::string filedir = ("media/img/ring/");

	files.push_back(filedir + "ring1.png");
	files.push_back(filedir + "ring2.png");

	//For every filename in files, check the iterator to connect it to a sprite, then increment it.
	int it = SPRITE_RING1;
	for(const auto& filename : files)
	{
		switch(it)
		{
			case static_cast<int>(SPRITE_RING1):
			{
				rings.AddSprite(filename,
								it,
								40,
								40,
								40,
								20,
								20,
								0.0,
								SDL_FLIP_NONE);
				break;
			}
			case static_cast<int>(SPRITE_RING2):
			{
				rings.AddSprite(filename,
								it,
								40,
								40,
								40,
								10,
								10,
								0.0,
								SDL_FLIP_HORIZONTAL);
				break;
			}
			default: continue; break;
		}
		it++;
	}
	currentSprite = SPRITE_RING1;

	return true;
}
