#include "events.h"

Event::Event() {}

Event::~Event() {}

void Event::OnEvent(SDL_Event* e)
{
	switch(e->type)
	{
		case SDL_WINDOWEVENT:
			{
				switch(e->window.event)
				{
					case SDL_WINDOWEVENT_ENTER:
						{
							OnMouseFocus();
							break;
						}
					case SDL_WINDOWEVENT_LEAVE:
						{
							OnMouseBlur();
							break;
						}
					case SDL_WINDOWEVENT_FOCUS_GAINED:
						{
							OnInputFocus();
							break;
						}
					case SDL_WINDOWEVENT_FOCUS_LOST:
						{
							OnInputBlur();
							break;
						}
					case SDL_WINDOWEVENT_SHOWN:
						{
							break;
						}
					case SDL_WINDOWEVENT_HIDDEN:
						{
							break;
						}
					case SDL_WINDOWEVENT_EXPOSED:
						{
							break;
						}
					case SDL_WINDOWEVENT_MOVED:
						{
							break;
						}
					case SDL_WINDOWEVENT_RESIZED:
						{
							OnWindowResized( e->window.data1, e->window.data2 );
							break;
						}
					case SDL_WINDOWEVENT_SIZE_CHANGED:
						{
							break;
						}
					case SDL_WINDOWEVENT_MINIMIZED:
						{
							break;
						}
					case SDL_WINDOWEVENT_MAXIMIZED:
						{
							break;
						}
					case SDL_WINDOWEVENT_RESTORED:
						{
							break;
						}
					case SDL_WINDOWEVENT_CLOSE:
						{
							break;
						}
				}
				break;
			}
		case SDL_QUIT:
			{
				OnExit();
				break;
			}
		case SDL_KEYDOWN:
			{
				OnKeyDown(e->key.keysym.sym,e->key.keysym.mod,e->key.keysym.scancode);
				break;
			}
		case SDL_KEYUP:
			{
				OnKeyUp(e->key.keysym.sym,e->key.keysym.mod,e->key.keysym.scancode);
				break;
			}
		case SDL_MOUSEMOTION:
			{
				OnMouseMove(e->motion.x, e->motion.y, e->motion.xrel, e->motion.yrel, (e->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT)) != 0, (e->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT)) != 0, (e->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE)) != 0);
				break;
			}
		case SDL_MOUSEBUTTONDOWN:
			{
				switch(e->button.button)
				{
					case SDL_BUTTON_LEFT:
						{
							OnLButtonDown(e->button.x, e->button.y);
							break;
						}
					case SDL_BUTTON_RIGHT:
						{
							OnRButtonDown(e->button.x, e->button.y);
							break;
						}
					case SDL_BUTTON_MIDDLE:
						{
							OnMButtonDown(e->button.x, e->button.y);
							break;
						}
				}
				break;
			}
		case SDL_MOUSEBUTTONUP:
			{
				switch(e->button.button)
				{
					case SDL_BUTTON_LEFT:
						{
							OnLButtonUp(e->button.x, e->button.y);
							break;
						}
					case SDL_BUTTON_RIGHT:
						{
							OnRButtonUp(e->button.x, e->button.y);
							break;
						}
					case SDL_BUTTON_MIDDLE:
						{
							OnMButtonUp(e->button.x, e->button.y);
							break;
						}
				}
				break;
			}

			//Star getting things from here man!
		case SDL_JOYAXISMOTION:
			{
				OnJoyAxis(e->jaxis.which, e->jaxis.axis, e->jaxis.value);
				break;
			}
		case SDL_JOYBALLMOTION:
			{
				OnJoyBall(e->jball.which, e->jball.ball, e->jball.xrel, e->jball.yrel);
				break;
			}
		case SDL_JOYHATMOTION:
			{
				OnJoyHat(e->jhat.which, e->jhat.hat, e->jhat.value);
				break;
			}
		case SDL_JOYBUTTONDOWN:
			{
				OnJoyButtonDown(e->jbutton.which, e->jbutton.button);
				break;
			}
		case SDL_JOYBUTTONUP:
			{
				OnJoyButtonUp(e->jbutton.which, e->jbutton.button);
				break;
			}
		default:
			{
				OnUser(e->user.type, e->user.code, e->user.data1, e->user.data2);
				break;
			}
	}
}

void Event::OnExit() {}

void Event::OnKeyDown( SDL_Keycode sym, Uint16 mod, Uint16 scancode )
{
	printf("keycode:%d\tmod:%d\tscancode:%d pressed!\n", sym, mod, scancode );
}

void Event::OnKeyUp( SDL_Keycode sym, Uint16 mod, Uint16 scancode )
{
	printf("keycode:%d\tmod:%d\tscancode:%d unpressed!\n", sym, mod, scancode );
}

void Event::OnMouseMove( int mx, int my, int relx, int rely, bool Left, bool Right, bool Middle )
{
	printf("x:%d\ty:%d\n", mx, my );
}

void Event::OnLButtonDown ( int mx, int my )
{
	printf("Left Click pressed in x:%d\ty:%d\n", mx, my);
}

void Event::OnLButtonUp ( int mx, int my )
{
	printf("Left Click unpressed in x:%d\ty:%d\n", mx, my);
}

void Event::OnRButtonDown ( int mx, int my )
{
	printf("Right Click pressed in x:%d\ty:%d\n", mx, my);
}

void Event::OnRButtonUp ( int mx, int my )
{
	printf("Right Click unpressed in x:%d\ty:%d\n", mx, my);
}

void Event::OnMButtonDown ( int mx, int my )
{
	printf("Middle Click pressed in x:%d\ty:%d\n", mx, my);
}

void Event::OnMButtonUp ( int mx, int my )
{
	printf("Middle Click unpressed in x:%d\ty:%d\n", mx, my);
}

void Event::OnMouseFocus()
{
	printf("Mouse entered the window!\n");
}

void Event::OnMouseBlur()
{
	printf("Mouse leaved the window!\n");
}

void Event::OnInputFocus()
{
	printf("Keyboard Focus the window!\n");
}

void Event::OnInputBlur()
{
	printf("Keyboar losed focus on the window!\n");
}

void Event::OnWindowResized( int data1, int data2 )
{
	printf( "Window Resized to: width:%d\theight:%d\n", data1, data2 );
}

void Event::OnJoyAxis(Uint8 which, Uint8 axis, Sint16 value){}

void Event::OnJoyBall(Uint8 which, Uint8 ball, Sint16 xrel, Sint16 yrel){}

void Event::OnJoyHat(Uint8 which, Uint8 hat, Uint8 button){}

void Event::OnJoyButtonDown(Uint8 which, Uint8 button){}

void Event::OnJoyButtonUp(Uint8 which, Uint8 button){}

void Event::OnUser(Uint8 type, int code, void* data1, void* data2){}
