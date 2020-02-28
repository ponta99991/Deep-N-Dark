#include "SDL.h"
#include "game.h"
#include "object.h"


int main(int argc, char* argv[])
{

	std::cout << "game has started\n";
	Game game("Dark-N-Deep", 300, 200, 800, 600);
	Object o(400, 300, 20, 20);

	while (game.running()) {
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
		game.handleEvents();
		//game.update();
		o.draw();
		game.render();
	}
	return 0;
}