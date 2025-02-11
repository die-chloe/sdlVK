#pragma once


//Headers

#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_vulkan.h>
#include <string>


//Constants

constexpr int kScreenWidth{ 1920 };
constexpr int kScreenHeight{ 1080 };


//Starts SDL and creates window
bool init();

//Loads Media
bool loadMedia();

//Frees Media and shuts down SDL
void close();




//Global Variables

SDL_Window* gWindow{ nullptr };

SDL_Surface* gScreenSurface{ nullptr };

SDL_Surface* gHelloWorld{ nullptr };