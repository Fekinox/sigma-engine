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
        SDL_Point d_origin;
        SDL_Point origin;       //X distance from 0
        double ang;             //Angle
        SDL_RendererFlip flip;  //Flip state
        SDL_Rect bb;            //Bounding box
        std::string name;       //Name of the sprite
    public:
        //BASE FUNCTIONS//

        //Initializer
        Sprite();
        //Destroyer
        ~Sprite() { free(); }
        //Frees sprite from memory
        void free();
        //Updates the current frame
        void OnAnimate();
        //Loads a sprite (overloads the texture function)
        bool Load(SDL_Renderer* r, std::string path);
        //Renders the sprite to the screen
        void Render(int x, int y);

        //MUTATOR FUNCTIONS

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

        //ACCESSOR FUNCTIONS

        int X() { return sx; }                              //Find sprite's literal x/y
        int Y() { return sy; }
        int Width() { return tex.Width(); }                 //Find sprite's literal w/h
        int Height() { return cliph; }
        int XOrigD() { return d_origin.x; }                       //Return the sprite's default origin value
        int YOrigD() { return d_origin.y; }
        int XOrig() { return origin.x; }                    //Return the sprite's internal origin
        int YOrig() { return origin.y; } ;
        int XaOrig() { return sx - origin.x; }              //Return the sprite's literal x/y, modified by the origin
        int YaOrig() { return sy - origin.y; }
        double Angle() { return ang; }                      //Return the angle
        SDL_RendererFlip Flip() { return flip; }            //Return the current flipstate
        int BBTop() { return YaOrig() + bb.y; }             //Return the lowest y of the BB
        int BBBottom() { return YaOrig() + bb.y + bb.w; }   //Return the highest y of the BB
        int BBLeft() { return XaOrig() + bb.x; }            //Return the lowest X of the BB
        int BBRight() { return YaOrig() + bb.y + bb.w; }    //Return the highest X of the BB
        int BBWidth() { return bb.w; }                      //Return the width of the BB
        int BBHeight() { return bb.h; }                     //Return the height of the BB
        int SheetHeight() { return tex.Height(); }          //Return the height of the entire spritesheet
        int CurrentFrame() { return currentFrame; }         //Return the current frame
        std::string Name() { return name; }                 //Return the name
};

#endif //SPRITE_H
