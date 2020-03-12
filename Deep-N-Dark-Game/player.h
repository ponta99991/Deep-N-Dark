#pragma once

#include "entity.h"

class Player : public Entity {
public:
	Player(int x, int y, int w, int h);

	void walk(Direction dirr);

	void update();

private:

};