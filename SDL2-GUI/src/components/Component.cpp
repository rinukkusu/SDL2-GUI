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

#include "../../include/components/Component.hpp"

namespace sdl2gui
{
	namespace component
	{
		Component::Component()
		{
			this->currentRenderRect = SDL_Rect();
			this->backgroundColour = SDL_Colour(*COLOUR_WHITE);
			this->foregroundColour = SDL_Colour(*COLOUR_BLACK);
		}

		void Component::setForegroundColour(SDL_Colour foregroundColour)
		{
			this->foregroundColour = foregroundColour;
		}

		void Component::setBackgroundColour(SDL_Colour backgroundColour)
		{
			this->backgroundColour = backgroundColour;
		}

		void Component::doBaseRendering(View *parent, SDL_Rect &sdlRect)
		{
			this->currentRenderRect.x = sdlRect.x;
			this->currentRenderRect.y = sdlRect.y;
			this->currentRenderRect.w = sdlRect.w;
			this->currentRenderRect.h = sdlRect.h;

			SDL_SetRenderDrawColor(parent->getSDLRenderer(), this->getBackgroundColour().r, this->getBackgroundColour().g, this->getBackgroundColour().b, this->getBackgroundColour().a);
			SDL_RenderDrawRect(parent->getSDLRenderer(), &sdlRect);

			if (this->Component::renderBorder)
			{
				SDL_SetRenderDrawColor(parent->getSDLRenderer(), this->foregroundColour.r, this->foregroundColour.g, this->foregroundColour.b, this->foregroundColour.a);
				SDL_RenderDrawRect(parent->getSDLRenderer(), &sdlRect);
			}

			SDL_SetRenderDrawColor(parent->getSDLRenderer(), this->getForegroundColour().r, this->getForegroundColour().g, this->getForegroundColour().b, this->getForegroundColour().a);
		}

		bool Component::onSDLEvent(SDL_Event &sdlEvent)
		{
			return false;
		}

		void Component::enableBorderDrawing(bool enabled)
		{
			this->renderBorder = enabled;
		}

		SDL_Colour & Component::getForegroundColour()
		{
			return this->foregroundColour;
		}

		SDL_Colour & Component::getBackgroundColour()
		{
			return this->backgroundColour;
		}

		SDL_Rect & Component::getCurrentRenderPosition()
		{
			return this->currentRenderRect;
		}
	}
}
