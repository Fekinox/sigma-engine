#ifndef __HITBOX_H__
#define __HITBOX_H__

#include <SDL2/SDL.h>

class BoundBox
{
	SDL_Rect bb;
public:
	BoundBox()						{	bb = {};				}

	void SetBB( SDL_Rect bound )	{	bb = bound;				}
	int BBTop( int y )				{	return y + bb.y;		}
	int BBBottom( int y )			{	return y + bb.y + bb.h;	}
	int BBLeft( int x )				{	return x + bb.x;		}	
	int BBRight( int x )			{	return x + bb.x + bb.w;	}
	int BBX()						{	return bb.x;			}
	int BBY()						{	return bb.y;			}
	int BBWidth()					{	return bb.w;			}
	int BBHeight()					{	return bb.h;			}
};

class BoundCircle
{
	int radius;
public:
	BoundCircle()
	{
		radius = 0;
	}

	void SetRadius( int rad)		{	radius = rad;			}
	int Radius()					{	return radius;			}
};

#endif //HITBOX_H
