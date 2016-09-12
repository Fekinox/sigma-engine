#ifndef __FX_H__
#define __FX_H__

#include <SDL2/SDL.h>

class Fade
{
    public:
        static void FadeIn(SDL_Renderer* rend);
        static void FadeOut(SDL_Renderer* rend);
    private:
        static Uint8 a;
};

#endif //FX_H
