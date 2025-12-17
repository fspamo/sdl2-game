#include <SDL2/SDL.h>
#include <stdio.h>

void player_movement(SDL_Rect box)
{
}

int main(int argc, char *argv[])
{
	int running = 1;
	SDL_Event event;

	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		printf("SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window *window = SDL_CreateWindow(
			"Hello SDL2",
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			800,
			600,
			SDL_WINDOW_SHOWN
			);

	if (!window)
	{
		printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
		SDL_Quit();
		return 1;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(
			window,
			-1,
			SDL_RENDERER_ACCELERATED
			);

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);

	SDL_Rect box;

	box.x = 100;
	box.y = 100;
	box.w = 200;
	box.h = 150;

	// Set draw color to red
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &box);

	// Show what we drew
	SDL_RenderPresent(renderer);

	// SDL_Delay(1000); // Keep window open for 3 seconds
	while (running)
	{
		// Process all events
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_KEYDOWN)
			{
				// simple movement for the character.
				if(event.key.keysym.sym == SDLK_d)
				{
					box.x = box.x + 20;
				}
				else if(event.key.keysym.sym == SDLK_a)
				{
					box.x = box.x - 20;
				}
				else if(event.key.keysym.sym == SDLK_w)
				{
					box.y = box.y - 20;
				}
				else if(event.key.keysym.sym == SDLK_s)
				{
					box.y = box.y + 20;
				}
				else if (event.key.keysym.sym == SDLK_0) // Press "0"
				{
					running = 0;
				}
			}
		}

		// Clear screen (black)
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		// Draw red box
		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		SDL_RenderFillRect(renderer, &box);

		// Present the frame
		SDL_RenderPresent(renderer);

		// 16ms delay (locking it to 60 FPS to avoid 100% CPU usage)
		SDL_Delay(16);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	// SDL_DestroyWindow(window);
	// SDL_Quit();

	return 0;
}
