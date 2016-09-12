#include "events.hpp"

Event::Event()
{
	//Default keybinds
	
	//Space maps to Switch
	k_space.reset(new SwitchPress);

	//Shift maps to Animation Toggle
	k_shift.reset(new AnimPress);
}

void Event::OnEvent(SDL_Event* e)
{
	switch(e->type)
	{
		//WINDOW EVENTS//
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

			//KEYBOARD EVENTS//

		case SDL_KEYDOWN:
			{
				OnKeyPress(e->key.keysym.sym,e->key.keysym.mod,e->key.keysym.scancode);
				break;
			}
		case SDL_KEYUP:
			{
				OnKeyRelease(e->key.keysym.sym,e->key.keysym.mod,e->key.keysym.scancode);
				break;
			}

			//MOUSE EVENTS//

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
							OnLButtonPress(e->button.x, e->button.y);
							break;
						}
					case SDL_BUTTON_RIGHT:
						{
							OnRButtonPress(e->button.x, e->button.y);
							break;
						}
					case SDL_BUTTON_MIDDLE:
						{
							OnMButtonPress(e->button.x, e->button.y);
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
							OnLButtonRelease(e->button.x, e->button.y);
							break;
						}
					case SDL_BUTTON_RIGHT:
						{
							OnRButtonRelease(e->button.x, e->button.y);
							break;
						}
					case SDL_BUTTON_MIDDLE:
						{
							OnMButtonRelease(e->button.x, e->button.y);
							break;
						}
				}
				break;
			}

			//CONTROLLER EVENTS//

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
				OnJoyButtonPress(e->jbutton.which, e->jbutton.button);
				break;
			}
		case SDL_JOYBUTTONUP:
			{
				OnJoyButtonRelease(e->jbutton.which, e->jbutton.button);
				break;
			}
		default:
			{
				OnUser(e->user.type, e->user.code, e->user.data1, e->user.data2);
				break;
			}
	}
}
