#include "Tetris.h"

int main()
{
	Tetris t = InitGame();

	char key;

	while (1) {
		system("cls");
		DrawBoard(t);
		SpawnBlock(t);

		while (_kbhit()) {
			key = _getch();
			switch (key) {
			case UP:
				printf("UP\n");
				break;

			case DOWN:
				printf("DOWN\n");
				break;

			case LEFT:
				printf("LEFT\n");
				break;

			case RIGHT:
				printf("RIGHT\n");
				break;
			}
			if (key == SPACE) {
				printf("SPACE\n");
			}
		}
	}
} 