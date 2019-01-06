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
		std::cout << "It is recommended that you maximize the window... (press any key after you do so)";
		_getch();
		std::cout << std::endl << "Use 'D', 'A', 'W' and 'S' to go right, left, up and down respectively" << std::endl;
		// repeat game decision
		char playAgain = 'y';
		// moving directions
		const char LEFT = 'a';
		const char RIGHT = 'd';
		const char UP = 'w';
		const char DOWN = 's';
		// wall dimensions
		const int WIDTH  = 50;
		const int HEIGHT = 20;

		position nextPosition;

		wall jegol;
		food fud;

		jegol.setDimensions(WIDTH, HEIGHT);
		fud.setPosition(position(35, 15));
		//\ /\ \/ /\ \/ /\ \/ /\ \/ /\ \/ /\ \/
		jegol.draw();
		fud.draw();

		// the snake starts moving to the right (why? because I said so)
		char moveDirection;
		while (playAgain == 'y') {
			nextPosition.setX(wall::X_OFFSET + 8);
			nextPosition.setY(wall::Y_OFFSET + 4);
			// on every new game a new snake is crated
			snake xenxia(nextPosition);
			xenxia.draw();
			// reset default direction
			moveDirection = RIGHT;
			// main game loop
			while (true) {
				if (_kbhit()) { moveDirection = _getch(); }

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
					continue;
				}

				xenxia.move(nextPosition);

				if (xenxia.collided(jegol.getBricks())) {
					gotoxy(wall::X_OFFSET, wall::Y_OFFSET + HEIGHT + 3);
					std::cout << "Game over! You collided.";
					std::cout << " Would you like to play again (y/n): ";
					std::cin >> playAgain;
					// clear the characters that make up the snake
					xenxia.disappear();
					// fix broken wall characters by redrawing it
					jegol.draw();
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
		}

		gotoxy(wall::X_OFFSET, wall::Y_OFFSET + HEIGHT + 4);
		std::cout << "Thank you for trying \"snake_c\". Press any key to quit...";

		_getch();
	}
};