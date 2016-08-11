#include "texture.h"

Texture::Texture()
{
    //Initialize
    mTexture = NULL;
    mWidth = 0;
    mHeight = 0;
    destrend = NULL;
    font = NULL;
}

Texture::~Texture()
{
    //Deallocate texture
    free();
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
        printf("Unable to load image!");
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(destrend, loadedSurface);
        if(mTexture == NULL)
        {
            printf("Unable to make texture!");
        }
        else
        {
            //Get image dimensions
            mWidth = loadedSurface->w;
            mHeight = loadedSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(loadedSurface);
    }

    //Return success
    return mTexture != NULL;
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
        printf("Unable to load image!");
    }
    else
    {
        //Create texture from surface pixels
        mTexture = SDL_CreateTextureFromSurface(destrend, textSurface);
        if(mTexture == NULL)
        {
            printf("Unable to make texture!");
        }
        else
        {
            //Get image dimensions
            mWidth = textSurface->w;
            mHeight = textSurface->h;
        }

        //Get rid of old loaded surface
        SDL_FreeSurface(textSurface);
    }

    //Return success
    return mTexture != NULL;
}

void Texture::free()
{
    //If texture exists
    if(mTexture != NULL)
    {
        SDL_DestroyTexture(mTexture);
        mTexture = NULL;
        mWidth = 0;
        mHeight = 0;
    }
}

void Texture::Render(int x, int y) //Basic render. Takes the default width and height.
{
    Render(x, y, mWidth, mHeight);
}

void Texture::Render(int x, int y, int w, int h) //Stretch render. Stretches rendered texture to the given size.
{
    SDL_Rect Destination = {x, y, w, h};

    SDL_RenderCopy(destrend, mTexture, NULL, &Destination);
}

void Texture::Render(int x, int y, int w, int h, int sx, int sy, int sw, int sh) //Clip render. Clips specific part of a texture, and stretches to the given size.
{
    SDL_Rect Source = {sx, sy, sw, sh};
    SDL_Rect Destination = {x, y, w, h};

    SDL_RenderCopy(destrend, mTexture, &Source, &Destination);
}

int Texture::GetWidth()
{
    return mWidth;
}
int Texture::GetHeight()
{
    return mHeight;
}
