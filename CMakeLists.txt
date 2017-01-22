cmake_minimum_required(VERSION 2.8)
project(SDL2-GUI_SOLUTION)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

if(NOT ${SDL2TTF_FOUND})
    set(SDL_TTF2_URL "https://www.libsdl.org/projects/SDL_ttf/release/SDL2_ttf-2.0.14.zip")
    set(SDL_TTF2_PATH "./sdl2_ttf")
    file(DOWNLOAD ${SDL_TTF2_URL} ${SDL_TTF2_PATH})
endif()

#add_subdirectory(SDL2-GUI)
#add_subdirectory(SDL2-GUI-Test)
