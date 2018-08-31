#include "SDL2/SDL.h"
#include <stdio.h>

int main(int argc, char *argv[]){
	SDL_Window *window;
	SDL_Renderer *renderer;

	SDL_Init(SDL_INIT_VIDEO);

	// create window
	window = SDL_CreateWindow("Game Window",
			SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED,
			640,
			480,
			0
			);
	
	// create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	// set draw color to blue
	SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

	// clear screen (to blue)
	SDL_RenderClear(renderer);

	// set draw color to white
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	
	// create rectangle
	SDL_Rect rect = { 220, 140, 200, 200 };

	// fill rectangle (with white)
	SDL_RenderFillRect(renderer, &rect);

	// "present" drawing to screen
	SDL_RenderPresent(renderer);

	// wait a few seconds before quitting
	SDL_Delay(4000);

	// close and destroy window and renderer
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	// clean up
	SDL_Quit();
	return 0;
}
