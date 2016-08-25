#include "spritebank.h"
#include <vector>

class Entity
{
    public:
        static std::vector<Entity*> entityList;
    protected:
        int x;
        int y;
        int w;
        int h;

        int bbx;
        int bby;
        int bbw;
        int bbh;

        double ang;
        SDL_Point origin;

        int currentFrame;

        SpriteBank sprites;
    public:
        Entity();

        virtual ~Entity() = 0;

        virtual bool onLoad() = 0;

        virtual void onLoop() = 0;

        virtual void onRender() = 0;

        virtual void onCleanup() = 0;

    public:
        int X() { return x; }
        int Y() { return y; }
};
