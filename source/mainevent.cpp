#include "main.h"
#include "log.h"

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
            currentSprite->ResetFrame();
            if(currentSprite->Name() == "ring1") currentSprite = rings.Get(SPRITE_RING2);
            else if(currentSprite->Name() == "ring2") currentSprite = rings.Get(SPRITE_RING1);
            break;
        }
        case SDLK_c:
        {
            system("cls");
        }
        case SDLK_f:
        {
            LOG("- FPS ANALYTICS -"
            << "\nFrames rendered since starting the program: " << pF
            << "\nFrames Tallied In Last Timeframe (" << TIMEFRAME/1000 << " s): " << FTILT
            << "\nFrames rendered since last FTILT check: " << cF
            << "\n\nRaw FPS: " << fpsc
            << "\nPeak FPS: " << fpsp);
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
