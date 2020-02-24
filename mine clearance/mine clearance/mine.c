#include "mine.h"

int GetRandIndex(int start, int end)//1-10
{
	return rand() % (end - start + 1) + start;
}

void SetMine(char mine[][COL], int row, int col)
{
	srand((unsigned long)time(NULL));
	int count = 0;
	while (count < MINE_NUM) {
		int x = GetRandIndex(1, 10);
		int y = GetRandIndex(1, 10);
		if (mine[x][y] == '0') {
			mine[x][y] = '1';
			count++;
		}
	}
}
void ShowBoard(char board[][COL], int row, int col)
{
	printf("    ");
	int i = 1;
	for (; i <= 10; i++) {
		printf(" %d ", i);
	}
	printf("\n----");
	for (i = 1; i <= 10; i++) {
		printf("---");
	}
	printf("\n");
	for (i = 1; i <= 10; i++) {
		printf("%3d|", i);
		int j = 1;
		for (; j <= 10; j++) {
			printf("%2c|", board[i][j]);
		}
		printf("\n");
		int k = 1;
		for (k = 1; k <= 11; k++) {
			printf("---");
		}
		printf("\n");
	}
}
//'0'-'8'
char GetMines(char mine[][COL], int row, int col)//char->'0'-'8'
{
	return mine[row - 1][col - 1] + mine[row - 1][col] + \
		mine[row - 1][col + 1] + mine[row][col - 1] + mine[row][col + 1] + \
		mine[row + 1][col - 1] + mine[row + 1][col] + \
		mine[row + 1][col + 1] - 7 * '0';
}
void Game()
{
	char mine[ROW][COL];   //set/judge mine
	char board[ROW][COL]; //show
	memset(mine, '0', sizeof(mine));
	memset(board, '*', sizeof(board));

	SetMine(mine, ROW, COL);
	int count = TOTAL;
	int x = 0;
	int y = 0;
	int times = 0;
	while (1) {
		ShowBoard(board, ROW, COL);
		printf("请选择坐标: ");
		scanf("%d,%d", &x, &y);
		times++;
		if (x >= 1 && x <= ROW - 2 && y >= 1 && y <= COL - 2) {
			if (times == 1) {
				mine[x][y] = '0';
			}
			if (mine[x][y] == '0') {
				if (mine[x - 1][y - 1] == '0')
					board[x - 1][y - 1] = GetMines(mine, x - 1, y - 1);
				if(mine[x - 1][y] == '0')
					board[x - 1][y] = GetMines(mine, x - 1, y);
				if(mine[x - 1][y + 1] == '0')
					board[x - 1][y + 1] = GetMines(mine, x - 1, y + 1);
				if(mine[x][y - 1] == '0')
					board[x][y - 1] = GetMines(mine, x, y - 1);
				if(mine[x][y + 1] == '0')
					board[x][y + 1] = GetMines(mine, x, y + 1);
				if(mine[x + 1][y - 1] == '0')
					board[x + 1][y - 1] = GetMines(mine, x + 1, y - 1);
				if( mine[x + 1][y] == '0') 
					board[x + 1][y] = GetMines(mine, x + 1, y);
				if(mine[x + 1][y + 1] == '0' )
					board[x + 1][y + 1] = GetMines(mine, x + 1, y + 1);
				char num = GetMines(mine, x, y);
				board[x][y] = num;
				count--;
				if (count <= 20) {
					printf("你赢了，厉害！\n");
					break;
				}
			}
			else {
				printf("不好意思，你被炸死了！\n");
				ShowBoard(mine, ROW, COL);
				break;
			}
		}
		else {
			printf("你输入的坐标有误，请重新输入！\n");
		}
	}
}