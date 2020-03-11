#include "SDL.h"
#include "game.h"
#include "object.h"


int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	std::cout << "game has started\n";
	Game game("Dark-N-Deep", 300, 200, 800, 600);
	Object o(400, 300, 20, 20);

	while (game.running()) {
		frameStart = SDL_GetTicks();
		game.handleEvents();

		if (game._downKeyPressed) {
			o.translate(down, 1);
		}
		else if (game._leftKeyPressed) {
			o.translate(left, 1);
		}
		else if (game._upKeyPressed) {
			o.translate(up, 1);
		}
		else if (game._rightKeyPressed) {
			o.translate(right, 1);
		}
		//game.update();
		o.draw();
		game.render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);//Waiting until 1000/fps time has passed
		}
	}
	return 0;
}