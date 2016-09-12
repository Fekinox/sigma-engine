#ifndef __FONT_H__
#define __FONT_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <vector>
#include <string>
#include <iostream>
#include "log.hpp"

/*
Simple font wrapper.

(constructor)			Adds font to FontList.
(destructor)			Closes the hardware font.
Load()				  Loads the font, with font font and color col.
SetColor(col)		   Sets the font's color to col.
GetFont()			   Returns a pointer to the font.
GetColor()			  Returns the font's color.
*/

class Font
{
		//Hardware font
		TTF_Font* hwfont;

		//Color
		SDL_Color color;

	public:
		//constructor
		Font()
		{
			hwfont = nullptr;
			color = {};
			FontList.push_back(this);
		}

		//destructor
		~Font()	{ free(); }

		void free()
		{
			//If a font exists
			if(hwfont != nullptr)
			{
				//Close that font, and set pointers to NULL
				TTF_CloseFont(hwfont);
				LOG("Closing hardware font");
				hwfont = nullptr;
				color = {};
			}
		}

		bool Load(TTF_Font* font, SDL_Color col)
		{
			//Delete existing font
			free();

			//Add new font
			if(font == NULL) return false;
			else
			{
				hwfont = font;
				color = col;
			}

			return (font != NULL);
		}

		TTF_Font* GetFont() { return (hwfont ? hwfont : nullptr); }

		SDL_Color GetColor() { return color; }

		void SetColor(SDL_Color col) { color = col; }

		static std::vector<Font*> FontList;
};

#endif //FONT_H
