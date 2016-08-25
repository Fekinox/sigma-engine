#ifndef __RING_H__
#define __RING_H__

#include "entity.h"

enum sprite_type
{
    SPRITE_RING1,
    SPRITE_RING2
};

class Ring : public Entity
{
    public:
        //Initialization
        Ring(float x, float y);

        //Cleanup
        ~Ring();

        //Update
        void Update();

        //Render
        void Render();

        //Key states
        bool key_up;
        bool key_down;
        bool key_left;
        bool key_right;
    private:
        SpriteBank sprites;

        sprite_type currentSprite;

        float xvel, yvel;

        float xacc, yacc;
};

#endif //RING_H
