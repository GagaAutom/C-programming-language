#include<stdio.h>
int main()
{
	int i = 62, j = 24;
	printf("%d  %d\n", i, j);
	i = i+j;
	j = i-j;
	i = i-j;
	printf("After change :%d  %d\n", i, j);
	system("pause");
	return 0;
}