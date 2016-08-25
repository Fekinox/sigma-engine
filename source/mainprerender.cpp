#include "main.h"
#include "log.h"

int App::Random(int min, int max)
{
    std::uniform_int_distribution<int> dist(min, max);
    return dist(gen);
}

void App::OnPreRender()
{
    stats << "Sprite ID: " << currentSprite->Name()
		  << " Flip State: " << currentSprite->Flip()
          << " X: " << currentSprite->XaOrig()
          << " Y: " << currentSprite->YaOrig();

	if(!statstext.Load(graphicsRenderer, globalFont, stats.str().c_str(), textColor))
    {
        LOG("Failed to load text texture!");
    }

	stats.flush();
	stats.str("");

	fps << "Current FPS: " << fpsc;

	if(!fpstext.Load(graphicsRenderer, globalFont, fps.str().c_str(), textColor))
    {
        LOG("Failed to load text texture!");
    }

	fps.flush();
	fps.str("");

    peak_fps << "Peak FPS: " << fpsp;

	if(!peak_fpstext.Load(graphicsRenderer, globalFont, peak_fps.str().c_str(), textColor))
    {
        LOG("Failed to load text from " << peak_fps.str());
    }

	peak_fps.flush();
	peak_fps.str("");

    if(timeTicks >= TIMEFRAME)
    {
        stable_fps << "Frames Tallied In Last Timeframe (" << TIMEFRAME/1000.f << " s): " << FTILT;

    	if(!stable_fpstext.Load(graphicsRenderer, globalFont, stable_fps.str().c_str(), textColor))
        {
            LOG("Failed to load text from " << stable_fps.str());
        }

    	stable_fps.flush();
    	stable_fps.str("");
    }
}
