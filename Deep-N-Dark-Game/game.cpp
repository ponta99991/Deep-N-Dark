#include "game.h"
#include <iostream>;
Game::Game(const char* title, int xpos, int ypos, int width, int height) {
	Game::init(title, xpos, ypos, width, height);
}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height) {
	int flags = 0;//example = SDL_WINDOW_FULLSCREEN for fullscreen

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {//checks so sdl works
		std::cout << "SDL initialised!\n";

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);//create window
		if (window) {//checks so window exists
			std::cout << "Window is created\n";
		}

		renderer = SDL_CreateRenderer(window, -1, 0);//create renderer
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer is created\n";
			isRunning = true;
		}
		else {
			isRunning = false;
		}
	}
}

void Game::handleEvents() {
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type) {
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}

void Game::update() {

}

void Game::render() {
	SDL_RenderClear(renderer);
	//add things that will render
	SDL_RenderPresent(renderer);
}

void Game::clean() {//when turning off
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
	std::cout << "Game cleaned\n";
}