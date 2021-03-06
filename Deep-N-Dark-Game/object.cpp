#include "object.h"

Object::Object(int x, int y, int w, int h) : _x(x), _y(y), _w(w), _h(h) {

}

void Object::translate(Direction dirr, int distance) {
	switch (dirr)
	{
	case up:
		_y-= distance;
		break;
	case down:
		_y+= distance;
		break;
	case left:
		_x-= distance;
		break;
	case right:
		_x+= distance;
		break;
	default:
		break;
	}
}

void Object::drawToTexture(void) {
	SDL_Rect rect = { _x, _y, _w, _h };

	SDL_SetRenderDrawColor(Game::_renderer, 0, 255, 0, 255);
	SDL_RenderFillRect(Game::_renderer, &rect);
}