#pragma once
#include <iostream>
#pragma once
#include "brick.h"

brick::brick(){
	this->brickPos.setX(0);
	this->brickPos.setY(0);
}
brick::~brick(){}

brick::brick(int x, int y) {
	this->brickPos.setX(x);
	this->brickPos.setY(y);
}

brick::brick(position newPosition) {
	this->brickPos = newPosition;
}

bool brick::getHorizontal() {
	return this->horizontal;
}

void brick::setHorizontal(bool newhorizontal) {
	this->horizontal = newhorizontal;
}

void brick::setPosition(position newPosition) {
	this->brickPos = newPosition;
}

position brick::getPosition() {
	return this->brickPos;
}

void brick::draw() {
	gotoxy(brickPos.getX(), brickPos.getY());
	// the 254th character is ■
	// the 219th character is 
	if (this->horizontal)
		std::cout << (char)254;
	else
		std::cout << (char)219;
}