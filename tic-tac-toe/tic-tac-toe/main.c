#include "chess.h"

void ShowMenu()
{
	printf("################################\n");
	printf("## 1.Play              2.Exit ##\n");
	printf("################################\n");
	printf("Please Select:");
}

int main()
{
	int select = 0;
	int quit = 0;
	while (!quit) {
		ShowMenu();
		scanf("%d", &select);
		switch (select) {
		case 1:
			Game();
			break;
		case 2:
			printf("Bye be!\n");
			quit = 1;
			break;
		default:
			printf("select error,try again!\n");
			break;
		}
	}
	system("pause");
	return 0;
}