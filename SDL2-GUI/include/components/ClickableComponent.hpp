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

#ifndef COMP_CLICKABLECOMPONENT__HPP 
#define COMP_CLICKABLECOMPONENT__HPP

#include <random>
#include <vector>

#include <SDL_events.h>

#include "SDLEventHandler.hpp"

namespace sdl2gui
{
	namespace component
	{
		class ClickableComponent
		{
			private:
			std::vector<SDLEventHandler *> *eventHandlers;
			
			public:
			ClickableComponent();
			void addEventHandler(SDLEventHandler *sdlEventHandler);
			bool handleEvent(SDL_Event &sdlEvent);
		};
	}
}

#endif
