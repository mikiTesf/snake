#pragma once
#include <Windows.h>

static void gotoxy(int x, int y) {
	static HANDLE h = NULL;
	if (!h) {
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	}
	COORD c = { (short)x, (short)y };
	SetConsoleCursorPosition(h, c);
}

class position
{
private:
	int x;
	int y;
public:
	// constructors
	position();
	position(int, int);

	~position();

	void setX(int);
	void setY(int);
	int getX();
	int getY();
	void setPosition(position);

	position getPosition();
	// "==" must be overloaded in order to make position comparisons easier
	bool operator == (position);
};

