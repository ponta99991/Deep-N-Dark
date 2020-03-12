#include "SDL.h"
#include "game.h"
#include "object.h"
#include "entity.h"
#include "player.h"


int main(int argc, char* argv[])
{
	const int FPS = 60;
	const int frameDelay = 1000 / FPS;
	Uint32 frameStart;
	int frameTime;

	std::cout << "game has started\n";
	Game game("Dark-N-Deep", 300, 200, 800, 600);

	Player player(400, 300, 20, 20);

	while (game.running()) {
		frameStart = SDL_GetTicks();
		game.handleEvents();

		if (game._downKeyPressed) {
			player.walk(down);
		}
		if (game._leftKeyPressed) {
			player.walk(left);
		}
		if (game._upKeyPressed) {
			player.walk(up);
		}
		if (game._rightKeyPressed) {
			player.walk(right);
		}
		//game.update();
		player.draw();
		game.render();

		frameTime = SDL_GetTicks() - frameStart;
		if (frameDelay > frameTime) {
			SDL_Delay(frameDelay - frameTime);//Waiting until 1000/fps time has passed
		}
	}
	return 0;
}