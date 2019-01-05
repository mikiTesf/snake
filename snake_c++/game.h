#include <conio.h>
#include <iostream>
#include "brick.h"
#include "wall.h"
#include "snake.h"
#include "food.h"

class game {
private:
	// the wall, snake and the food should be here
public:
	void run() {
		std::cout << "It is recommended that you resize the window... (press any key after you do so)";
		_getch();

		// moving directions
		const char LEFT = 'a';
		const char RIGHT = 'd';
		const char UP = 'w';
		const char DOWN = 's';

		wall jegol;
		snake xenxia;
		food fud;
		// positions used during the game
		position nextPosition(wall::X_OFFSET + 13, wall::Y_OFFSET + 5);
		position foodPosition(30, 28);
		fud.setPosition(foodPosition);
		//\ /\ \/ /\ \/ /\ \/ /\ \/ /\ \/ /\ \/
		jegol.setDimensions(60, 20);
		jegol.draw();
		xenxia.draw();
		fud.draw();

		// the snake starts moving to the right (why? because I said so)
		char moveDirection = RIGHT;
		// main game loop
		while (true) {
			if (_kbhit()) moveDirection = _getch();

			switch (moveDirection) {
				case RIGHT:
					nextPosition.setX(nextPosition.getX() + 1);
					break;
				case LEFT:
					nextPosition.setX(nextPosition.getX() - 1);
					break;
				case UP:
					nextPosition.setY(nextPosition.getY() - 1);
					break;
				case DOWN:
					nextPosition.setY(nextPosition.getY() + 1);
					break;
				default:
					break;
			}

			xenxia.move(nextPosition);

			if (xenxia.collided(jegol.getBricks())) {
				std::cout << "you done collided nigga!!";
			}

			if (xenxia.ateFood(foodPosition)) {
				foodPosition = fud.getNextPosition();
				xenxia.grow();
			}

			xenxia.draw();
			
			Sleep(50);
		}

		_getch();
	}
};