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

#include "../include/Rectangle.hpp"

namespace sdl2gui
{
	Rectangle::Rectangle(int posX, int posY, int sizeX, int sizeY, bool absPosX, bool absPosY, bool absSizeX, bool absSizeY)
	{
		this->posX = posX;
		this->posY = posY;
		this->sizeX = sizeX;
		this->sizeY = sizeY;
		this->absPosX = absPosX;
		this->absPosY = absPosY;
		this->absSizeX = absSizeX;
		this->absSizeY = absSizeY;

		this->parentPositionX = 0;
		this->parentPositionY = 0;
		this->parentSizeX = 0;
		this->parentSizeY = 0;

		this->currentRect = new SDL_Rect();
		this->minimumRect = new SDL_Rect();
		this->maximumRect = new SDL_Rect();

		this->minimumRect->w = -1;
		this->minimumRect->h = -1;

		this->maximumRect->w = -1;
		this->maximumRect->h = -1;
	}

	void Rectangle::setMinimum(int sizeX, int sizeY)
	{
		this->minimumRect->w = sizeX;
		this->minimumRect->h = sizeY;
	}

	void Rectangle::setMaximum(int sizeX, int sizeY)
	{
		this->maximumRect->w = sizeX;
		this->maximumRect->h = sizeY;
	}

	SDL_Rect & Rectangle::toSDLRect(SDL_Rect *parent)
	{
		if ((parent->x == this->parentPositionX) && (parent->y == this->parentPositionY) && (parent->w == this->parentSizeX) && (parent->h == this->parentSizeY))
		{
			return (*this->currentRect);
		}

		int absPosX, absPosY, absSizeX, absSizeY;

		if (this->absPosX)
			absPosX = parent->x + this->posX;
		else
			absPosX = parent->x + ((int) ((this->posX / 100.0) * parent->w));

		if (this->posX < 0)
			absPosX += parent->w;

		if (this->absPosY)
			absPosY = parent->y + this->posY;
		else
			absPosY = parent->y + ((int) ((this->posY / 100.0) * parent->h));

		if (this->posY < 0)
			absPosY += parent->h;


		if (this->absSizeX)
			absSizeX = this->sizeX;
		else
			absSizeX = ((int) ((this->sizeX / 100.0) * parent->w));

		if (absSizeX < 0)
			absSizeX += parent->w;
		

		if (this->absSizeY)
			absSizeY = this->sizeY;
		else
			absSizeY = ((int) ((this->sizeY / 100.0) * parent->h));

		if (absSizeY < 0)
			absSizeY += parent->h;


		this->parentPositionX = parent->x;
		this->parentPositionY = parent->y;
		this->parentSizeX = parent->w;
		this->parentSizeY = parent->h;

		this->currentRect->x = absPosX;
		this->currentRect->y = absPosY;
		this->currentRect->w = absSizeX;
		this->currentRect->h = absSizeY;

		return (*this->currentRect);
	}
}
