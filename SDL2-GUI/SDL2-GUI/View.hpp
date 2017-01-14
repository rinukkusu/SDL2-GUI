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

#ifndef VIEW__HPP
#define VIEW__HPP

#define DEFAULT_FONT "Roboto-Medium.ttf"

#include <string>

#include <SDL.h>

#include <SDL_ttf.h>

namespace sdl2gui
{
	class View
	{
		protected:
		SDL_Renderer *sdlRenderer;
		SDL_Window *sdlWindow;
		TTF_Font *font;

		public:
		View(SDL_Window *sdlWindow);
		virtual void render() = 0;
		virtual SDL_Renderer * getSDLRenderer();
		virtual bool onSDLEvent(SDL_Event &sdlEvent) = 0;
		virtual TTF_Font * getFont();
		virtual int getSizeX();
		virtual int getSizeY();
	};
}

#endif
