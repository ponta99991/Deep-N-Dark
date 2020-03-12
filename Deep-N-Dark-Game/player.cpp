#include "player.h"
#include <iostream>

Player::Player(int x, int y, int w, int h) :
	Entity(x, y, w, h) {

	std::clog << "Player has been created\n";
}

void Player::walk(Direction dirr) {
	switch (dirr)
	{
	case up:
		_y--;
		break;
	case down:
		_y++;
		break;
	case left:
		_x--;
		break;
	case right:
		_x++;
		break;
	default:
		break;
	}
}

