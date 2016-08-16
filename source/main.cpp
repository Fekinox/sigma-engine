#include "main.h"

App::App()
{
    graphicsWindow = NULL;
    graphicsRenderer = NULL;
    globalFont = NULL;
    Running = true;
}

int App::OnExecute()
{
    if(OnInit() == false)
    {
        return -1;
    }

    SDL_Event e;
    while(Running)
    {
        capTimer.start();
        while(SDL_PollEvent(&e))
        {
            OnEvent(&e);
        }
        OnLoop();
        OnRender();
    }
    OnCleanup();
    return 0;
}

int main(int argc, char** argv)
{
    App app;
    return app.OnExecute();
}
