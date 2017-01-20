cmake_minimum_required(VERSION 2.8)
project(SDL2-GUI_SOLUTION)

include(FindPkgConfig)
pkg_search_module(SDL2 REQUIRED sdl2>=2.0.0)
pkg_search_module(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)
pkg_search_module(SDL2TTF REQUIRED SDL2_ttf>=2.0.0)

add_subdirectory(SDL2-GUI)
add_subdirectory(SDL2-GUI-Test)
