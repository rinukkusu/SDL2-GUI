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

#ifndef RECTANGLE__HPP
#define RECTANGLE__HPP

#include "View.hpp"

#include <SDL_rect.h>

namespace sdl2gui
{
	class Rectangle
	{
		private:
		int posX;
		int posY;
		int sizeX;
		int sizeY;
		bool absPosX;
		bool absPosY;
		bool absSizeX;
		bool absSizeY;

		int parentPositionX;;
		int parentPositionY;
		int parentSizeX;
		int parentSizeY;

		SDL_Rect *currentRect;
		SDL_Rect *minimumRect;
		SDL_Rect *maximumRect;
		
		public:
		Rectangle(int posX, int posY, int sizeX, int sizeY, bool absPosX = false, bool absPosY = false, bool absSizeX = false, bool absSizeY = false);
		void setMinimum(int sizeX, int sizeY);
		void setMaximum(int sizeX, int sizeY);
		SDL_Rect & toSDLRect(SDL_Rect *parent);
	};
}

#endif
