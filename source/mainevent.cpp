#include "main.h"

void App::OnEvent(SDL_Event* event)
{
    Event::OnEvent(event);
}

void App::OnExit()
{
    Running = false;
}
