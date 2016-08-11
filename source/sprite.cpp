#include "sprite.h"

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

    ox = sx;
    oy = sy;

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

void Sprite::OnAnimate()
{
    if (maxFrames != 0) //If sprite is actually animatable
    {
        if (oscillate) //If oscillate flag is checked
        {
            if (frameInc > 0) //If frameInc goes up
            {
                if (currentFrame >= maxFrames) //If the next increment takes it up to maxFrames
                {
                    frameInc = -frameInc;
                }
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

void Sprite::SetCurrentFrame(int Frame)
{
    currentFrame = Frame;
}

int Sprite::GetCurrentFrame()
{
    return currentFrame;
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
    cliph = this->GetHeight();

    //Max frames is by default 0

    //Origin position is by default 0

    //Bounding box is by default 0

    //Oscillate is by default 0

    return true;
}

void Sprite::SetClip(int h)
{
    cliph = h;
    //Set max frames equal to the amount of times cliph can fit on the texture. Minus one to account for the first frame***
    maxFrames = (this->GetSheetHeight() / cliph)-1;
}

void Sprite::Render(int x, int y)
{
    sx = x;
    sy = y;
    tex.Render(this->GetXaOrig(), this->GetYaOrig(), this->GetWidth(), cliph, 0, this->GetCurrentFrame()*cliph, this->GetWidth(), cliph);
}

void Sprite::SetBoundingBox(int x, int y, int w, int h)
{
    bb.x = x;
    bb.y = y;
    bb.w = w;
    bb.h = h;
}

void Sprite::SetOrigin(int x, int y)
{
    ox = x;
    oy = y;
}

void Sprite::SetOscillate(bool osc)
{
    oscillate = osc;
}

int Sprite::GetX()
{
    return sx;
}

int Sprite::GetY()
{
    return sy;
}

int Sprite::GetWidth()
{
    return tex.GetWidth();
}

int Sprite::GetHeight()
{
    return cliph;
}

int Sprite::GetXOrig()
{
    return ox;
}

int Sprite::GetYOrig()
{
    return oy;
}

int Sprite::GetXaOrig()
{
    return sx - ox;
}

int Sprite::GetYaOrig()
{
    return sy - oy;
}

int Sprite::BBTop()
{
    return GetYaOrig() + bb.y;
}

int Sprite::BBBottom()
{
    return GetYaOrig() + bb.y + bb.w;
}

int Sprite::BBLeft()
{
    return GetXaOrig() + bb.x;
}

int Sprite::BBRight()
{
    return GetXaOrig() + bb.x + bb.w;
}

int Sprite::BBWidth()
{
    return bb.w;
}
int Sprite::BBHeight()
{
    return bb.h;
}

int Sprite::GetSheetHeight()
{
    return tex.GetHeight();
}
