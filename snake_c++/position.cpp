#include "position.h"

position::position(){}

position::position(int x, int y) {
	this->x = x;
	this->y = y;
}

position::~position(){}

void position::setX(int x){
	this->x = x;
}

void position::setY(int y) {
	this->y = y;
}

int position::getX() {
	return this->x;
}

int position::getY() {
	return this->y;
}

void position::setPosition(position newPos) {
	this->x = newPos.x;
	this->y = newPos.y;
}

position position::getPosition() {
	return position(this->x, this->y);
}

bool position::operator == (position anotherPosition) {
	return (this->x == anotherPosition.x) && (this->y == anotherPosition.y);
}