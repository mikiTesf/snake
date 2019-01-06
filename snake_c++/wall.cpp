#include "wall.h"

wall::wall(){};

wall::~wall(){}

void wall::setDimensions(int WIDTH, int HEIGHT) {
	this->WIDTH  = WIDTH;
	this->HEIGHT = HEIGHT;
	/* fill the brick vector in the wall class with bricks that have
	positions along the right dimensions */
	// top width
	for (int x = 0; x < this->WIDTH; x++) {
		brick newBrick(this->X_OFFSET + x, this->Y_OFFSET);
		newBrick.setHorizontal(true);
		this->jegol.emplace_back(newBrick);
	}
	// bottom width
	for (int x = 0; x < this->WIDTH + 1; x++) {
		brick newBrick(this->X_OFFSET + x, this->Y_OFFSET + this->HEIGHT);
		newBrick.setHorizontal(true);
		this->jegol.emplace_back(newBrick);
	}
	// left length
	for (int y = 0; y < this->HEIGHT + 1; y++) {
		brick newBrick(this->X_OFFSET, y + this->Y_OFFSET);
		newBrick.setHorizontal(false);
		this->jegol.emplace_back(newBrick);
	}
	// right length
	for (int y = 0; y < this->HEIGHT + 1; y++) {
		brick newBrick(this->WIDTH + this->X_OFFSET, y + this->Y_OFFSET);
		newBrick.setHorizontal(false);
		this->jegol.emplace_back(newBrick);
	}
}

std::vector<brick> wall::getBricks() {
	return this->jegol;
}

void wall::draw() {
	for (brick brk : this->jegol) {
		brk.draw();
	}
}