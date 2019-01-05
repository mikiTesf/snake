#include <vector>
#include "brick.h"

#pragma once
class wall
{
private:
	int WIDTH;
	int HEIGHT;
	std::vector<brick> jegol;
public:
	static const int X_OFFSET = 20;
	static const int Y_OFFSET = 10;

	wall();
	~wall();

	void setDimensions(int, int);
	std::vector<brick> getBricks();
	void draw();
};

