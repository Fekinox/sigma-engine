#include "texture.h"

#include "log.h"

Texture::Texture()
{
    //Initialize
    tex = NULL;
    w = 0;
    h = 0;
    destrend = NULL;
    font = NULL;
}

bool Texture::Load(SDL_Renderer* r, std::string path)
{
    //Remove preexisting texture
    free();

    //Check the renderer
    if(r == NULL)
    {
        return false;
    }

    //Set the renderer pointer to the given renderer
    destrend = r;

    //The surface
    SDL_Surface* loadedSurface;

    //Load image at specified path
    loadedSurface = IMG_Load(path.c_str());
    if(loadedSurface == NULL)
    {
        LOG("Unable to load image " << path);
        return false;
    }
    else
    {
        //Create texture from surface pixels
        tex = SDL_CreateTextureFromSurface(destrend, loadedSurface);
        if(tex == NULL)
        {
            LOG("Unable to make texture");
            return false;
        }
        else
        {
            //  image dimensions
            w = loadedSurface->w;
            h = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    LOG("Created texture from " << path);
    return tex != NULL;
}

bool Texture::Load(SDL_Renderer* r, TTF_Font* f, std::string textureText, SDL_Color textColor)
{
    //Remove preexisting texture
    free();

    //Check renderer and font
    if(r == NULL)
    {
        return false;
    }

    if(f == NULL)
    {
        return false;
    }

    //Set pointers
    destrend = r;
    font = f;

    //The surface
    SDL_Surface* textSurface;

    //Render text surface
    textSurface = TTF_RenderText_Solid(font, textureText.c_str(), textColor);
    if(textSurface == NULL)
    {
        LOG("Unable to make text from " << textureText);
    }
    else
    {
        //Create texture from surface pixels
        tex = SDL_CreateTextureFromSurface(destrend, textSurface);
        if(tex == NULL)
        {
            LOG("Unable to make texture");
        }
        else
        {
            //Get image dimensions
            w = textSurface->w;
            h = textSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return tex != NULL;
}

void Texture::free()
{
    //If texture exists
    if(tex != NULL)
    {
        SDL_DestroyTexture(tex);
        tex = NULL;
        w = 0;
        h = 0;
    }
}

void Texture::Render(int x, int y) //Basic render. Takes the default width and height.
{
    Render(x, y, w, h);
}

void Texture::Render(int x, int y, int w, int h) //Stretch render. Stretches rendered texture to the given size.
{
    SDL_Rect Destination = {x, y, w, h};

    SDL_RenderCopy(destrend, tex, NULL, &Destination);
}

void Texture::Render(int x, int y, int w, int h, int sx, int sy, int sw, int sh) //Clip render. Clips specific part of a texture, and stretches to the given size.
{
    SDL_Rect Source = {sx, sy, sw, sh};
    SDL_Rect Destination = {x, y, w, h};

    SDL_RenderCopy(destrend, tex, &Source, &Destination);
}

void Texture::Render(int x, int y, int w, int h, int sx, int sy, int sw, int sh, double ang, SDL_Point orig, SDL_RendererFlip flip) //Super render. Adds angle, an actual origin, and flip.
{
    SDL_Rect Source = {sx, sy, sw, sh};
    SDL_Rect Destination = {x, y, w, h};

    SDL_RenderCopyEx(destrend, tex, &Source, &Destination, ang, &orig, flip);
}
