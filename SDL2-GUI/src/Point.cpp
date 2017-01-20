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

#include "../include/Point.hpp" 

namespace sdl2gui
{
	Point::Point(int x, int y, bool absPosX, bool absPosY)
	{
		this->x = x;
		this->y = y;
		this->absPosX = absPosX;
		this->absPosY = absPosY;

		this->sdlPoint = new SDL_Point();

		this->parentPositionX = 0;
		this->parentPositionY = 0;
		this->parentSizeX = 0;
		this->parentSizeY = 0;
	}

	int Point::getX()
	{
		return this->x;
	}

	int Point::getY()
	{
		return this->y;
	}

	SDL_Point & Point::toSDL_Point(SDL_Rect *parent)
	{
		if ((parent->x == this->parentPositionX) && (parent->y == this->parentPositionY) && (parent->w == this->parentSizeX) && (parent->h == this->parentSizeY))
		{
			return *this->sdlPoint;
		}

		if (this->absPosX)
			this->sdlPoint->x = this->x;
		else
			this->sdlPoint->x = parent->x + ((int) ((this->x / 100.0) * parent->w));

		if (this->absPosY)
			this->sdlPoint->y = this->y;
		else
			this->sdlPoint->y = parent->y + ((int) ((this->y / 100.0) * parent->h));


		if (this->absPosX < 0)
			this->sdlPoint->x = parent->w + this->sdlPoint->x;

		if (this->absPosY < 0)
			this->sdlPoint->y = parent->h + this->sdlPoint->y;

		
		this->parentPositionX = parent->x;
		this->parentPositionY = parent->y;
		this->parentSizeX = parent->w;
		this->parentSizeY = parent->h;

		return *this->sdlPoint;
	}
}
