#include<stdio.h>
int main()
{
	int i, j;
	for (i = 0; i <= 6; i++) {
		for (j = 0; j <= 2 * i; j++) {
			printf("*");
		}
		printf("\n");
	}
	for (i = 0; i <= 6; i++) {
		for (j = 0; j <= 10 - 2 * i; j++) {
			printf("*");
		}
		printf("\n");
	}
	system("pause");
	return 0;
}