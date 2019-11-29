#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int Year(int y)
{
	if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0) {
		printf("%d is a leap year!\n", y);
		return 0;
	}
	else {
		printf("Not a leap year!Please try again...\n");
	}
}

int main()
{
	int x, t;
	printf("Please Enter a year :\n");
	while (1) {
		scanf("%d", &x);
		t = Year(x);
		if (0 == t) {
			break;
		}
	}
	system("pause");
	return 0;
}