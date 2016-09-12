#ifndef __EVENTS_H__
#define __EVENTS_H__

#include <SDL2/SDL.h>
#include <memory>

#include "commands.hpp"

class Event
{
protected:
	std::unique_ptr<KeyboardCommand>	k_space;
	std::unique_ptr<KeyboardCommand> 	k_shift;
public:
	Event();

	//Overload these events at any time

	virtual 		~Event() {}

	virtual void	OnEvent(SDL_Event* e);

	virtual void	OnExit() {}

	virtual void	OnKeyPress( SDL_Keycode sym, Uint16 mod, Uint16 scancode ) {}

	virtual void	OnKeyRelease( SDL_Keycode sym, Uint16 mod, Uint16 scancode ) {}

	virtual void	OnMouseMove( int mx, int my, int relx, int rely, bool Left, bool Right, bool Middle ) {}

	virtual void	OnLButtonPress ( int mx, int my ) {}

	virtual void	OnLButtonRelease ( int mx, int my ) {}

	virtual void	OnRButtonPress ( int mx, int my ) {}

	virtual void	OnRButtonRelease ( int mx, int my ) {}

	virtual void	OnMButtonPress ( int mx, int my ) {}

	virtual void	OnMButtonRelease ( int mx, int my ) {}

	virtual void	OnMouseFocus() {}

	virtual void	OnMouseBlur() {}

	virtual void	OnInputFocus() {}

	virtual void	OnInputBlur() {}

	virtual void	OnWindowResized( int data1, int data2 ) {}

	virtual void	OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value) {}

	virtual void 	OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel) {}

	virtual void	OnJoyHat(Uint8 which, Uint8 hat, Uint8 button) {}

	virtual void	OnJoyButtonPress(Uint8 which, Uint8 button) {}

	virtual void	OnJoyButtonRelease(Uint8 which, Uint8 button) {}

	virtual void	OnUser(Uint8 type, int code, void* data1, void* data2) {}
};

#endif //__EVENTS_H__
