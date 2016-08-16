#include "spritebank.h"
#include "fmanage.h"

std::vector<Sprite*> spriteList;

SpriteBank::SpriteBank()
{
    //Initialize
    this->destrend = NULL;
}

SpriteBank::~SpriteBank()
{
    //Run deallocation function
    Cleanup();
}

bool SpriteBank::Init(SDL_Renderer* r)
{
    //Set renderer pointer to given renderer
    this->destrend = r;
    return true;
}

void SpriteBank::Cleanup()
{
    if(spriteList.size() <= 0) return;

    for(auto& sprite : spriteList)
    {
        delete sprite;
        sprite = NULL;
    }

    spriteList.clear();
}

void SpriteBank::AddSprite(const std::string& filename,
                           int id,
                           int h,
                           int bbw,
                           int bbh,
                           int ox,
                           int oy,
                           double ang,
                           SDL_RendererFlip flip,
                           int bbx,
                           int bby,
                           bool osc)
{
    //Get sprite name and id
    const auto& ext = FileManager::GetFilenameExt(filename);

    //Ignore non-png extensions
    if(ext != "png") return;
    else
    {
        //Create a pointer to a sprite object off the heap
        Sprite* newSprite = new Sprite();
        //Load the sprite//
        if(newSprite->Load(destrend, filename) == false) return;
        //Modify the sprite//

        //Set clipping height (also sets maxFrames)
        newSprite->Clip(h);

        //Set bounding box
        newSprite->BoundingBox(bbx, bby, bbw, bbh);

        //Set origin
        newSprite->Origin(ox, oy);

        //Set angle
        newSprite->SetAngle(ang);

        //Set flipstate
        newSprite->Flip(flip);

        //Set oscillation
        newSprite->Oscillate(osc);

        //Map the id to the new sprite
        spriteList.push_back(newSprite);
    }
}

Sprite* SpriteBank::Get(int id)
{
    if(spriteList[id] == NULL) return 0;

    return spriteList[id];
}
