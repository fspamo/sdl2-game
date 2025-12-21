#include <stdio.h>
#include <SDL2/SDL.h>

void player_movement(int *running, SDL_Event *event, 
		SDL_Renderer *renderer, SDL_Rect *box)
{
	while (*running)
	{
		while (SDL_PollEvent(event))
		{
			if (event->type == SDL_KEYDOWN)
			{
				if (event->key.keysym.sym == SDLK_d)
					box->x += 20;
				else if (event->key.keysym.sym == SDLK_a)
					box->x -= 20;
				else if (event->key.keysym.sym == SDLK_w)
					box->y -= 20;
				else if (event->key.keysym.sym == SDLK_s)
					box->y += 20;
				else if (event->key.keysym.sym == SDLK_0)
					*running = 0;
			}
		}

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
		SDL_RenderFillRect(renderer, box);

		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}
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

	// color thing
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_RenderFillRect(renderer, &box);

	// idk bruh
	SDL_RenderPresent(renderer);

	player_movement(&running, &event, renderer, &box);

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
