#ifndef __SPRITEBANK_H__
#define __SPRITEBANK_H__

#include "sprite.h"

class SpriteBank
{
    private:
        SDL_Renderer* destrend;

    public:
        SpriteBank();

        ~SpriteBank();

        void Init(SDL_Renderer* r);

        void Cleanup();
    public:
        void AddSprite(std::string filename,
                       int h,
                       int bbw,
                       int bbh,
                       int ox = 0, //Origin is top left by default
                       int oy = 0,
                       int bbx = 0, //Bounding box's top left corner is sprite's top left by default
                       int bby = 0,
                       bool osc = false); //Oscillation is disabled by default
    public:
        Sprite* Get(std::string id);
};

#endif //SPRITEBANK_H
