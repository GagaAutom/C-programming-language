#include "chess.h"

void InitBoard(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++) {
		int j = 0;
		for (; j < col; j++) {
			board[i][j] = ' ';
		}
	}
}

void ShowBoard(char board[][COL], int row, int col)
{
	printf("   | 1 | 2 | 3\n");
	printf("----------------\n");
	int i = 1;
	for (; i <= 3; i++) {
		printf(" %d | %c | %c | %c \n", \
			i, board[i - 1][0], board[i - 1][1], board[i - 1][2]);
		if (i != 3) {
			printf("----------------\n");
		}
	}
}

void PlayerMove(char board[][COL], int row, int col)
{
	while (1) {
		int x = 0;
		int y = 0;
		printf("Please Enter Pos<x,y>:");
		scanf("%d,%d", &x, &y);
		if (x >= 1 && x <= 3 && y >= 1 && y <= 3) {
			if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = PLAYER_COLOR;
				break;
			}
			else {
				printf("Enter Error,Try again!1\n");
			}
		}
		else {
			printf("Enter Error,Try again!2\n");
		}
	}
}

char Judge(char board[][COL], int row, int col)
{
	int i = 0;
	for (; i < row; i++) {
		if(board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1]==board[i][2])
		{
			return board[i][0];
		}
	}
	for (i = 0; i < col; i++) {
		if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
		{
			return board[0][i];
		}
	}
	if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
	{
		return board[1][1];
	}
	if (board[0][2] != ' '&&board[0][2] == board[1][1] && board[1][1] == board[2][0]) 
	{
		return board[1][1];
	}
	for (i = 0; i < row; i++) {
		int j = 0;
		for (; j < col; j++) {
			if (board[i][j] == ' ') {
				return 'N';
			}
		}
	}
	return 'E';
}

int GetRandom(int start, int end) {
	srand((unsigned int)time(NULL));
	return rand() % (end - start + 1) + start;
}

void ComputerMove(char board[][COL], int row, int col)
{
	while (1) {
		int x = GetRandom(1,3);
		int y = GetRandom(1,3);
		if (board[x - 1][y - 1] == ' ') {
				board[x - 1][y - 1] = COMPUTER_COLOR;
				break;
		}
	}
}


void Game()
{
	char board[ROW][COL];
	char result = 0;
	InitBoard(board,ROW,COL);
	ShowBoard(board, ROW, COL);
	while (1) {
		PlayerMove(board, ROW, COL);
		ShowBoard(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != 'N') {
			break;
		}
		ComputerMove(board, ROW, COL);
		ShowBoard(board, ROW, COL);
		result = Judge(board, ROW, COL);
		if (result != 'N') {
			break;
		}
	}
	switch (result) {
	case 'X'://you win
		printf("你赢了\n");
		break;
	case 'O'://computer win
		printf("你输了\n");
		break;
	case 'E'://Equal
		printf("平局\n");
		break;
	default:
		printf("Throwable Exception?!?!\n");
		break;
	}
	
	printf("Play again?\n");
}