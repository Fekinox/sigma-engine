#include "compinput.hpp"

//STATE

void	State::Press()
{
	held		= true;					//Button is held.
	released	= !held;				//If it's held, then it's not released
}

void	State::Release()
{
	held		= false;				//Button is not held.
	pressed		= held;					//If it's not held, then it's not pressed
}

bool	State::Pressed()
{
	bool res	= held && !pressed;		//If it's held and not already pressed
	
	if(res)		pressed = true;			//If this result is true, pressed is true

	return res;							//Returns the result
}

bool	State::Held()
{
	return	held;						//Just returns held status.
}

bool	State::Released()
{
	bool res	= !held && !released;	//If it's not held, and not already released

	if(res)		released = true;		//If this result is true, released is true

	return		res;					//Returns the result
}

//MOUSE_INPUT

void	Mouse_Input::SendInput( ClickType c, SDL_Point loc, bool state )
{
	pos = loc;

	switch(c)
	{
		case ClickType::left:
			state ?	lmouse.Press()	: lmouse.Release();
			break;
		case ClickType::middle:
			state ?	mmouse.Press()	: mmouse.Release();
			break;
		case ClickType::right:
			state ?	rmouse.Press()	: rmouse.Release();
			break;
	}	
}

void	Mouse_Input::SendInput( SDL_Point loc )
{
	pos = loc;
}
