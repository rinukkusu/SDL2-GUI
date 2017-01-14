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

#include "TickBox.hpp" 

namespace sdl2gui
{
	namespace component
	{
		TickBox::TickBox()
		{
			this->tickRectangle = new Rectangle(0, 0, 100, 100);
			this->textRectangle = new Rectangle(0, 0, 0, 0);
		}

		TickBox::TickBox(std::string *text)
		{
			if (text != NULL)
			{
				this->tickRectangle = new Rectangle(1, 1, 22, -2, true, true, true, true);
				this->textRectangle = new Rectangle(27, 1, -29, -2, true, true, true, true);
				this->textLabel = new TextLabel(text);
			}
			else
			{
				this->tickRectangle = new Rectangle(0, 0, 100, 100);
				this->textRectangle = new Rectangle(0, 0, 0, 0);
			}
		}

		void TickBox::setTicked(bool enabled)
		{
			this->ticked = enabled;
		}

		bool TickBox::getTicked()
		{
			return this->ticked;
		}

		void TickBox::render(View *parent, SDL_Rect &sdlRect)
		{
			this->Component::doBaseRendering(parent, sdlRect);

			this->tickSDLRectangle = &this->tickRectangle->toSDLRect(&sdlRect);
			this->textSDLRectangle = &this->textRectangle->toSDLRect(&sdlRect);
			if ((this->textSDLRectangle->w > 0) || (this->textSDLRectangle->h > 0))
			{
				SDL_RenderDrawRect(parent->getSDLRenderer(), this->textSDLRectangle);
				this->textLabel->render(parent, *this->textSDLRectangle);
			}

			SDL_RenderDrawRect(parent->getSDLRenderer(), this->tickSDLRectangle);
			if (this->ticked)
			{
				SDL_RenderDrawLine(parent->getSDLRenderer(), (this->tickSDLRectangle->x + 2), (this->tickSDLRectangle->y + 2), ((this->tickSDLRectangle->x + this->tickSDLRectangle->w) - 4), ((this->tickSDLRectangle->y + this->tickSDLRectangle->h) - 4));
				SDL_RenderDrawLine(parent->getSDLRenderer(), (this->tickSDLRectangle->x + 2), ((this->tickSDLRectangle->y + this->tickSDLRectangle->h) - 3), ((this->tickSDLRectangle->x + this->tickSDLRectangle->w) - 4), (this->tickSDLRectangle->y + 4));
			}
		}

		bool TickBox::onSDLEvent(SDL_Event &sdlEvent)
		{
			if (sdlEvent.type == SDL_EventType::SDL_MOUSEBUTTONDOWN)
			{
				this->ticked = !this->ticked;
				return true;
			}

			return false;
		}
	}
}
