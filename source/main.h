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

        SpriteBank rings; //Collection of sprites
        std::string currentSprite; //Filename of sprite in use
        Texture statstext; //Some statstext
        SDL_Color textColor{ 0x00, 0x00, 0x00 }; //Text color
        std::stringstream stats; //Stringsteam of tstatstext
    public:
        App();
        int OnExecute(); //When the program executes
    public:
        void OnEvent(SDL_Event* e); //When polling events
        void OnExit(); //When the program is exited
        void OnKeyDown(SDL_Keycode sym, Uint16 mod, Uint16 scancode); //When a key is pressed
        void OnKeyUp(SDL_Keycode sym, Uint16 mod, Uint16 scancode); //When a key is released
    public:
        bool OnInit(); //When the program starts
        void OnLoop(); //When the program loops
        void OnRender(); //When the program renders
        void OnCleanup(); //While cleaning up
};

#endif //MAIN_H
