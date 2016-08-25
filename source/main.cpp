#include "main.h"

App::App()
{
    graphicsWindow = NULL;
    graphicsRenderer = NULL;
    globalFont = NULL;
    Running = true;
    fps.precision(6);
}

int App::OnExecute()
{
    if(OnInit() == false)
    {
        return -1;
    }

	ticks.start();

    SDL_Event e;
    while(Running)
    {
        capTimer.start();
        while(SDL_PollEvent(&e))
        {
            OnEvent(&e);
        }
        OnPreRender();
        OnRender();
        OnPostRender();
    }
    OnCleanup();
    return 0;
}

int main(int argc, char** argv)
{
    App app;
    return app.OnExecute();
}
