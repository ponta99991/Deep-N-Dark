#include "entity.h"

Entity::Entity(int x, int y, int w, int h) : 
	Object(x, y, w, h) {

}

void Entity::move(Direction	dirr) {
	
}

void Entity::update() {
	_yVel++;
}