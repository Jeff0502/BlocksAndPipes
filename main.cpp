#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    std::cout << "Hello World";

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
        std::cout << "Failed to initialize " << SDL_GetError();
         
    SDL_Window *window = SDL_CreateWindow("hello world", 0, 0, 800, 600, SDL_WINDOW_SHOWN);

    while(true);
    
    return 0;
}