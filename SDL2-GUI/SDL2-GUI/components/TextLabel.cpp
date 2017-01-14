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

#include "TextLabel.hpp"

namespace sdl2gui
{
	namespace component
	{
		TextLabel::TextLabel(std::string *text) : TextBasedComponent(text)
		{
			this->renderedTextRect = new SDL_Rect();
		}

		void TextLabel::render(View *parent, SDL_Rect &sdlRect)
		{
			this->doBaseRendering(parent, sdlRect);

			if (this->getRenderedText() == NULL)
				this->renderText(parent);

			unsigned int format = 0;
			int access = 0;
			int width = 0;
			int height = 0;

			SDL_QueryTexture(this->getRenderedText(), &format, &access, &width, &height);

			this->renderedTextRect->x = (sdlRect.x + (sdlRect.w / 2)) - (width / 2);
			this->renderedTextRect->y = (sdlRect.y + (sdlRect.h / 2)) - (height / 2);
			this->renderedTextRect->w = width;
			this->renderedTextRect->h = height;

			SDL_RenderCopy(parent->getSDLRenderer(), this->getRenderedText(), 0, this->renderedTextRect);
		}

		TextLabel::~TextLabel()
		{
			TextBasedComponent::~TextBasedComponent();
		}
	}
}