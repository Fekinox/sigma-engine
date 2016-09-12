#include "main.hpp"

App::App()
{
	graphicsWindow = NULL;
	graphicsRenderer = NULL;
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
		frameTicks.start();
		while(SDL_PollEvent(&e))
		{
			OnEvent(&e);
		}

		if(Running)
		{
			OnPreRender();
			OnRender();
			OnPostRender();
		}
	}
	OnCleanup();
	return 0;
}

int main(int argc, char** argv)
{
	App app;
	return app.OnExecute();
}
