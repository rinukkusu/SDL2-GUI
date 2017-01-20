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

#ifndef ICOMPONENT__HPP
#define ICOMPONENT__HPP

#include <SDL_rect.h>
#include <SDL_render.h>
#include <SDL_events.h>

#include "View.hpp"

namespace sdl2gui
{
	namespace component
	{
		class IComponent
		{
			public:
			virtual void render(View *parent, SDL_Rect &sdlRect) = 0;
			virtual void enableBorderDrawing(bool enable) = 0;

			virtual void setForegroundColour(SDL_Colour foregroundColour) = 0;
			virtual void setBackgroundColour(SDL_Colour backgroundColour) = 0;

			virtual SDL_Colour & getForegroundColour() = 0;
			virtual SDL_Colour & getBackgroundColour() = 0;

			virtual SDL_Rect & getCurrentRenderPosition() = 0;

			virtual bool onSDLEvent(SDL_Event &sdlEvent) = 0;
		};
	}
}

#endif
