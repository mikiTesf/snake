#include <iostream>
#include <iomanip>
#include <vector>
#include "food.h"
#include "abdomen.h"
#include "wall.h"

food::food() {}

food::~food(){}

void food::setPosition(position newPosition) {
	this->foodPos = newPosition;
}

position food::getPosition() {
	return this->foodPos;
}

bool food::checkPositionAgainstSnake(std::vector<abdomen> allAbdomen) {
	// hod = ሆድ
	for (abdomen hod : allAbdomen) {
		if (this->foodPos == hod.getPosition()) {
			return true;
		}
	}
	return false;
}

void food::setNextPosition(std::vector<abdomen> allAbdomen, int width, int length) {
	static bool firstTime = true;

	if (firstTime) {
		srand(time(NULL));
		firstTime = false;
	}

	do {
		// range = max - min + 1
		// deciding horizontal coordinate (x)
		int minimum = wall::X_OFFSET + 1;
		int maximum = wall::X_OFFSET + width;
		int range = maximum - minimum;
		this->foodPos.setX((rand() % range) + minimum);
		// deciding vertical coordinate (y)
		minimum = wall::Y_OFFSET + 1;
		maximum = wall::Y_OFFSET + length;
		range = maximum - minimum;
		this->foodPos.setY((rand() % range) + minimum);
	} while (this->checkPositionAgainstSnake(allAbdomen));
}

void food::draw() {
	gotoxy(foodPos.getX(), foodPos.getY());
	std::cout << (char)248;
}
