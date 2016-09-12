#ifndef __COMMANDS_H__
#define __COMMANDS_H__

#include "ring.hpp"

//Purely virtual Command class. Just to refer to any Command.


struct Command
{
/*	typename		function name								function definition	*/
	virtual			~Command()									{}
};


//		KEYBOARD COMMANDS


struct KeyboardCommand	: public Command
{
	virtual			~KeyboardCommand()							{}
	virtual void	Press( Key_Input& i )						= 0;
	virtual void	Release( Key_Input& i )						= 0;
};

struct SwitchPress		: public KeyboardCommand
{
	void			Press( Key_Input& i )						{	i.SendInput(0, true);						}
	void			Release( Key_Input& i )						{	i.SendInput(0, false);						}
};


struct AnimPress		: public KeyboardCommand
{
	void			Press( Key_Input& i )						{	i.SendInput(1, true);						}
	void			Release( Key_Input& i )						{	i.SendInput(1, false);						}
};


//		MOUSE COMMANDS


struct ClickCommand		: public Command
{
	virtual			~ClickCommand()								{}
	virtual void	Press( Mouse_Input& i, SDL_Point& loc )		= 0;
	virtual void	Release( Mouse_Input& i, SDL_Point& loc )	= 0;
};

struct LeftMouse		: public ClickCommand
{
	void			Press( Mouse_Input& i, SDL_Point& loc)		{	i.SendInput(ClickType::left, loc, true);	}
	void			Release( Mouse_Input& i, SDL_Point& loc )	{	i.SendInput(ClickType::left, loc, false);	}
};

struct MiddleMouse		: public ClickCommand
{
	void			Press( Mouse_Input& i, SDL_Point& loc )		{	i.SendInput(ClickType::middle, loc, true);	}
	void			Release( Mouse_Input& i, SDL_Point& loc )	{	i.SendInput(ClickType::middle, loc, false);	}
};

struct RightMouse		: public ClickCommand
{
	void			Press( Mouse_Input& i, SDL_Point& loc )		{	i.SendInput(ClickType::right, loc, true);	}
	void			Release( Mouse_Input& i, SDL_Point& loc )	{	i.SendInput(ClickType::right, loc, false);	}
};





struct MouseMove
{
	void			Movement( Mouse_Input& i, SDL_Point& loc )	{	i.SendInput(loc);							}
};

#endif //COMMANDS_H
