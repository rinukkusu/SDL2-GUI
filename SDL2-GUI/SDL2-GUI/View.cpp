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

#include "View.hpp"

namespace sdl2gui
{
	View::View(SDL_Window *sdlWindow)
	{
		this->sdlWindow = sdlWindow;
		this->sdlRenderer = SDL_GetRenderer(this->sdlWindow);
		
		std::string *path = new std::string(SDL_GetBasePath());
		path->append(DEFAULT_FONT);

		this->font = TTF_OpenFont(path->c_str(), 16);
		if (this->font == NULL)
		{
			auto err = TTF_GetError();
			printf_s("Could not load font from %s.", path->c_str());
			printf_s(err);
			throw std::exception("Could not load font.");
		}
	}

	SDL_Renderer * View::getSDLRenderer()
	{
		return this->sdlRenderer;
	}

	TTF_Font * View::getFont()
	{
		return this->font;
	}

	int View::getSizeX()
	{
		int width, height;
		SDL_GetWindowSize(this->sdlWindow, &width, &height);
		return width;
	}

	int View::getSizeY()
	{
		int width, height;
		SDL_GetWindowSize(this->sdlWindow, &width, &height);
		return height;
	}
}
