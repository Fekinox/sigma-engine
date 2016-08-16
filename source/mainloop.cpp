#include "main.h"

void App::OnLoop()
{
	stats.str("");
    stats << "Sprite ID: " << currentSprite
		  << " Flip State: " << rings.Get(currentSprite)->Flip()
          << " X: " << rings.Get(currentSprite)->XaOrig()
          << " Y: " << rings.Get(currentSprite)->YaOrig();

	if(!statstext.Load(graphicsRenderer, globalFont, stats.str().c_str(), textColor))
    {
        printf("Failed to load text texture!");
    }

    rings.Get(currentSprite)->OnAnimate();
}
