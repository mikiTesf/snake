#pragma once
#include "position.h"

class brick
{
private:
	bool horizontal;
	position brickPos;
public:
	brick();
	brick(int, int);
	brick(position);
	~brick();

	void setHorizontal(bool);
	bool getHorizontal();
	
	void setPosition(position);
	position getPosition();

	void draw();
};

