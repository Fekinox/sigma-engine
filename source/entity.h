#include "spritebank.h"
#include <vector>

class Entity
{
    public:
        static std::vector<Entity*> entityList;
    protected:
        float x;
        float y;
        int w;
        int h;

        float bbx;
        float bby;
        int bbw;
        int bbh;

        double ang;
        SDL_Point origin;

        int currentFrame;

        SpriteBank sprites;
    public:
        Entity();

        virtual ~Entity();

        virtual bool onLoad();

        virtual void onLoop();

        virtual void onRender();

        virtual void onCleanup();
};
