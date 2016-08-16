#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "texture.h"

class Sprite
{
    private:
        //BASE VALUES//
        int currentFrame;       //Current frame to render
        int frameInc;           //Frame increment (use to skip frames)
        int maxFrames;          //Maximum frames
        bool oscillate;         //Choose whether to oscillate or not
        unsigned long oldTime;  //Timer
        Texture tex;            //Spritesheet texture
        int cliph;              //Clipping cutoff height
        int sx;                 //Sprite's X coords
        int sy;                 //Sprite's Y coords
        SDL_Renderer* destrend; //Destination renderer
        int d_ox;               //Default values for origin
        int d_oy;
        SDL_Point origin;       //X distance from 0
        double ang;             //Angle
        SDL_RendererFlip flip;  //Flip state
        SDL_Rect bb;            //Bounding box.
    public:
        //BASE FUNCTIONS//

        //Initializer
        Sprite();
        //Destroyer
        ~Sprite();
        //Frees sprite from memory
        void free();
        //Updates the current frame
        void OnAnimate();
        //Loads a sprite (overloads the texture function)
        bool Load(SDL_Renderer* r, std::string path);
        //Renders the sprite to the screen
        void Render(int x, int y);

        //MODIFIER FUNCTIONS

        //Sets bounding box coords. x and y are the displacement from 0.
        void BoundingBox(int x, int y, int w, int h);
        //Sets the angle
        void SetAngle(double degrees);
        //Adds a value to the angle
        void AddAngle(double degrees);
        //Sets the flip
        void Flip(SDL_RendererFlip state);
        //Sets the origin (where objects are spawned)
        void Origin(int x, int y);
        //Sets the clipping cutoff and changes maxFrames accordingly
        void Clip(int h);
        //Jumps to a frame
        void CurrentFrame(int Frame);
        //Sets frame to 0
        void ResetFrame();
        //Enables or disables sprite oscillation (forward-reverse)
        void Oscillate(bool osc);

        //VALUE FINDER FUNCTIONS

        int X();                   //Find sprite's literal x/y
        int Y();
        int Width();               //Find sprite's literal w/h
        int Height();
        int XOrigD();              //Return the sprite's default origin value
        int YOrigD();
        int XOrig();               //Return the sprite's internal origin
        int YOrig();
        int XaOrig();              //Return the sprite's literal x/y, modified by the origin
        int YaOrig();
        double Angle();            //Return the angle
        SDL_RendererFlip Flip();   //Return the current flipstate
        int BBTop();               //Return the lowest y of the BB
        int BBBottom();            //Return the highest y of the BB
        int BBLeft();              //Return the lowest X of the BB
        int BBRight();             //Return the highest X of the BB
        int BBWidth();             //Return the width of the BB
        int BBHeight();            //Return the height of the BB
        int SheetHeight();         //Return the height of the entire spritesheet
        int CurrentFrame();        //Gets current frame
};

#endif //SPRITE_H
