#include "abdomen.h"
#include "brick.h"
#include <vector>

#pragma once
class snake
{
private:
	std::vector<abdomen> xenxia;
	position lastAbdomenPosition;
public:
	snake();
	snake(position);
	~snake();

	std::vector<abdomen> getAllAbdomen();

	position getHeadPosition();
	void move(position);
	bool ateFood(position);
	void grow();
	void draw();
	void disappear();
	void clearTrail();
	bool collided(std::vector<brick>);
};

