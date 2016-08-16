#ifndef __MAIN_H__
#define __MAIN_H__

#include <vector>

class App;
class Event;

#include "texture.h"
#include "events.h"
#include "spritebank.h"
#include "timer.h"

class App : public Event
{
    private:
        bool Running; //Running flag

        std::vector<std::string> files; //Files to load

        enum sprite_file //List of file states
        {
            SPRITE_RING1 = 0,
            SPRITE_RING2,
            SPRITE_END
        };
        sprite_file currentSprite; //Filename of sprite in use

        SDL_Window* graphicsWindow; //The window
        SDL_Renderer* graphicsRenderer; //The renderer
        TTF_Font* globalFont; //The global font

        Timer capTimer; //Frames per second cap timer

        SpriteBank rings; //Collection of sprites
        Texture statstext; //Some statstext
        std::stringstream stats; //Stringsteam of statstext
        SDL_Color textColor{ 0x00, 0x00, 0x00 }; //Text color
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
