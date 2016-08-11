#include "main.h"

void App::OnLoop()
{
    stats.str("");
    stats << "X: " << spr.GetX() << " Y: " << spr.GetY() << " Origin X: " << spr.GetXOrig() << " Y: " << spr.GetYOrig() << " Origin Position X: " << spr.GetXaOrig() << " Y: " << spr.GetYaOrig();

	if(!statstext.Load(graphicsRenderer, globalFont, stats.str().c_str(), textColor))
    {
        printf("Failed to load text texture!");
    }

    spr.OnAnimate();
}
