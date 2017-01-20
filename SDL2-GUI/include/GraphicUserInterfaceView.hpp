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

#ifndef IGRAPHICUSERINTERFACE__HPP
#define IGRAPHICUSERINTERFACE__HPP

#define COOLDOWN_DEF_TEXTINPUT 1

#include <map>
#include <vector>

#include "View.hpp"

#include "Rectangle.hpp"
#include "components/Container.hpp"

namespace sdl2gui
{
	class GraphicUserInterfaceView : public View
	{
		private:
		SDL_Rect *viewRectangle;
		sdl2gui::component::Container *contentContainer;
		std::map<SDL_EventType, unsigned int> *cooldowns;
		std::map<SDL_EventType, unsigned int> *lastEventTimestamps;

		public:
		void render();
		bool onSDLEvent(SDL_Event &sdlEvent);
		void addComponent(sdl2gui::component::IComponent *iComponent, sdl2gui::Rectangle *rectangle);
		void setEventCooldown(SDL_EventType SDL_EventType, unsigned int lastEventCooldown);
		GraphicUserInterfaceView(SDL_Window *sdlWindow);
	};
}

#endif
