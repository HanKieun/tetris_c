#include"Tetris.h"
#include <random>

std::random_device rd;
std::mt19937 mesenne(rd());
std::uniform_int_distribution<> randomBlock(0, 3);

int blocks[7][4][4][4] = {
    // ㄴ
    0,0,0,0,0,1,0,0,0,1,1,1,0,0,0,0,    0,0,0,0,0,1,1,0,0,1,0,0,0,1,0,0,    0,0,0,0,1,1,1,0,0,0,1,0,0,0,0,0,    0,0,1,0,0,0,1,0,0,1,1,0,0,0,0,0,
    // ㄴ반대
    0,0,0,0,0,0,1,0,1,1,1,0,0,0,0,0,    0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,    0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,0,    0,0,0,0,0,1,1,0,0,0,1,0,0,0,1,0,
    // ㅁ
    1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,    1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,    1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,    1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,
    // ㅡ
    0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,    0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,0,    0,0,0,0,1,1,1,1,0,0,0,0,0,0,0,0,    0,0,1,0,0,0,1,0,0,0,1,0,0,0,1,0,
    // ㅗ
    0,0,0,0,0,1,0,0,1,1,1,0,0,0,0,0,    0,0,0,0,0,1,0,0,0,1,1,0,0,1,0,0,    0,0,0,0,0,0,0,0,1,1,1,0,0,1,0,0,    0,0,0,0,0,1,0,0,1,1,0,0,0,1,0,0,
    // ㄱㄴ
    0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,    0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,    0,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,    0,1,0,0,1,1,0,0,1,0,0,0,0,0,0,0,
    // ㄱㄴ반대
    0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,    0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0,    0,0,0,0,0,1,1,0,1,1,0,0,0,0,0,0,    0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,0
};

int gameBoard[HEIGHT][WIDTH];
const char* figure[2] = { "  ", "■" };

Tetris InitGame()
{
    Tetris t;
    t.level = 1;
    t.gameover = 0;
    t.score = 0;
    t.rotation = 0;
    t.absX = t.absY = 0;
    t.curX = t.curY = 0;
    t.curBlock = 0;
    t.nextBlock = 0;

    //게임보드 초기화
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (x == 0 || x == WIDTH - 1)
                gameBoard[y][x] = 1;
            else if (y == HEIGHT - 1)
                gameBoard[y][x] = 1;
            else
                gameBoard[y][x] = 0;
        }
    }

    return t;
}

void DrawBoard()
{
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {
            if (gameBoard[y][x] == 1)
                printf("%s", figure[1]);
            else
                printf("%s", figure[0]);
        }
        printf("\n");
    }
}

void Gotoxy(int x, int y)
{
	COORD pos = { x, y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void RemoveCursor()
{
	CONSOLE_CURSOR_INFO curInfo;
	curInfo.bVisible = 0;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), & curInfo);
}

void RemoveCurrentBlock(Tetris& t)
{
    for(int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++) {
            if (blocks[t.curBlock][t.rotation][j][i] == 1) {
                Gotoxy(t.absX + (i + t.curX) * 2, t.absY + j + t.curY);
                printf("  ");
            }
        }
}

void SpawnBlock(Tetris& t)
{
    //t.curBlock = randomBlock(mesenne);
    t.curBlock = 0;
    t.curX = WIDTH / 2;
    t.curY = 0;

    Gotoxy(t.absX + t.curX, t.absY + t.curY);
    for (int y = 0; y < 4; y++) {
        for (int x = 0; x < 4; x++) {
            if (blocks[t.curBlock][t.rotation][y][x] == 1) {
                Gotoxy(t.absX + t.curX + x*2, t.absY + t.curY + y);
                printf("%s", figure[1]);
            }
        }
    }
}