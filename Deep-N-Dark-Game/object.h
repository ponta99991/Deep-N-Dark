#pragma once

#include "game.h"
#include "SDL.h"
#include "direction.h"


class Object {
public:
	Object(int x, int y, int w, int h);
	

	void inline draw() { drawToTexture(); }

	void translate(Direction dirr, int distance);

private:
	void drawToTexture(void);

protected:
	int _x, _y, _w, _h;
	int _xVel = 0, _yVel = 0;
};