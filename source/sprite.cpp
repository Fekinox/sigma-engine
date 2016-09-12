#include "sprite.hpp"
#include "fmanage.hpp"
#include "log.hpp"

/* ---------------- BASE ---------------- */

Sprite::Sprite()
{
	//Initialize values
	currentFrame = 0;
	maxFrames = 0;
	frameInc = 1;

	cliph = 0;

	pos = {};

	destrend = NULL;

	origin = d_origin = {};

	flip = SDL_FLIP_NONE;

	oscillate = false;

	animated = true;

	name = "";
}

void Sprite::free()
{
	//Unload texture, and reset pointers
	LOG("Unloading sprite " << (name != "" ? name : "NULL"));
	tex.free();
	cliph = 0;
}

bool Sprite::Load(SDL_Renderer* r, const std::string path)
{
	//Check the renderer
	if(r == NULL)
	{
		return false;
	}

	//Free current sprite
	free();

	//Set the renderer pointer to the given renderer
	this->destrend = r;

	if(!tex.Load(destrend, path))
	{
		LOG("Sprite texture failed to be created from " << path);
		return false;
	}

	name = FileManager::GetFilenameWithoutExt(path);

	//Clipping height is by default max height
	cliph = this->Height();

	//Max frames is by default 0

	//Origin position is by default 0, 0

	//Bounding box is by default 0

	//Oscillate is by default 0

	//Flip is by default neutral

	LOG("Loaded sprite " << name);

	return true;
}

void Sprite::OnAnimate()
{
	if (animated != false && maxFrames != 0) //If sprite is actually animatable
	{
		if (oscillate) //If oscillate flag is checked
		{
			if (frameInc > 0) //If frameInc goes up
			{
				if (currentFrame >= maxFrames) frameInc = -frameInc; //If the next increment takes it up to maxFrames
			}
			else
			{
				if (currentFrame <= 0) frameInc = -frameInc; //If the next decrement takes it below zero
			}
		}
		else
		{
			if (currentFrame >= maxFrames)
			{
				currentFrame = -1;
			}
		}
		currentFrame += frameInc;
	}
}

/* ---------------- SPRITE MODIFIERS ---------------- */

void Sprite::ResetFrame()
{
	CurrentFrame(0);
	frameInc = 1;
}

void Sprite::Clip(int h)
{
	cliph = h;
	//Set max frames equal to the amount of times cliph can fit on the texture. Minus one to account for the first frame***
	maxFrames = (this->SheetHeight() / cliph)-1;
}


void Sprite::Render(SDL_Point& loc)
{
	pos = loc;
	SDL_Rect src = {0, this->CurrentFrame()*cliph, this->Width(), cliph};
	SDL_Rect dest = {this->XaOrig(), this->YaOrig(), this->Width(), cliph};
	tex.Render(src, dest, ang, origin, flip);
	//Update animation
	OnAnimate();
}

void Sprite::Flip(SDL_RendererFlip state)
{
	switch(state)
	{
		case SDL_FLIP_NONE:
		{
			//Reset to default origin
			origin.x = d_origin.x;
			origin.y = d_origin.y;
			break;
		}
		case SDL_FLIP_HORIZONTAL:
		{
			//Flip the x origin
			origin.x = Width() - XOrig();
			origin.y = d_origin.y;
			break;
		}
		case SDL_FLIP_VERTICAL:
		{
			//Flip the y origin
			origin.y = Width() - YOrig();
			origin.x = d_origin.x;
			break;
		}
	}
	flip = state;
}
