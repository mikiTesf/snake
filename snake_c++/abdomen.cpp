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
	gotoPos(this->pos);
	std::cout << (char)254;
}

abdomen::~abdomen(){}
