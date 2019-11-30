#include <stdio.h>
#pragma warning (disable:4996)

void mul(int m)
{
	int i, j;
	for (i = 1; i <= m; i++) {
		for (j = 1; j <= i; j++) {
			printf("%d*%d=%2d  ", i, j, i*j);
		}
		printf("\n");
	}
}

int main() {
	int n;
	while (1) {
		printf("You want _*_ ?\n");
		printf("Enter 0 to exit.\n");
		scanf("%d", &n);
		mul(n);
		if (0 == n) {
			printf("Bye bye!\n");
			break;
		}
	}
	system("pause");
	return 0;
}