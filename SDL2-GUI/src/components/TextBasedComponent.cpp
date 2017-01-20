/*
 * SDL2-GUI - Make ugly GUIs, but with SDL.
 * Copyright (C) 2017 Shadow1Raven
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
**/

#include "../../include/components/TextBasedComponent.hpp"

namespace sdl2gui
{
	namespace component
	{
		TextBasedComponent::TextBasedComponent(std::string *text)
		{
			this->text = text;
			this->textColour = COLOUR_BLACK;
		}

		void TextBasedComponent::setText(std::string *text)
		{
			this->text = text;
			if (this->renderedText != NULL)
			{
				SDL_DestroyTexture(this->renderedText);
				this->renderedText = NULL;
			}
		}

		std::string * TextBasedComponent::getText()
		{
			return this->text;
		}

		void TextBasedComponent::setTextColour(SDL_Colour *textColour)
		{
			this->textColour = textColour;
			if (this->renderedText != NULL)
			{
				SDL_DestroyTexture(this->renderedText);
				this->renderedText = NULL;
			}
		}

		SDL_Colour * TextBasedComponent::getTextColour()
		{
			return this->textColour;
		}

		void TextBasedComponent::renderText(View *parent)
		{
			TTF_Font *font = parent->getFont();
			SDL_Renderer *sdlRenderer = parent->getSDLRenderer();
			SDL_Surface *sdlSurface = TTF_RenderUTF8_Blended(font, this->text->c_str(), *this->textColour);
			this->renderedText = SDL_CreateTextureFromSurface(sdlRenderer, sdlSurface);
		}

		SDL_Texture * TextBasedComponent::getRenderedText()
		{
			return this->renderedText;
		}

		TextBasedComponent::~TextBasedComponent()
		{
			if (this->renderedText != NULL)
			{
				SDL_DestroyTexture(this->renderedText);
				this->renderedText = NULL;
			}
		}
	}
}
