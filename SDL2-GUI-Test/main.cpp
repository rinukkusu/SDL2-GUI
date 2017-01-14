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

#include <ctime>

#include <SDL.h>

#include "Colours.hpp"

#include <View.hpp>
#include <GraphicUserInterfaceView.hpp>

#include <components/SDLEventHandler.hpp>

#include <components/Button.hpp>
#include <components/TextLabel.hpp>
#include <components/ClickableComponent.hpp>
#include <components/TextInput.hpp>
#include <components/NumberSpinner.hpp>
#include <components/ImageLabel.hpp>
#include <components/TickBox.hpp>

unsigned int setToNull(unsigned int interval, void *parameters)
{
	void **params = ((void **) parameters);
	int *renderedFramesArray = ((int *) *params);

	renderedFramesArray[1] = renderedFramesArray[0];
	renderedFramesArray[0] = 0;

	renderedFramesArray[2] = 0;

	return 1000;
}

class EventHandler : public sdl2gui::component::SDLEventHandler
{
	bool SDLEventHandler::handleEvent(SDL_Event &sdlEvent)
	{
		if (sdlEvent.button.button == SDL_BUTTON_LEFT)
		{
			printf("Hallo\r\n");
			return true;
		}
		else
		{
			return false;
		}
	}
};

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	TTF_Init();

	SDL_Window *sdlWindow;
	SDL_Renderer *sdlRenderer;

	SDL_CreateWindowAndRenderer(320, 240, SDL_WINDOW_RESIZABLE, &sdlWindow, &sdlRenderer);

	SDL_Surface *img = SDL_LoadBMP("img.bmp");
	SDL_Texture *imageTexture = SDL_CreateTextureFromSurface(sdlRenderer, img);
	SDL_FreeSurface(img);

	auto button = new sdl2gui::component::Button(new std::string("Hallo"));
	button->enableBorderDrawing(true);
	auto buttonRectangle = new sdl2gui::Rectangle(5, 5, 30, 30, false, false, false, false);

	EventHandler *eventHandler = new EventHandler();
	button->addEventHandler(eventHandler);

	std::string *labelString = new std::string("FPS");
	char *labelCharArray = new char[3];
	auto textLabel = new sdl2gui::component::TextLabel(labelString);
	textLabel->enableBorderDrawing(true);
	auto textLabelRectangle = new sdl2gui::Rectangle(-50, 0, 50, 25, true, true, true, true);
	
	auto textInput = new sdl2gui::component::TextInput(new std::string());
	textInput->enableBorderDrawing(true);
	auto textInputRectangle = new sdl2gui::Rectangle(50, 50, 40, 40, false, false, false, false);

	auto numberSpinner = new sdl2gui::component::NumberSpinner();
	numberSpinner->enableBorderDrawing(true);
	auto numberSpinnerRectangle = new sdl2gui::Rectangle(10, 10, 30, 25, false, true, false, true);

	auto imageLabel = new sdl2gui::component::ImageLabel(imageTexture);
	imageLabel->enableBorderDrawing(true);
	auto imageLabelRectangle = new sdl2gui::Rectangle(10, 40, 64, 64, false, true, true, true);

	auto withTextTickBox = new sdl2gui::component::TickBox(labelString);
	withTextTickBox->Component::enableBorderDrawing(true);
	auto withTextTickBoxRectangle = new sdl2gui::Rectangle(10, 114, 64, 25, false, true, true, true);

	auto withoutTextTickBox = new sdl2gui::component::TickBox();
	withoutTextTickBox->Component::enableBorderDrawing(true);
	auto withoutTextTickBoxRectangle = new sdl2gui::Rectangle(10, 188, 24, 24, false, true, true, true);

	auto view = new sdl2gui::GraphicUserInterfaceView(sdlWindow);
	view->addComponent(button, buttonRectangle);
	view->addComponent(textLabel, textLabelRectangle);
	view->addComponent(textInput, textInputRectangle);
	view->addComponent(numberSpinner, numberSpinnerRectangle);
	view->addComponent(imageLabel, imageLabelRectangle);
	view->addComponent(withTextTickBox, withTextTickBoxRectangle);
	view->addComponent(withoutTextTickBox, withoutTextTickBoxRectangle);

	int *renderedFramesArray = new int[3] {0};
	
	SDL_AddTimer(1000, setToNull, &renderedFramesArray);

	SDL_Event sdlEvent;
	while (true)
	{
		SDL_SetRenderDrawColor(sdlRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
		SDL_RenderClear(sdlRenderer);
		view->render();
		SDL_RenderPresent(sdlRenderer);

		SDL_PollEvent(&sdlEvent);
		view->onSDLEvent(sdlEvent);

		renderedFramesArray[0]++;

		labelString->clear();
		SDL_itoa(renderedFramesArray[1], labelCharArray, 10);
		labelString->append(labelCharArray);
		textLabel->setText(labelString);
	}

	return 0;
}
