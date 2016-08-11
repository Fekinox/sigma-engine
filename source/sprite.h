#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "texture.h"

class Sprite
{
    private:
        int currentFrame; //Current frame to render
        int frameInc; //Frame increment (use to skip frames)
        int maxFrames; //Maximum frames
        bool oscillate; //Choose whether to oscillate or not
    private:
        unsigned long oldTime; //Timer
    private:
        Texture tex; //Spritesheet texture
        int cliph; //Clipping cutoff height
        int sx; //Sprite's X coords
        int sy; //Sprite's Y coords
        SDL_Renderer* destrend; //Destination renderer
    private:
        int ox; //Sprite's origin X (X-distance from 0)
        int oy; //Sprite's origin Y (Y-distance from 0)
        SDL_Rect bb; //Bounding box.
    public:
        //Initializer
        Sprite();

        //Destroyer
        ~Sprite();

        //Frees sprite from memory
        void free();

        //Updates the current frame
        void OnAnimate();

    public:
        //Jumps to a frame
        void SetCurrentFrame(int Frame);
        //Gets current frame
        int GetCurrentFrame();
    public:
        //Loads a sprite (overloads the texture function)
        bool Load(SDL_Renderer* r, std::string path);
        //Renders the sprite to the screen
        void Render(int x, int y);
    public:
        //Sets bounding box coords. x and y are the displacement from 0.
        void SetBoundingBox(int x, int y, int w, int h);
        //Sets the origin (where objects are spawned)
        void SetOrigin(int x, int y);
        //Sets the clipping cutoff and changes maxFrames accordingly
        void SetClip(int h);
        //Enables or disables sprite oscillation (forward-reverse)
        void SetOscillate(bool osc);
    public:
        //Utility
        int GetX(); //Find sprite's literal x/y
        int GetY();
        int GetWidth(); //Find sprite's literal w/h
        int GetHeight();
        int GetXOrig(); //Return the sprite's internal origin
        int GetYOrig();
        int GetXaOrig(); //Return the sprite's literal x/y, modified by the origin
        int GetYaOrig();
        int BBTop(); //Find the lowest y of the BB
        int BBBottom(); //Find the highest y of the BB
        int BBLeft(); //Find the lowest X of the BB
        int BBRight(); //Find the highest X of the BB
        int BBWidth(); //Get the width of the BB
        int BBHeight(); //Get the height of the BB
        int GetSheetHeight(); //gets the height of the entire spritesheet
};

#endif //SPRITE_H
