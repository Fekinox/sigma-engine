#include "main.h"
#include "log.h"

#include <ctime>

//Initialization

bool App::OnInit()
{
	//Print message to console indicating debug state
	#if DEBUG == 1
		std::cout << "DEBUG MODE IS ACTIVE.\n";
		time_t rawtime;
		time(&rawtime);
		#if TOFILE == 1
			std::cout << "LOGGING TO A FILE.\n";
		#else
			std::cout << "PRINTING TO CONSOLE.\n";
		#endif
		LOG("--- LOG DATE: " << ctime(&rawtime) << "\n");
	#else
		std::cout << "DEBUG MODE IS INACTIVE.\n";
	#endif //DEBUG

	LOG("-- INITIALIZATION");

	//Initialize SDL
	LOG("Initializing SDL...");
	if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		LOG("SDL failed to initialize! Error: " << SDL_GetError());
		return false;
	}
    else
	{
		//Set texture filtering to linear
		LOG("Setting texture filtering to linear...");
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			LOG("Warning: Linear texture filtering not enabled!");
		}

		//Create a window
		LOG("Creating window...");
		graphicsWindow = SDL_CreateWindow("Densite", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if(graphicsWindow == NULL)
		{
			LOG("Failed to create window! Error: " << SDL_GetError());
			return false;
		}
		else
		{
			//Create renderer for window
			LOG("Creating renderer...");
			graphicsRenderer = SDL_CreateRenderer(graphicsWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
			if(graphicsRenderer == NULL)
			{
				LOG("Renderer failed to be created! Error: " << SDL_GetError());
				return false;
			}
			else
			{
				SDL_SetRenderDrawColor(graphicsRenderer, 0xFF, 0x66, 0x66, 0xFF);

				//Initialize PNG loading
				LOG("Initializing SDL_image...");

				int imgFlags = IMG_INIT_PNG;
				if( !( IMG_Init( imgFlags ) & imgFlags ) )
				{
					LOG("SDL_image failed to initialize! Error: " << IMG_GetError());
					return false;
				}

				//Initialize SDL_ttf
				LOG("Initializing SDL_ttf...");

				if (TTF_Init() == -1)
				{
					LOG("SDL_ttf failed to initialize! Error: " << TTF_GetError());
					return false;
				}
			}
		}
	}

    LOG("\n");

    globalFont = TTF_OpenFont("media/font/ProggyCleanCE.ttf", 16);
	LOG("Setting global font...");
    if(globalFont == NULL)
    {
        LOG("Failed to load font!");
        return false;
    }

	//Make some sprites
	//Initialize spritebank
	if(!rings.Init(graphicsRenderer))
	{
		LOG("Failed to load sprites!");
	}

	//Add two sprites
	std::string filedir = ("media/img/ring/");

	files.push_back(filedir + "ring1.png");
	files.push_back(filedir + "ring.png");

	//For every filename in files, check the iterator to connect it to a sprite, then increment it.
	int it = SPRITE_RING1;
	for(const auto& filename : files)
	{
		switch(it)
		{
			case (int)SPRITE_RING1:
			{
				rings.AddSprite(filename,
								it,
								40,
								40,
								40,
								20,
								20);
				break;
			}
			case (int)SPRITE_RING2:
			{
				rings.AddSprite(filename,
								it,
								40,
								20,
								20,
								20,
								20,
								10,
								10);
				break;
			}
			default: continue; break;
		}
		it++;
	}

	currentSprite = rings.Get(SPRITE_RING1);

	return true;
}
