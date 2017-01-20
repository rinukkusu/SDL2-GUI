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

#include "../../include/components/NumberSpinner.hpp" 

namespace sdl2gui
{
	namespace component
	{
		NumberSpinner::NumberSpinner(int value, int step, int minimum, int maximum) : Component()
		{
			this->value = value;
			this->minimum = minimum;
			this->maximum = maximum;
			this->step = step;
			this->numberText = new std::string(std::to_string(value));
			this->numberTextLabel = new TextLabel(this->numberText);

			this->setValue(this->value);

			this->arrowUpRectangle = new Rectangle(-20, 0, 20, 50, true, false, true, false);
			this->arrowDownRectangle = new Rectangle(-20, 50, 20, 52, true, false, true, false);
			this->textRectangle = new Rectangle(1, 1, -21, -2, true, true, true, true);

			this->arrowUpTipPoint = new Point(50, 15);
			this->arrowUpBottomLeftPoint = new Point(25, 80);
			this->arrowUpBottomRightPoint = new Point(75, 80);

			this->arrowDownTopLeftPoint = new Point(25, 20);
			this->arrowDownTopRightPoint = new Point(75, 20);
			this->arrowDownTipPoint = new Point(50, 80);

			this->arrowUpPoints = new SDL_Point[4];
			this->arrowDownPoints = new SDL_Point[4];

			this->arrowDownSDLRectangle = new SDL_Rect();
			this->arrowUpSDLRectangle = new SDL_Rect();
		}

		void NumberSpinner::setValue(int value)
		{
			this->value = value;

			if (this->value < this->minimum)
				this->value = this->minimum;

			if (this->value > this->maximum)
				this->value = this->maximum;

			std::string *text = this->numberTextLabel->getText();
			text->clear();
			text->append(std::to_string(this->value));
			this->numberTextLabel->setText(text);
		}

		bool NumberSpinner::onSDLEvent(SDL_Event &sdlEvent)
		{
			if (sdlEvent.type == SDL_MOUSEBUTTONDOWN)
			{
				SDL_Point *clickPosition = new SDL_Point();
				clickPosition->x = sdlEvent.button.x;
				clickPosition->y = sdlEvent.button.y;
				
				if (SDL_PointInRect(clickPosition, this->arrowUpSDLRectangle))
				{
					this->setValue(this->value + this->step);
				}
				else if (SDL_PointInRect(clickPosition, this->arrowDownSDLRectangle))
				{
					this->setValue(this->value - this->step);
				}

				return true;
			}

			return false;
		}

		void NumberSpinner::render(View *parent, SDL_Rect &sdlRect)
		{
			this->doBaseRendering(parent, sdlRect);

			this->arrowDownSDLRectangle = &this->arrowDownRectangle->toSDLRect(&sdlRect);
			this->arrowUpSDLRectangle = &this->arrowUpRectangle->toSDLRect(&sdlRect);
			SDL_Rect textRectangle = this->textRectangle->toSDLRect(&sdlRect);

			SDL_RenderDrawRect(parent->getSDLRenderer(), this->arrowDownSDLRectangle);
			SDL_RenderDrawRect(parent->getSDLRenderer(), this->arrowUpSDLRectangle);
			SDL_RenderDrawRect(parent->getSDLRenderer(), &textRectangle);

			// Draw "arrow up" (a triangle pointing up)
			this->arrowUpPoints[0] = this->arrowUpTipPoint->toSDL_Point(arrowUpSDLRectangle);
			this->arrowUpPoints[1] = this->arrowUpBottomLeftPoint->toSDL_Point(arrowUpSDLRectangle);
			this->arrowUpPoints[2] = this->arrowUpBottomRightPoint->toSDL_Point(arrowUpSDLRectangle);
			this->arrowUpPoints[3] = this->arrowUpTipPoint->toSDL_Point(arrowUpSDLRectangle);
			SDL_RenderDrawLines(parent->getSDLRenderer(), this->arrowUpPoints, 4);

			// Draw "arrow down" (a triangle pointing down)
			this->arrowDownPoints[0] = this->arrowDownTopLeftPoint->toSDL_Point(arrowDownSDLRectangle);
			this->arrowDownPoints[1] = this->arrowDownTopRightPoint->toSDL_Point(arrowDownSDLRectangle);
			this->arrowDownPoints[2] = this->arrowDownTipPoint->toSDL_Point(arrowDownSDLRectangle);
			this->arrowDownPoints[3] = this->arrowDownTopLeftPoint->toSDL_Point(arrowDownSDLRectangle);
			SDL_RenderDrawLines(parent->getSDLRenderer(), this->arrowDownPoints, 4);

			this->numberTextLabel->render(parent, textRectangle);
		}
	}
}
