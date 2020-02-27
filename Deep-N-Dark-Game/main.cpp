#include "SDL.h"
#include "game.h"


int main(int argc, char* argv[])
{

	Game window("Dark-N-Deep", 300, 200, 800, 600);

	while (window.running()) {
		window.handleEvents();
		window.update();
	}
	return 0;
}