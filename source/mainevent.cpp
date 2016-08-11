#include "main.h"

void App::OnEvent(SDL_Event* event)
{
    Event::OnEvent(event);
}

void App::OnExit()
{
    Running = false;
}

void App::OnKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
    switch(sym)
    {
        case SDLK_SPACE:
        {
            if(currentSprite = "")
            break;
        }
    }
}

void App::OnKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode)
{
    switch(sym)
    {
        //
    }
}
