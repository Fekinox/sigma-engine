#include "main.hpp"

void	App::OnEvent(SDL_Event* event)
{
	Event::OnEvent(event);
}

void	App::OnExit()
{
	Running = false;
}

void	App::OnKeyPress(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
	switch(sym)
	{
		case SDLK_SPACE:
		{
			k_space->Press(rings.input);
			break;
		}
		case SDLK_LSHIFT:
		{
			k_shift->Press(rings.input);
			break;
		}
		case SDLK_RSHIFT:
		{
			k_shift->Press(rings.input);
			break;
		}
		case SDLK_c:
		{
			system("cls");
			break;
		}
		case SDLK_f:
		{
			LOG("- FPS ANALYTICS -"
			<< "\n  Frames rendered since starting the program: " << pF
			<< "\n  Frames Tallied In Last Timeframe (" << TIMEFRAME/1000 << " s): " << FTILT
			<< "\n  Frames rendered since last FTILT check: " << cF);
			break;
		}
	}
}

void	App::OnKeyRelease(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
	switch(sym)
	{
		case SDLK_SPACE:
		{
			k_space->Release(rings.input);
			break;
		}
		case SDLK_LSHIFT:
		{
			k_shift->Release(rings.input);
			break;
		}
		case SDLK_RSHIFT:
		{
			k_shift->Release(rings.input);
			break;
		}
	}
}
