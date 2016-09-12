#ifndef __RING_H__
#define __RING_H__

#include "compinput.hpp"
#include "comprender.hpp"
#include "compcollision.hpp"
#include <vector>
#include <string>

class Ring_Input	: public Key_Input
{
	enum class Type
	{
		swit = 0,
		anim
	};

public:
	State			k_swit,	k_anim;

	void			SendInput( int k, bool state );
	void			Update( Comp_Render& rend );
};

class Ring
{
	enum SpriteState
	{
		sprite_ring1,
		sprite_ring2,
		sprite_ring3,
		end
	};

	SDL_Point pos;

	Sprite*					Get()		{	return rend.Spr();							}

public:
	Ring_Input				input;
	Comp_Render 			rend;
	Comp_BoundBoxCollision	bb;

	Ring()
	{
		pos = {};
	}

	Ring(SDL_Point& xy) 					: pos(xy) {}

	Ring(SDL_Point& xy, SDL_Renderer* r)	: pos(xy)
	{
		Init(r);
	}	

	bool					Init(SDL_Renderer* r);

	void					Update();

	Comp_Render&			Rend()		{	return rend;								}

	Comp_BoundBoxCollision&	BB()		{	return bb;									}

	void					X(int x)	{	pos.x = x;									}
	void					Y(int y)	{	pos.y = y;									}

	int						BBTop()		{	return bb.hbox.BBTop(Get()->YaOrig());		}
	int						BBBottom()	{	return bb.hbox.BBBottom(Get()->YaOrig());	}
	int						BBLeft()	{	return bb.hbox.BBLeft(Get()->XaOrig());		}
	int						BBRight()	{	return bb.hbox.BBRight(Get()->XaOrig());	}

	void					Render()	{	rend.Render(pos);							}
};

#endif //RING_H
