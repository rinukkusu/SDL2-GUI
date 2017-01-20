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

#ifndef COMP_IMAGELABEL__HPP 
#define COMP_IMAGELABEL__HPP

#include <SDL_render.h>

#include "Component.hpp"

namespace sdl2gui
{
	namespace component
	{
		class ImageLabel : public Component
		{
			private:
			SDL_Texture *imageTexture;
			void render(View *parent, SDL_Rect &sdlRect);
			bool onSDLEvent(SDL_Event &sdlEvent);

			SDL_Rect *imageSourceRectangle;
			SDL_Rect *imageTargetRectangle;

			public:
			ImageLabel(SDL_Texture *imageTexture, SDL_Rect *imageSourceRectangle = NULL);
		};
	}
}

#endif
