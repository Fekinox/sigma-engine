#include "spritebank.hpp"
#include "fmanage.hpp"
#include "log.hpp"

SpriteBank::SpriteBank()
{
	//Initialize
	this->destrend = NULL;
}

bool SpriteBank::Init(SDL_Renderer* r)
{
	//Set renderer pointer to given renderer
	this->destrend = r;
	LOG("Spritebank created");
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

void SpriteBank::AddSprite(const std::string& filename, int id, int h, SDL_Point orig, bool osc)
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
		if(newSprite->Load(destrend, filename) == false)
		{
			LOG("Sprite " << filename << " not found.");
			return;
		}
		//Modify the sprite//

		//Set clipping height (also sets maxFrames)
		newSprite->Clip(h);

		//Set origin
		newSprite->Origin(orig);

		//Set oscillation
		newSprite->Oscillate(osc);

		//Map the id to the new sprite
		spriteList.push_back(newSprite);
	}
}

Sprite* SpriteBank::Get(int id)
{
	if(spriteList[id] == NULL)
	{
		LOG("Sprite " << id << " does not exist.");
		return 0;
	}

	LOG("Getting sprite " << spriteList[id]->Name());

	return spriteList[id];
}

Sprite* SpriteBank::MakeAndGet(const std::string& filename, int id, int h, SDL_Point orig, bool osc)
{
	AddSprite(filename, id, h, orig, osc);
	return Get(id);
}
