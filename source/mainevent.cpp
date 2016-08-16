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
            rings.Get(currentSprite)->ResetFrame();
            if(currentSprite == SPRITE_RING1) currentSprite = SPRITE_RING2;
            else if (currentSprite == SPRITE_RING2) currentSprite = SPRITE_RING1;
            break;
        }
        case SDLK_h:
        {
            if (rings.Get(currentSprite)->Flip() != SDL_FLIP_HORIZONTAL)
                rings.Get(currentSprite)->Flip(SDL_FLIP_HORIZONTAL);
            break;
        }
        case SDLK_n:
        {
            if (rings.Get(currentSprite)->Flip() != SDL_FLIP_NONE)
                rings.Get(currentSprite)->Flip(SDL_FLIP_NONE);
            break;
        }
        case SDLK_v:
        {
            if (rings.Get(currentSprite)->Flip() != SDL_FLIP_VERTICAL)
                rings.Get(currentSprite)->Flip(SDL_FLIP_VERTICAL);
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
