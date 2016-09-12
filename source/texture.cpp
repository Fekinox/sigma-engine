/*
 * Texture wrapper
 *
 * Texture()								Initializes values.
 * ~Texture()								Alias to free()
 * Load(r, path)							Loads a texture to r from a file defined by path
 * Load(r, text, font)						Loads text texture to r from a string text and font font
 * free()									Deletes the texture and resets pointers
 * Render(x, y)								Renders the texture at regular x and y
 * Render(x, y, dest)						Renders the texture at regular x and y, and stretches it
 * Render(x, y, src, dest)					Renders part of the texture defined by source to a destination
 * Render(x, y, src, dest, ang, orig, flip)	Renders part of the texture defined by source to a destination, and modifies its angle, origin, and flip
*/
#include "texture.hpp"

#include "log.hpp"

Texture::Texture()
{
	//Initialize
	tex = nullptr;
	w = 0;
	h = 0;
	destrend = nullptr;
}

bool Texture::Load(SDL_Renderer* r, const std::string path)
{
	//Remove preexisting texture
	free();

	//Check the renderer
	if(r == nullptr)
	{
		return false;
	}

	//The surface
	SDL_Surface* loadedSurface;

	//Load image at specified path
	loadedSurface = IMG_Load(path.c_str());
	if(loadedSurface == nullptr)
	{
		LOG("Unable to load image " << path);
		return false;
	}
	else
	{
		//Set the renderer pointer to the given renderer
		destrend = r;

		//Create texture from surface pixels
		tex = SDL_CreateTextureFromSurface(destrend, loadedSurface);
		if(tex == NULL)
		{
			LOG("Unable to make texture");
			return false;
		}
		else
		{
			//  image dimensions
			w = loadedSurface->w;
			h = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	LOG("Created texture from " << path);
	return tex != nullptr;
}

bool Texture::Load(SDL_Renderer* r, const std::string textureText, Font& font)
{
	//Remove preexisting texture
	free();

	//Check renderer
	if(font.GetFont() == nullptr || r == nullptr)
	{
		return false;
	}

	//The surface
	SDL_Surface* textSurface;

	//Render text surface
	textSurface = TTF_RenderText_Solid(font.GetFont(), textureText.c_str(), font.GetColor());
	if(textSurface == nullptr)
	{
		LOG("Unable to make text from " << textureText);
	}
	else
	{
		//Set pointers
		destrend = r;

		//Create texture from surface pixels
		tex = SDL_CreateTextureFromSurface(destrend, textSurface);
		if(tex == nullptr)
		{
			LOG("Unable to make texture");
		}
		else
		{
			//Get image dimensions
			w = textSurface->w;
			h = textSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(textSurface);
	}

	//Return success
	return tex != nullptr;
}

void Texture::free()
{
	//If texture exists
	if(tex != nullptr)
	{
		SDL_DestroyTexture(tex);
		tex = nullptr;
		w = 0;
		h = 0;
	}
}

void Texture::Render(const int x, const int y) //Basic render. Takes the default width and height.
{
	SDL_Rect source = {x, y, w, h};
	Render(source);
}

void Texture::Render(const SDL_Rect dest)
{
	SDL_RenderCopy(destrend, tex, NULL, &dest);
}

void Texture::Render(const SDL_Rect src, const SDL_Rect dest)
{
	SDL_RenderCopy(destrend, tex, &src, &dest);
}

void Texture::Render(const SDL_Rect src, const SDL_Rect dest, const double ang, const SDL_Point orig, const SDL_RendererFlip flip)
{
	SDL_RenderCopyEx(destrend, tex, &src, &dest, ang, &orig, flip);
}
