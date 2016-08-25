#ifndef __MAIN_H__
#define __MAIN_H__

#include <vector>
#include <sstream>

#include "events.h"
#include "spritebank.h"
#include "timer.h"

#include <random>

const int FPS = 30; //Frames per second
const int SCREEN_WIDTH = 800; //Screen width
const int SCREEN_HEIGHT = 600; //Screen height

const int TIMEFRAME = 1000;

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
        Sprite* currentSprite; //Current sprite

        std::default_random_engine gen;

        SDL_Window* graphicsWindow; //The window
        SDL_Renderer* graphicsRenderer; //The renderer
        TTF_Font* globalFont; //The global font

        Timer capTimer, ticks; //Frames per second cap timer
        int timeTicks; //updates at the end of every frame
        double fpsc = 0; //Raw FPS
        double fpsp = 0; //Highest attained FPS
        int pF = 0; //Frames since program start
        int cF = 0; //Frames since last FTILT check
        int FTILT = 0; //Frames Tallied In Last Timeframe

        SpriteBank rings; //Collection of sprites
        Texture statstext, fpstext, peak_fpstext, stable_fpstext; //Some statstext
        std::stringstream stats, fps, peak_fps, stable_fps; //Stringsteam of statstext
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
        void OnPreRender(); //Pre-rendering operations
        void OnRender(); //Rendering
        int Random(int min, int max); //Random value
        void OnPostRender(); //When the program renders
        void OnCleanup(); //While cleaning up
};

#endif //MAIN_H
