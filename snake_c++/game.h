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
		// wall dimensions
		const int WIDTH  = 50;
		const int HEIGHT = 20;

		wall jegol;
		snake xenxia;
		food fud;
		// positions used during the game
		position nextPosition(xenxia.getHeadPosition().getX() + 1, xenxia.getHeadPosition().getY());
		fud.setPosition(position(35, 15));
		//\ /\ \/ /\ \/ /\ \/ /\ \/ /\ \/ /\ \/
		jegol.setDimensions(WIDTH, HEIGHT);
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
				gotoxy(wall::X_OFFSET, wall::Y_OFFSET + HEIGHT + 3);
				std::cout << "You collided. Game over! ";
				std::cout << "Press any key to quit...";
				break;
			}

			if (xenxia.ateFood(fud.getPosition())) {
				xenxia.grow();
				fud.setNextPosition(xenxia.getAllAbdomen(), WIDTH, HEIGHT);
				fud.draw();
			}

			xenxia.draw();
			
			Sleep(50);
		}

		_getch();
	}
};