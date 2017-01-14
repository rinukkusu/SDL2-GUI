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

#ifndef COMP_COLOURS__HPP
#define COMP_COLOURS__HPP

#include <SDL_pixels.h>
#include <SDL_render.h>

SDL_Colour * createSDL_Colour(int r, int g, int b, int a);

#define COLOUR_BLACK createSDL_Colour(0x00, 0x00, 0x00, 0xFF)
#define COLOUR_WHITE createSDL_Colour(0xFF, 0xFF, 0xFF, 0xFF)
#define COLOUR_TRANSPARENT createSDL_Colour(0x00, 0x00, 0x00, 0x00) 

#endif
