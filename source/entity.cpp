#include "entity.h"
#include "fmanage.h"

std::vector<Entity*> Entity::entityList;

Entity::Entity()
{
    x = 0;
    y = 0;
    w = 0;
    h = 0;

    bbx = x;
    bby = y;
    bbw = w;
    bbh = h;

    ang = 0.0;
    origin.x = x;
    origin.y = y;

    currentFrame = 0;
}

Entity::~Entity()
{}

bool Entity::onLoad()
{return true;}

void Entity::onLoop()
{}

void Entity::onRender()
{}

void Entity::onCleanup()
{}
