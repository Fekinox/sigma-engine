#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "texture.hpp"

class Sprite
{
private:
	//BASE VALUES//
	int currentFrame;		//Current frame to render
	int frameInc;			//Frame increment (use to skip frames)
	int maxFrames;			//Maximum frames
	bool oscillate;			//Choose whether to oscillate or not
	bool animated;			//Toggle animation

	Texture tex;			//Spritesheet texture
	int cliph;				//Clipping cutoff height
	SDL_Point pos;
	SDL_Renderer* destrend;	//Destination renderer
	SDL_Point d_origin;
	SDL_Point origin;		//X distance from 0
	double ang;				//Angle
	SDL_RendererFlip flip;  //Flip state
	SDL_Rect bb;			//Bounding box
	std::string name;		//Name of the sprite
public:
	//BASE FUNCTIONS//

	//Constructor
	Sprite();
	//Destructor
	~Sprite(){ free(); }
	//Frees sprite from memory
	void free();
	//Updates the current frame
	void OnAnimate();
	//Loads a sprite (overloads the texture function)
	bool Load(SDL_Renderer* r, const std::string path);
	//Renders the sprite to the screen
	void Render(SDL_Point& loc);

	//MUTATOR FUNCTIONS//

	void SetAngle(const double deg)			{ ang = deg; }				//Sets the angle
	void AddAngle(const double deg)			{ ang += deg; }				//Adds degrees to angle
	void Origin(const SDL_Point& pt)		{ d_origin = origin = pt; }	//Sets origin
	void CurrentFrame(const int frame)		{ currentFrame = frame; };	//Sets current frame
	void Oscillate(const bool& osc)			{ oscillate = osc; }		//Toggles oscillation
	void Animate(const bool anim)			{ animated = anim; }		//Toggles animation

	//These are a bit more involved and are thus defined in sprite.cpp
	void Flip(const SDL_RendererFlip);
	void Clip(const int);
	void ResetFrame();

	//ACCESSOR FUNCTIONS//

	int X()					{ return pos.x; }					//Find sprite's literal x/y
	int Y()					{ return pos.y; }
	int Width()				{ return tex.Width(); }				//Find sprite's literal w/h
	int Height()			{ return cliph; }
	int XOrigD()			{ return d_origin.x; }				//Return the sprite's default origin value
	int YOrigD()			{ return d_origin.y; }
	int XOrig()				{ return origin.x; }				//Return the sprite's internal origin
	int YOrig()				{ return origin.y; } ;
	int XaOrig()			{ return pos.x - origin.x; }		//Return the sprite's literal x/y, modified by the origin
	int YaOrig()			{ return pos.y - origin.y; }
	double Angle()			{ return ang; }						//Return the angle
	SDL_RendererFlip Flip()	{ return flip; }					//Return the current flipstate
	int BBWidth()			{ return bb.w; }					//Return the width of the BB
	int BBHeight()			{ return bb.h; }					//Return the height of the BB
	int SheetHeight()		{ return tex.Height(); }			//Return the height of the entire spritesheet
	int CurrentFrame()		{ return currentFrame; }			//Return the current frame
	bool Oscillate()		{ return oscillate; }				//Return oscillation state
	bool Animate()			{ return animated; }				//Return animated state
	std::string Name()		{ return name; }					//Return the name
};

#endif //SPRITE_H
