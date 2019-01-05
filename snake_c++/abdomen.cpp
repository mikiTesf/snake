#include <iostream>
#include "abdomen.h"

abdomen::abdomen(){}

void abdomen::setPosition(position newPosition) {
	this->pos = newPosition;
}

position abdomen::getPosition() {
	return this->pos;
}

void abdomen::draw() {
	gotoxy(this->pos.getX(), this->pos.getY());
	std::cout << (char)254;
}

abdomen::~abdomen(){}
