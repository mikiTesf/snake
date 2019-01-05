#include "abdomen.h"
#include "brick.h"
#include <vector>

#pragma once
class snake
{
private:
	std::vector<abdomen> xenxia;
	position lastAbdomenPosition;
	position getHeadPosition();
public:
	snake();
	~snake();

	bool collided(std::vector<brick>);
	bool ateFood(position);
	std::vector<abdomen> getAllAbdomen();

	void grow();
	void move(position);
	void draw();
	void clearTrail();
};

