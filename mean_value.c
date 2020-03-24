#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int _math(int a,int b)
{
	int avg = a - (a - b) / 2;
	return avg;
}

int no_math(int a, int b)
{
	return (((a^b) >> 1) + (a&b));
}

int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n", _math(a, b));
	printf("%d\n", no_math(a, b));
	system("pause");
	return 0;
}