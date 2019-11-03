#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
int main()
{
	int a[10], i, max=0;
	printf("please input number:\n");
	for (i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	for (i = 0; i < 10;i++)
		if (a[i] > max)
			max = a[i];
	printf("the max :%d", max);
	system("pause");
	return 0;
}