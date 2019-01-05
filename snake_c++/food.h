#include "position.h"
#include "abdomen.h"

#pragma once
class food
{
private:
	position foodPos;
public:
	food();
	~food();

	void setPosition(position);
	position getPosition();

	bool checkPositionAgainstSnake(std::vector<abdomen>);
	position getNextPosition(std::vector<abdomen>, int, int);

	void draw();
};
