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

#ifndef COMP_TICKBOX__HPP 
#define COMP_TICKBOX__HPP

#include <SDL_events.h>

#include "../Point.hpp"
#include "../Rectangle.hpp"
#include "Component.hpp"
#include "TextLabel.hpp"

namespace sdl2gui
{
	namespace component
	{
		class TickBox : public Component
		{
			private:
			bool ticked;

			Rectangle *tickRectangle;
			Rectangle *textRectangle;

			SDL_Rect *tickSDLRectangle;
			SDL_Rect *textSDLRectangle;

			TextLabel *textLabel;

			public:
			TickBox();
			TickBox(std::string *text);
			void setTicked(bool enabled);
			bool getTicked();
			void render(View *parent, SDL_Rect &sdlRect);
			bool onSDLEvent(SDL_Event &sdlEvent);
		};
	}
}

#endif
