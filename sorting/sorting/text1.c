#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	int i, j, k, t;
	printf("please input number\n");
	scanf("%d %d %d", &i, &j, &k);
	if (k > j)
	{
		t = k;
		k = j;
		j = t;
	}
	t = 0;
	if (k > i)
	{
		t = k;
		k = i;
		i = t;
	}
	t = 0;
	if (j > i)
	{
		t = j;
		j = i;
		i = t;
	}
	printf("the sorting: %d %d %d", i, j, k);
	system("pause");
	return 0;
}