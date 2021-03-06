#pragma once
#include<cstdio>
#include<conio.h>
#include<Windows.h>

#define UP 72
#define DOWN 80
#define LEFT 75
#define RIGHT 77
#define SPACE 32
#define WIDTH 15
#define HEIGHT 25

typedef struct _tetris {
	int rotation;
	int absX, absY;
	int curX, curY;
	int curBlock;
	int nextBlock;
	bool isBlockSpawn;
}Tetris;

Tetris InitGame();
void DrawBoard(Tetris& t);
void Gotoxy(int x, int y);
void RemoveCursor();
void RemoveCurrentBlock(Tetris& t);
void SpawnBlock(Tetris& t);
void DrawBlock(Tetris& t);
void MoveLeftAndRight(Tetris& t, int direction);
void MoveDown(Tetris& t);
void RotationBlock(Tetris& t);
bool CollisionCheck(Tetris& t);
void BlockFix(Tetris& t);
void DrawFrame(Tetris& t);
void RemoveLine(Tetris& t);
bool GameOver();
void QuickDown(Tetris& t);
void ShowNextBlock(Tetris& t);