#ifndef _MINE_H_
#define _MINE_H_

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>

#define ROW 12 //10 + 2
#define COL 12
#define TOTAL 10*10
#define MINE_NUM 20

#pragma warning(disable:4996)

void SetMine(char mine[][COL], int row, int col);
void ShowBoard(char board[][COL], int row, int col);
char GetMines(char mine[][COL], int row, int col);
void Game();

#endif
