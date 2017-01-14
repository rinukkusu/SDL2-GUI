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

#include "GraphicUserInterfaceView.hpp"

namespace sdl2gui
{
	GraphicUserInterfaceView::GraphicUserInterfaceView(SDL_Window *sdlWindow) : View(sdlWindow)
	{
		this->viewRectangle = new SDL_Rect();
		this->contentContainer = new sdl2gui::component::Container();
		this->cooldowns = new std::map<SDL_EventType, unsigned int>();
		this->lastEventTimestamps = new std::map<SDL_EventType, unsigned int>();

		this->cooldowns->insert(std::pair<SDL_EventType, unsigned int>(SDL_EventType::SDL_TEXTINPUT, COOLDOWN_DEF_TEXTINPUT));
		this->cooldowns->insert(std::pair<SDL_EventType, unsigned int>(SDL_EventType::SDL_KEYDOWN, COOLDOWN_DEF_TEXTINPUT));
		this->cooldowns->insert(std::pair<SDL_EventType, unsigned int>(SDL_EventType::SDL_MOUSEBUTTONDOWN, COOLDOWN_DEF_TEXTINPUT));
	}

	void GraphicUserInterfaceView::render()
	{
		SDL_GetWindowSize(this->sdlWindow, &this->viewRectangle->w, &this->viewRectangle->h);

		this->contentContainer->render(this, (*this->viewRectangle));
	}

	void GraphicUserInterfaceView::addComponent(sdl2gui::component::IComponent *iComponent, sdl2gui::Rectangle *rectangle)
	{
		this->contentContainer->addComponent(iComponent, rectangle);
	}

	void GraphicUserInterfaceView::setEventCooldown(SDL_EventType sdlEventType, unsigned int lastEventCooldown)
	{
		if (this->cooldowns->find(sdlEventType) != this->cooldowns->end())
			this->cooldowns->erase(sdlEventType);

		this->cooldowns->insert(std::pair<SDL_EventType, unsigned int>(sdlEventType, lastEventCooldown));
	}

	bool GraphicUserInterfaceView::onSDLEvent(SDL_Event &sdlEvent)
	{
		if ((this->cooldowns->find(((SDL_EventType) sdlEvent.type))) == (this->cooldowns->end()))
		{
			return this->contentContainer->onSDLEvent(sdlEvent);
		}
		else
		{
			unsigned int cooldown = this->cooldowns->at(((SDL_EventType) sdlEvent.type));
			unsigned int lastEventTimestamp = 0;
			if (this->lastEventTimestamps->find(((SDL_EventType) sdlEvent.type)) != this->lastEventTimestamps->end())
				lastEventTimestamp = this->lastEventTimestamps->at(((SDL_EventType) sdlEvent.type));

			if ((sdlEvent.common.timestamp - lastEventTimestamp) > cooldown)
			{
				this->lastEventTimestamps->erase(((SDL_EventType) sdlEvent.type));
				this->lastEventTimestamps->insert(std::pair<SDL_EventType, unsigned int>(((SDL_EventType) sdlEvent.type), sdlEvent.common.timestamp));
				return this->contentContainer->onSDLEvent(sdlEvent);
			}
			else
			{
				return true;
			}
		}
	}
}
