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

#ifndef COMP_TEXTINPUT__HPP 
#define COMP_TEXTINPUT__HPP

#include <string>

#include <SDL_events.h>
#include <SDL_keycode.h>

#include "Component.hpp"
#include "TextBasedComponent.hpp"

namespace sdl2gui
{
	namespace component
	{
		class TextInput : public Component, public TextBasedComponent
		{
			private:
			SDL_Rect *textRect;
			SDL_Rect *textTextureRect;
			int textLengthLimit;
			bool isMultiline;

			public:
			TextInput(std::string *text);
			bool onSDLEvent(SDL_Event &sdlEvent);
			void setTextLengthLimit(int textLengthLimit);
			void setMultiline(bool isEnabled);
			bool getIsMultiline();
			void render(View *parent, SDL_Rect &sdlRect);
		};
	}
}

#endif
