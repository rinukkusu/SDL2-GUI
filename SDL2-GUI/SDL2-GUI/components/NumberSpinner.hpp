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

#ifndef COMP_NUMBERSPINNER__HPP
#define COMP_NUMBERSPINNER__HPP

#include <limits>

#include "../Point.hpp"
#include "../Rectangle.hpp"
#include "Component.hpp"
#include "TextLabel.hpp"

namespace sdl2gui
{
	namespace component
	{
		class NumberSpinner : public Component
		{
			private:
			int value;
			int minimum;
			int maximum;
			int step;
			std::string *numberText;

			Rectangle *arrowUpRectangle;
			Rectangle *arrowDownRectangle;
			Rectangle *textRectangle;

			Point *arrowUpTipPoint;
			Point *arrowUpBottomLeftPoint;
			Point *arrowUpBottomRightPoint;

			Point *arrowDownTipPoint;
			Point *arrowDownTopLeftPoint;
			Point *arrowDownTopRightPoint;

			SDL_Point *arrowUpPoints;
			SDL_Point *arrowDownPoints;

			SDL_Rect *arrowDownSDLRectangle;
			SDL_Rect *arrowUpSDLRectangle;

			TextLabel *numberTextLabel;

			public:
			NumberSpinner(int value = 0, int step = 1, int minimum = std::numeric_limits<int>().min(), int maximum = std::numeric_limits<int>().max());
			void render(View *parent, SDL_Rect &sdlRect);
			bool onSDLEvent(SDL_Event &sdlEvent);
			void setValue(int value);
		};
	}
}

#endif
