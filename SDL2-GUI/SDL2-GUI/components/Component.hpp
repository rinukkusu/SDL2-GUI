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

#ifndef COMP_COMPONENT__HPP
#define COMP_COMPONENT__HPP

#include "../Colours.hpp"

#include "../IComponent.hpp"

namespace sdl2gui
{
	namespace component
	{
		class Component : public IComponent
		{
			protected:
			bool renderBorder;
			SDL_Rect currentRenderRect;
			SDL_Colour foregroundColour;
			SDL_Colour backgroundColour;

			public:
			Component();

			virtual bool onSDLEvent(SDL_Event &sdlEvent);

			void enableBorderDrawing(bool enable);
			void doBaseRendering(View *parent, SDL_Rect &sdlRect);

			void setForegroundColour(SDL_Colour foregroundColour);
			void setBackgroundColour(SDL_Colour backgroundColour);

			SDL_Colour & getForegroundColour();
			SDL_Colour & getBackgroundColour();

			SDL_Rect & getCurrentRenderPosition();
		};
	}
}

#endif
