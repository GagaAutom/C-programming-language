#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

void left(char *a, int str, int step)
{
	while (step--) {
		char temp = *a;
		for (int i = 0; i < str - 1; i++) {
			a[i] = a[i + 1];
		}
		a[str - 1] = temp;
	}
}

int main()
{
	char a[] = "ABCDEF";
	int str = strlen(a);
	int num = 0;
	printf("what steps you want?\n");
	scanf("%d", &num);
	if (num <= 0 && num > str) {
		printf("after:%s\n", a);
	}
	else {
		left(a, str, num);
		printf("after:%s\n", a);
	}
	system("pause");
	return 0;
}