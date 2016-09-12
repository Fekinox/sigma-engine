#ifndef __MAIN_H__
#define __MAIN_H__

#include <vector>
#include <sstream>

#include "events.hpp"
#include "ring.hpp"
#include "timer.hpp"
#include "log.hpp"
#include "font.hpp"

constexpr int MS_PER_FRAME = 20; //Milliseconds per frame
constexpr int SCREEN_WIDTH = 800; //Screen width
constexpr int SCREEN_HEIGHT = 600; //Screen height

const int TIMEFRAME = 1000;

class App : public Event
{
	bool Running;														//Running flag

	Ring rings;

	SDL_Window* graphicsWindow;											//The window
    SDL_Renderer* graphicsRenderer;										//The renderer
    Font* gfont;

	Timer frameTicks, programTicks;										//Frames per second cap timer
	int programtime;													//updates at the end of every frame
	double fpsc = 0;													//Raw FPS
	double fpsp = 0;													//Highest attained FPS
	int pF = 0;															//Frames since program start
	int cF = 0;															//Frames since last FTILT check
	int FTILT = 0;														//Frames Tallied In Last Timeframe

	Texture statstext;													//Some statstext
	std::stringstream stats;

public:
	App();
	int OnExecute();													//When the program executes
public:
	void OnEvent(SDL_Event* e);											//When polling events
	void OnExit();														//When the program is exited
	void OnKeyPress(SDL_Keycode sym, Uint16 mod, Uint16 scancode);		//When a key is pressed
	void OnKeyRelease(SDL_Keycode sym, Uint16 mod, Uint16 scancode);	//When a key is released
public:
	bool OnInit();														//When the program starts
	void OnPreRender();													//Pre-rendering operations
	void OnRender();													//Rendering
	void OnPostRender();												//Post-rendering operations
	void OnCleanup();													//While cleaning up
		
	//Copy protection
	App(const App&)														= delete;
	void operator=(const App&)											= delete;
};

#endif //MAIN_H
