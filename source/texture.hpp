#ifndef __TEXTURE_H__
#define __TEXTURE_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string>
#include "font.hpp"

//Texture wrapper
class Texture
{
	public:
		//Initializes variables
		Texture();

		//Deallocates memory
		~Texture() { free(); }

		//Pointer to a renderer
		SDL_Renderer* destrend;

		//Loads image at specified path, or by entered text
		bool Load(SDL_Renderer* destrend, const std::string path);

		bool Load(SDL_Renderer* destrend, const std::string textureText, Font& font);

		//Deallocates texture
		void free();

		//Renders texture at given point
		void Render(const int x, const int y);

		void Render(const SDL_Rect dest);

		void Render(const SDL_Rect src, const SDL_Rect dest);

		void Render(const SDL_Rect src, const SDL_Rect dest, const double, const SDL_Point, SDL_RendererFlip = SDL_FLIP_NONE);

		//Gets image dimensions
		int Width() { return w; }
		int Height() { return h; }
	private:
		//The actual hardware texture
		SDL_Texture* tex;
		//Image dimensions
		int w;
		int h;
};

#endif //TEXTURE_H
