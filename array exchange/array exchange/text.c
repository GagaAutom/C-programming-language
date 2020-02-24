#pragma warning(disable:4996)
#include<stdio.h>
int exch(int *arr1, int *arr2)
{
	int j;
	int t;
	for (j = 0; j < 10; j++)
	{
		t = arr1[j];//也可以使用*(arr1+j)
		arr1[j] = arr2[j];
		arr2[j] = t;
	}
}
int main()
{
	int a[10], b[10];
	int i;
	printf("please input a:\n");
	for (i = 0; i < 10; i++){
		scanf("%d", &a[i]);
	}
	printf("please input b:\n");
	for (i = 0; i < 10; i++) {
		scanf("%d", &b[i]);
	}
	exch(&a, &b);
	printf("after exchange a:");
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", a[i]);
	}
	printf("\nafter exchange b:");
	for (i = 0; i < 10; i++)
	{
		printf("%d\t", b[i]);
	}
	system("pause");
	return 0;
}
