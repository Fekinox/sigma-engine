#include "sprite.h"

/* ---------------- BASE ---------------- */

Sprite::Sprite()
{
    //Initialize values
    currentFrame = -1;
    maxFrames = 0;
    frameInc = 1;
    oldTime = 0;

    cliph = 0;

    sx = 0;
    sy = 0;

    destrend = NULL;

    d_ox = 0;
    d_oy = 0;

    origin.x = d_ox;
    origin.y = d_oy;

    flip = SDL_FLIP_NONE;

    bb.x = 0;
    bb.y = 0;
    bb.w = 0;
    bb.h = 0;

    oscillate = false;
}

Sprite::~Sprite()
{
    this->free();
}

void Sprite::free()
{
    //Unload texture, and reset pointers
    tex.free();
    cliph = 0;
}

bool Sprite::Load(SDL_Renderer* r, std::string path)
{
    //Free preexisting texture
    tex.free();

    //Check the renderer
    if(r == NULL)
    {
        return false;
    }

    //Set the renderer pointer to the given renderer
    destrend = r;

    tex.Load(destrend, path);

    //Clipping height is by default max height
    cliph = this->Height();

    //Max frames is by default 0

    //Origin position is by default 0

    //Bounding box is by default 0

    //Oscillate is by default 0

    //Flip is by default neutral

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
    }
    currentFrame += frameInc;
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
            origin.x = d_ox;
            origin.y = d_oy;
            break;
        }
        case SDL_FLIP_HORIZONTAL:
        {
            //Flip the x origin
            origin.x = Width() - XOrig();
            break;
        }
        case SDL_FLIP_VERTICAL:
        {
            //Flip the y origin
            origin.y = Width() - YOrig();
            break;
        }
    }
    flip = state;
}

void Sprite::Origin(int x, int y)
{
    d_ox = x;
    d_oy = y;
    origin.x = d_ox;
    origin.y = d_oy;
}

void Sprite::Oscillate(bool osc)
{
    oscillate = osc;
}

/* ---------------- SPRITE VALUE FINDERS ---------------- */

int Sprite::CurrentFrame()
{
    return currentFrame;
}

int Sprite::X()
{
    return sx;
}

int Sprite::Y()
{
    return sy;
}

int Sprite::Width()
{
    return tex.Width();
}

int Sprite::Height()
{
    return cliph;
}

int Sprite::XOrigD()
{
    return d_ox;
}

int Sprite::YOrigD()
{
    return d_oy;
}

int Sprite::XOrig()
{
    return origin.x;
}

int Sprite::YOrig()
{
    return origin.y;
}

int Sprite::XaOrig()
{
    return sx - XOrig();
}

int Sprite::YaOrig()
{
    return sy - YOrig();
}

double Sprite::Angle()
{
    return ang;
}

SDL_RendererFlip Sprite::Flip()
{
    return flip;
}

int Sprite::BBTop()
{
    return YaOrig() + bb.y;
}

int Sprite::BBBottom()
{
    return YaOrig() + bb.y + bb.w;
}

int Sprite::BBLeft()
{
    return XaOrig() + bb.x;
}

int Sprite::BBRight()
{
    return XaOrig() + bb.x + bb.w;
}

int Sprite::BBWidth()
{
    return bb.w;
}
int Sprite::BBHeight()
{
    return bb.h;
}

int Sprite::SheetHeight()
{
    return tex.Height();
}
