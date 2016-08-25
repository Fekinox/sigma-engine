#include "sprite.h"
#include "fmanage.h"
#include "log.h"

/* ---------------- BASE ---------------- */

Sprite::Sprite()
{
    //Initialize values
    currentFrame = 0;
    maxFrames = 0;
    frameInc = 1;
    oldTime = 0;

    cliph = 0;

    sx = 0;
    sy = 0;

    destrend = NULL;

    d_origin.x = 0;
    d_origin.y = 0;

    origin.x = d_origin.x;
    origin.y = d_origin.y;

    flip = SDL_FLIP_NONE;

    bb.x = 0;
    bb.y = 0;
    bb.w = 0;
    bb.h = 0;

    oscillate = false;

    name = "";
}

void Sprite::free()
{
    //Unload texture, and reset pointers
    LOG("Unloading sprite " << name);
    tex.free();
    cliph = 0;
}

bool Sprite::Load(SDL_Renderer* r, std::string path)
{
    //Check the renderer
    if(r == NULL)
    {
        return false;
    }

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
    if (maxFrames != 0) //If sprite is actually animatable
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

void Sprite::CurrentFrame(int Frame)
{
    currentFrame = Frame;
}

void Sprite::ResetFrame()
{
    CurrentFrame(-1);
    frameInc = 1;
}

void Sprite::Clip(int h)
{
    cliph = h;
    //Set max frames equal to the amount of times cliph can fit on the texture. Minus one to account for the first frame***
    maxFrames = (this->SheetHeight() / cliph)-1;
}

void Sprite::Render(int x, int y)
{
    sx = x;
    sy = y;
    tex.Render(this->XaOrig(),
               this->YaOrig(),
               this->Width(),
               cliph,
               0,
               this->CurrentFrame()*cliph,
               this->Width(),
               cliph,
               ang,
               origin,
               flip);
    //Update animation
    OnAnimate();
}

void Sprite::BoundingBox(int x, int y, int w, int h)
{
    bb.x = x;
    bb.y = y;
    bb.w = w;
    bb.h = h;
}

void Sprite::SetAngle(double degrees)
{
    ang = degrees;
}

void Sprite::AddAngle(double degrees)
{
    ang += degrees;
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

void Sprite::Origin(int x, int y)
{
    d_origin.x = x;
    d_origin.y = y;
    origin.x = d_origin.x;
    origin.y = d_origin.y;
}

void Sprite::Oscillate(bool osc)
{
    oscillate = osc;
}
