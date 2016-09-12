#ifndef __SPRITEBANK_H__
#define __SPRITEBANK_H__

#include "sprite.hpp"
#include <vector>

class SpriteBank
{
	private:
		SDL_Renderer* destrend;

		std::vector<Sprite*> spriteList;

		Sprite* errSprite;

	public:
		SpriteBank();

		~SpriteBank() { Cleanup(); }

		virtual bool Init( SDL_Renderer* );

		void Cleanup();
	public:
		void AddSprite(const std::string&, const int, const int, SDL_Point orig = {}, bool osc = false); //Origin is (0, 0), and Oscillation is set to false

		Sprite* MakeAndGet(const std::string&, const int, const int, SDL_Point orig = {}, bool osc = false);

		Sprite* Get(int id);
};

#endif //SPRITEBANK_H
