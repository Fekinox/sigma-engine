#ifndef	__COMPRENDER_H__
#define	__COMPRENDER_H__

#include "spritebank.hpp"

class Base_Render
{
public:
	virtual			~Base_Render()							{}

	virtual void	Render(SDL_Point& pos)					= 0;
};

class Comp_Render : public Base_Render
{
protected:
	Sprite* 		currentSprite;
public:
	SpriteBank		spriteset;

	Comp_Render()
	{
		currentSprite = nullptr;
	}

	virtual bool	Init(SDL_Renderer* r)					{	return spriteset.Init(r);			}

	virtual			~Comp_Render() 							{	spriteset.Cleanup();				}

	void			Spr(int id)								{	currentSprite = spriteset.Get(id);	}
	Sprite*			Spr()									{	return currentSprite;				}

	void			Render(SDL_Point& pos)					{	currentSprite->Render(pos);			}
};

#endif	//COMPRENDER_H
