#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <string>
#include <iostream>

//Texture wrapper
class Texture
{
    public:
        //Initializes variables
        Texture();

        //Deallocates memory
        ~Texture() { free(); }

        //Pointer to a renderer
        SDL_Renderer* destrend;

        //Pointer to a font
        TTF_Font* font;

        //Loads image at specified path, or by entered text
        bool Load(SDL_Renderer* destrend, std::string path);

        bool Load(SDL_Renderer* destrend, TTF_Font* font, std::string textureText, SDL_Color textColor);

        //Deallocates texture
        void free();

        //Renders texture at given point
        void Render(int x, int y);

        void Render(int x, int y, int w, int h);

        void Render(int x, int y, int w, int h, int sx, int sy, int sw, int sh);

        void Render(int x, int y, int w, int h, int sx, int sy, int sw, int sh, double ang, SDL_Point orig, SDL_RendererFlip flip);

        //Gets image dimensions
        int Width() { return w; }
        int Height() { return h; }
    private:
        //The actual hardware texture
        SDL_Texture* tex;
        //Image dimensions
        int w;
        int h;
};

#endif //TEXTURE_H
