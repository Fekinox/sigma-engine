#include "spritebank.h"
#include "fmanage.h"

std::map<std::string, Sprite*> spriteList;

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

void SpriteBank::Init(SDL_Renderer* r)
{
    //Set renderer pointer to given renderer
    this->destrend = r;
}

void SpriteBank::Cleanup()
{
    if(spriteList.size() <= 0) return;

    for(auto& it : spriteList)
    {
        Sprite* TheSprite = (Sprite*)it.second;

        if(TheSprite)
        {
            delete TheSprite;
            TheSprite = NULL;
        }
    }

    spriteList.clear();
}

void SpriteBank::AddSprite(std::string filename,
                           int h,
                           int bbw,
                           int bbh,
                           int ox,
                           int oy,
                           int bbx,
                           int bby,
                           bool osc)
{
    //Get sprite name and id
    std::string ext = FileManager::GetFilenameExt(filename);
    std::string id = FileManager::GetFilenameWithoutExt(filename);

    //Create a pointer to a sprite object off the heap
    Sprite* newSprite = new Sprite();
    //Load the sprite//
    if(newSprite->Load(destrend, filename) == false)
    {
        return;
    }
    //Modify the sprite//

    //Set clipping height (also sets maxFrames)
    newSprite->SetClip(h);

    //Set bounding box
    newSprite->SetBoundingBox(bbx, bby, bbw, bbh);

    //Set origin
    newSprite->SetOrigin(ox, oy);

    //Set oscillation
    newSprite->SetOscillate(osc);

    //Map the id to the new sprite
    spriteList[id] = newSprite;
}

Sprite* SpriteBank::Get(std::string id)
{
    if(spriteList.find(id) == spriteList.end()) return 0;

    return spriteList[id];
}
