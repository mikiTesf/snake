#include "position.h"

#pragma once
class abdomen
{
private:
	position pos;
public:
	abdomen();
	~abdomen();

	void setPosition(position);
	position getPosition();
	
	void draw();
};

