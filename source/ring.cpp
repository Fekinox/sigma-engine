#include "ring.hpp"

void	Ring_Input::SendInput( int k, bool state )
{
	switch(k)
	{
		case (int)Type::swit:
			state ?	k_swit.Press()	: k_swit.Release();
			break;
		case (int)Type::anim:
			state ?	k_anim.Press()	: k_anim.Release();
			break;
	}
}

void	Ring_Input::Update( Comp_Render& rend )
{
	//If k_swit was pressed
	if(k_swit.Pressed())
	{
		rend.Spr()->ResetFrame();
		rend.Spr((rend.Spr()->Name() == "ring1")	? 2 : 0);
	}

	//If k_anim was pressed
	if(k_anim.Pressed())
	{
		rend.Spr()->Animate(!rend.Spr()->Animate());
	}
}

bool	Ring::Init(SDL_Renderer* r)
{
	//If spritebank fails to initialize, exit
	if(rend.Init(r) == false) return false;

	//Create vector of filenames
	std::vector<std::string> files;
	
	//Create directory, then append filenames to that directory
	std::string dir = "media/img/ring/";
	files.push_back(dir + "ring1.png");
	files.push_back(dir + "ring2.png");
	files.push_back(dir + "ring3.png");

	//For each filename in files...
	int it = sprite_ring1;
	for(const auto& filename : files)
	{
		//Create a sprite for each
		switch(it)
		{
			case (int)sprite_ring1:
			{
				rend.spriteset.AddSprite(filename, it, 40, {20, 20});
				break;
			}
			case (int)sprite_ring2:
			{
				rend.spriteset.AddSprite(filename, it, 40, {20, 20});
				break;
			}
			case (int)sprite_ring3:
			{
				rend.spriteset.AddSprite(filename, it, 40, {20, 20});
			}
		}
		it++;
	}

	//Set bounding box
	bb.hbox.SetBB({0, 0, 40, 40});

	//Set currentSprite to the first sprite
	rend.Spr(sprite_ring1);
	return true;
}

void	Ring::Update()
{
	input.Update(rend);
}
