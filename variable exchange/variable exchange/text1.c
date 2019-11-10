#include<stdio.h>
int main()
{
	int i=62, j=24, t=0;
	printf("%d  %d\n", i, j);
	t = j;
	j = i;
	i = t;
	printf("After change :%d  %d\n", i, j);
	system("pause");
	return 0;
}