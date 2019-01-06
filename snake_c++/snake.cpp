#include <iostream>
#include "snake.h"
#include "wall.h"

snake::snake(position headPosition) {
	abdomen head;
	head.setPosition(position(wall::X_OFFSET + headPosition.getX(), wall::Y_OFFSET + headPosition.getY()));
	this->xenxia.emplace_back(head);

	abdomen thorax;
	thorax.setPosition(position(head.getPosition().getX() - 1, head.getPosition().getY()));
	this->xenxia.emplace_back(thorax);

	abdomen butt; // or ass
	butt.setPosition(position(thorax.getPosition().getX() - 1, head.getPosition().getY()));
	this->xenxia.emplace_back(butt);
}

snake::snake() {}

snake::~snake(){}

std::vector<abdomen> snake::getAllAbdomen() {
	return this->xenxia;
}

position snake::getHeadPosition() {
	return this->xenxia[0].getPosition();
}

void snake::grow() {
	this->xenxia.emplace_back(abdomen());
}

void snake::move(position nextPos) {
	this->lastAbdomenPosition = this->xenxia[this->xenxia.size() - 1].getPosition();
	position tempPos;
	for (unsigned int abdIndex = 0; abdIndex < this->xenxia.size(); abdIndex++) {
		tempPos = this->xenxia[abdIndex].getPosition();
		this->xenxia[abdIndex].setPosition(nextPos);
		/* every abdomen has a "nextPos" to which it it going to displace
		   therefore "nextPos" must be updated everytime with the position
		   that the abdomen before it was at */
		nextPos = tempPos;
	}
}

bool snake::ateFood(position foodPosition) {
	return this->getHeadPosition() == foodPosition;
}

void snake::draw() {
	for (abdomen bodyPart : this->xenxia) {
		bodyPart.draw();
	}
	snake::clearTrail();
}

void snake::disappear() {
	for (abdomen bodyPart : this->xenxia) {
		gotoPos(bodyPart.getPosition());
		std::cout << " ";
	}
}

void snake::clearTrail() {
	/* the last abdomen in the vector (xenxia) will still be left on the console
	even after it has displaced to the next coordinate. Therefore, an empty
	space must be drawn in it's place to avoid trails */
	gotoPos(lastAbdomenPosition);
	std::cout << " ";
}

bool snake::collided(std::vector<brick> wallBricks) {
	position snakeHeadPosition = getHeadPosition();
	for (brick brk : wallBricks) {
		if (snakeHeadPosition == brk.getPosition()) {
			return true;
		}
	}
	return false;
}
