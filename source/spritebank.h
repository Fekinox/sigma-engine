#ifndef __SPRITEBANK_H__
#define __SPRITEBANK_H__

#include "sprite.h"
#include <vector>

class SpriteBank
{
    private:
        SDL_Renderer* destrend;

        std::vector<Sprite*> spriteList;

        Sprite* errSprite;

    public:
        SpriteBank();

        ~SpriteBank() { Cleanup(); }

        bool Init(SDL_Renderer* r);

        void Cleanup();
    public:
        void AddSprite(const std::string& filename,
                       int id,
                       int h,
                       int bbw,
                       int bbh,
                       int ox = 0, //Origin is top left by default
                       int oy = 0,
                       int bbx = 0, //Bounding box's top left corner is sprite's top left by default
                       int bby = 0,
                       double ang = 0.0,
                       SDL_RendererFlip flip = SDL_FLIP_NONE,
                       bool osc = false); //Oscillation is disabled by default

        Sprite* MakeAndGet(const std::string& filename, int id, int h, int bbw, int bbh, int ox = 0, int oy = 0, int bbx = 0, int bby = 0, double ang = 0.0, SDL_RendererFlip flip = SDL_FLIP_NONE, bool osc = false);

        Sprite* Get(int id);
};

#endif //SPRITEBANK_H
