#pragma once

#include "SDL.h"
#include <stdio.h>
#include <iostream>

class Game {
public:
	Game(const char* title, int xpos, int ypos, int width, int height);
	~Game();


	void handleEvents();
	void update();
	void render();
	void clean();

	bool inline running() { return isRunning; }

private:
	void init(const char* title, int xpos, int ypos, int width, int height);
	bool isRunning;
	SDL_Window* _window;

public:
	static SDL_Renderer* _renderer;
	bool _downKeyPressed = false;
	bool _upKeyPressed = false;
	bool _leftKeyPressed = false;
	bool _rightKeyPressed = false;
};