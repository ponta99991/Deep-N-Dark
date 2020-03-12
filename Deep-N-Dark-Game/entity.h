#pragma once

#include "object.h"

class Entity : public Object {
public:
	Entity(int x, int y, int w, int h);

	void jump();

	void virtual move(Direction dirr);

	void update();
private:
	

};