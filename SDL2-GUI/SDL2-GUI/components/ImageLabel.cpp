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

#include "ImageLabel.hpp" 

namespace sdl2gui
{
	namespace component
	{
		ImageLabel::ImageLabel(SDL_Texture *imageTexture, SDL_Rect *imageSourceRectangle)
		{
			this->imageTexture = imageTexture;
			this->imageSourceRectangle = imageSourceRectangle;
			this->imageTargetRectangle = new SDL_Rect();
		}

		void ImageLabel::render(View *parent, SDL_Rect &sdlRect)
		{
			this->doBaseRendering(parent, sdlRect);

			this->imageTargetRectangle->x = sdlRect.x + 1;
			this->imageTargetRectangle->y = sdlRect.y + 1;
			this->imageTargetRectangle->w = sdlRect.w - 2;
			this->imageTargetRectangle->h = sdlRect.h - 2;

			SDL_RenderCopy(parent->getSDLRenderer(), this->imageTexture, this->imageSourceRectangle, this->imageTargetRectangle);
		}

		bool ImageLabel::onSDLEvent(SDL_Event &sdlEvent)
		{
			return true;
		}
	}
}
