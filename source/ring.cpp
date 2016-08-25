#include "ring.h"

Ring::Ring(float x, float y)
{
    //Initialize variables
    this->x = x;
    this->y = y;

    xvel = 0;
    yvel = 0;

    xacc = 0;
    yacc = 0;

    key_up = key_down = key_left = key_right = false;

    //Load sprites
    sprites.AddSprite("media/img/ring/ring1.png",
                      0,
                      40,
                      40,
                      40,
                      20,
                      20);
    sprites.AddSprite("media/img/ring/ring2.png",
                      1,
                      40,
                      40,
                      40,
                      20,
                      20);
    currentSprite = SPRITE_RING1;
}

Ring::~Ring()
{
    //Cleanup sprites
    sprites.Cleanup();
}

void Ring::Update()
{
    if(!(key_up && key_down))
    {
        key_up ? yacc = -1 : yacc = 0;
        key_down ? yacc = 1 : yacc = 0;
    }
    if(!(key_left && key_right))
    {
        key_left ? xacc = -1 : xacc = 0;
        key_right ? xacc = 1 : xacc = 0;
    }

    xvel += xacc;
    yvel += yacc;

    x += xvel;
    y += yvel;

    x = std::max(x, 0);
    x = std::min (x, SCREEN_WIDTH);

    y = std::max(y, 0);
    y = std::min(y, SCREEN_HEIGHT);
}
