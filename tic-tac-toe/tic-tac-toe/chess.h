#ifndef _CHESS_H_
#define _CHESS_H_

#include <stdio.h>
#include <Windows.h>
#include <time.h>

#define ROW 3
#define COL 3
#define PLAYER_COLOR 'X'
#define COMPUTER_COLOR 'O'

#pragma warning(disable:4996)

void Game();
void InitBoard(char board[][COL], int row,int col);
void ShowBoard(char board[][COL], int row, int col);
void PlayerMove(char board[][COL], int row, int col);
char Judge(char board[][COL], int row, int col);
void ComputerMove(char board[][COL], int row, int col);

#endif
