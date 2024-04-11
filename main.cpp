#include <iostream>

#include <SDL2/SDL.h>

int main(int argc, char *argv[])
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {  
        std::cout << "Failed to initialize " << SDL_GetError( ) << std::endl;
        return 1;
    }
        
    // Le box fancy box on your screen
    SDL_Window *window = SDL_CreateWindow("hello world", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_ALLOW_HIGHDPI);
    SDL_Event windowEvent;

    // Le thing that actually renders things
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    // A rectangle to test everything (This thing is a struct, go goegel)
    SDL_Rect rect = {
      0, 0, 100, 100  
    };

  while(true)
  {
    // Clear the background
    SDL_RenderClear(renderer);

    // Colour for the rectangle
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);

    // Colour for the background, since RenderClear is called again
    SDL_SetRenderDrawColor(renderer, 100, 149, 237, 255);

    // Gets the current window event
    if (SDL_PollEvent(&windowEvent))
    {
        if (SDL_QUIT == windowEvent.type)
        { 
            break; 
        }
    }
  }

  // Frees up the space taken by the window and window
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
  
}