#ifndef __MAIN_H__
#define __MAIN_H__

class App;
class Event;

#include "texture.h"
#include "events.h"
#include "sprite.h"
#include "timer.h"

class App : public Event
{
    private:
        bool Running; //Running flag

        SDL_Window* graphicsWindow; //The window
        SDL_Renderer* graphicsRenderer; //The renderer
        TTF_Font* globalFont; //The global font

        Timer capTimer; //Frames per second cap timer

        Sprite spr; //A sprite
        Texture statstext; //Some statstext
        SDL_Color textColor{ 0x00, 0x00, 0x00 }; //Text color
        std::stringstream stats; //Stringsteam of tstatstext
    public:
        App();
        int OnExecute(); //When the program executes
    public:
        bool OnInit(); //When the program starts
        void OnEvent(SDL_Event* e); //When polling events
        void OnExit(); //When the program is exited
        void OnLoop(); //When the program loops
        void OnRender(); //When the program renders
        void OnCleanup(); //While cleaning up
};

#endif //MAIN_H
