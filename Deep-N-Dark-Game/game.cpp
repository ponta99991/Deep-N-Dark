#include "game.h"

SDL_Renderer* Game::_renderer = nullptr;

Game::Game(const char* title, int xpos, int ypos, int width, int height) {
	Game::init(title, xpos, ypos, width, height);
}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height) {
	int flags = 0;//example = SDL_WINDOW_FULLSCREEN for fullscreen

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {//checks so sdl works
		std::cout << "SDL initialised!\n";

		_window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);//create window
		if (_window) {//checks so window exists
			std::cout << "Window is created\n";
		}

		_renderer = SDL_CreateRenderer(_window, -1, 0);//create renderer
		if (_renderer) {
			SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
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
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym){
		case SDLK_DOWN:
			_downKeyPressed = true;
			break;
		case SDLK_UP:
			_upKeyPressed = true;
			break;
		case SDLK_LEFT:
			_leftKeyPressed = true;
			break;
		case SDLK_RIGHT:
			_rightKeyPressed = true;
			break;
		default:
			break;
		}
		break;
	case SDL_KEYUP:
		switch (event.key.keysym.sym) {
		case SDLK_DOWN:
			_downKeyPressed = false;
			break;
		case SDLK_UP:
			_upKeyPressed = false;
			break;
		case SDLK_LEFT:
			_leftKeyPressed = false;
			break;
		case SDLK_RIGHT:
			_rightKeyPressed = false;
			break;
		default:
			break;
		}
		break;
	default:
		break;
	}
}

void Game::update() {

}

void Game::render() {
	SDL_RenderPresent(_renderer);
	//add things that will render
	SDL_SetRenderDrawColor(_renderer, 0, 0, 0, 255);
	
	SDL_RenderClear(_renderer);
	
}

void Game::clean() {//when turning off
	SDL_DestroyRenderer(_renderer);
	SDL_DestroyWindow(_window);
	SDL_Quit();
	std::cout << "Game cleaned\n";
}