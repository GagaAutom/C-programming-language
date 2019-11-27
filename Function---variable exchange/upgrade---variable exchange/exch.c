#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)
int Exch(int *i, int *j)
{
	int temp = 0;
	temp = *j;
	*j = *i;
	*i = temp;
}

int main() 
{
	int a, b;
	printf("Please input numbers:\n");
	scanf("%d %d", &a, &b);
	Exch(&a, &b);
	printf("After exchang:%d  %d\n", a, b);
	system("pause");
	return 0;
}