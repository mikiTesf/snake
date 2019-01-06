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
	~snake();

	std::vector<abdomen> getAllAbdomen();

	position getHeadPosition();
	void move(position);
	void grow();
	void draw();
	void clearTrail();

	bool collided(std::vector<brick>);
	bool ateFood(position);
};

