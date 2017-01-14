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

#include "Container.hpp"

namespace sdl2gui
{
	namespace component
	{
		Container::Container()
		{
			this->components = new std::map<sdl2gui::component::IComponent *, Rectangle *>();
		}

		void Container::render(View *parent, SDL_Rect &sdlRect)
		{
			this->doBaseRendering(parent, sdlRect);

			auto iComponents = this->components->begin();
			auto iEnd = this->components->end();

			sdl2gui::component::IComponent *iComponent;
			Rectangle *rectangle;
			SDL_Rect componentRectangle;

			for (; iComponents != iEnd; iComponents++)
			{
				iComponent = iComponents->first;
				rectangle = iComponents->second;
				componentRectangle = rectangle->toSDLRect(&sdlRect);

				iComponent->render(parent, componentRectangle);
			}
		}

		void Container::addComponent(sdl2gui::component::IComponent *iComponent, sdl2gui::Rectangle *rectangle)
		{
			this->components->insert(std::pair<sdl2gui::component::IComponent *, sdl2gui::Rectangle *>(iComponent, rectangle));
		}

		bool Container::onSDLEvent(SDL_Event &sdlEvent)
		{
			auto iComponents = this->components->begin();
			auto iEnd = this->components->end();

			sdl2gui::component::IComponent *iComponent;
			Rectangle *rectangle;
			SDL_Rect componentRectangle;

			bool result = false;
			SDL_Point sdlPoint = SDL_Point();
			SDL_Rect currentRenderPosition;
			for (; iComponents != iEnd; iComponents++)
			{
				iComponent = iComponents->first;
				
				if ((sdlEvent.type == SDL_MOUSEBUTTONDOWN) || (sdlEvent.type == SDL_MOUSEBUTTONUP) || (sdlEvent.type == SDL_MOUSEMOTION))
				{
					sdlPoint.x = sdlEvent.button.x;
					sdlPoint.y = sdlEvent.button.y;
					currentRenderPosition = iComponent->getCurrentRenderPosition();
					if (SDL_PointInRect(&sdlPoint, &currentRenderPosition))
					{
						result = iComponent->onSDLEvent(sdlEvent);
						break;
					}
				}
				else
				{
					result |= iComponent->onSDLEvent(sdlEvent);
				}
			}

			return result;
		}
	}
}
