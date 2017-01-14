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

#include "TextInput.hpp" 

namespace sdl2gui
{
	namespace component
	{
		TextInput::TextInput(std::string *text) : TextBasedComponent(text)
		{
			this->textRect = new SDL_Rect();
			this->textLengthLimit = -1;
			this->textTextureRect = new SDL_Rect();
			this->isMultiline = false;
		}

		bool TextInput::onSDLEvent(SDL_Event &sdlEvent)
		{
			if (sdlEvent.type == SDL_EventType::SDL_TEXTINPUT)
			{
				if (this->getText()->length() >= this->textLengthLimit)
					return true;

				SDL_TextInputEvent sdlTextInputEvent = sdlEvent.text;

				std::string *text = this->getText();
				text->append(sdlTextInputEvent.text);
				this->setText(text);

				return true;
			}
			else if (sdlEvent.type == SDL_KEYDOWN)
			{
				if (sdlEvent.key.keysym.scancode == SDL_SCANCODE_BACKSPACE)
				{
					std::string *text = this->getText();
					std::string substrText = text->substr(0, text->length() - 1);
					this->setText(new std::string(substrText));
					delete text;
				}

				if (this->isMultiline && (sdlEvent.key.keysym.scancode == SDL_SCANCODE_RETURN))
				{
					std::string *text = this->getText();
					text->append("\n");
					this->setText(text);
				}
			}

			return false;
		}

		void TextInput::setMultiline(bool isEnabled)
		{
			this->isMultiline = isEnabled;
		}

		bool TextInput::getIsMultiline()
		{
			return this->isMultiline;
		}

		void TextInput::setTextLengthLimit(int textLengthLimit)
		{
			this->textLengthLimit = textLengthLimit;
		}

		void TextInput::render(View *parent, SDL_Rect &sdlRect)
		{
			this->doBaseRendering(parent, sdlRect);

			if (this->getRenderedText() == NULL)
				this->renderText(parent);

			unsigned int format = 0;
			int access = 0;
			int textureWidth = 0;
			int textureHeight = 0;

			SDL_QueryTexture(this->getRenderedText(), &format, &access, &textureWidth, &textureHeight);

			this->textRect->x = sdlRect.x;
			this->textRect->y = sdlRect.y;

			if (sdlRect.w > textureWidth)
			{
				this->textRect->w = textureWidth;
				this->textTextureRect->x = 0;
				this->textTextureRect->w = textureWidth;
			}
			else
			{
				this->textRect->w = sdlRect.w;
				this->textTextureRect->x = textureWidth - sdlRect.w;
				this->textTextureRect->w = sdlRect.w;
			}

			if (sdlRect.h > textureHeight)
			{
				this->textRect->h = textureHeight;
				this->textTextureRect->y = 0;
				this->textTextureRect->h = textureHeight;
			}
			else
			{
				this->textRect->h = sdlRect.h;
				this->textTextureRect->y = textureHeight - sdlRect.h;
				this->textTextureRect->h = sdlRect.h;
			}

			SDL_RenderCopy(parent->getSDLRenderer(), this->getRenderedText(), this->textTextureRect, this->textRect);
		}
	}
}
