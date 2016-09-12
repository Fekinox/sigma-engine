#ifndef	__COMPINPUT_H__
#define	__COMPINPUT_H__

#include <SDL2/SDL.h>

//EVENT HANDLING COMPONENTS

//A simple class to define a press.

class State
{
	bool			held;									//True once button is pressed. False once button is released.
	bool			pressed;								//True once its value is checked.
	bool			released;								//True once its value is checked.
public:
					State()									{	pressed = held = false;				}

	void			Press();
	void			Hold();
	void			Release();

	bool			Pressed();
	bool			Held();
	bool			Released();
};

class Base_Input
{
public:
	virtual 		~Base_Input()							{}
};

//An enumerated type for mouse buttons.

enum class ClickType
{ 
	left = 0,
	middle,
	right
};

//Base class for mouse input.
class Mouse_Input	: public Base_Input
{
public:
	State			lmouse,	mmouse,	rmouse;
	SDL_Point		pos;

	virtual			~Mouse_Input()							{}
	
	//Mouse click
	void			SendInput( ClickType c, SDL_Point loc, bool state );
	
	//Mouse movement
	void			SendInput( SDL_Point loc );
};

//Base class for keyboard input.
class Key_Input		: public Base_Input
{
public:
	virtual			~Key_Input()							{}

	virtual void	SendInput ( int k, bool state ) 		= 0;
};

#endif	//COMPINPUT_H
