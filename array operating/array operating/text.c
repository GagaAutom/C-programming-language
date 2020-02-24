#include<stdio.h>
#include<windows.h>
#pragma warning (disable:4996)
void init(int *b[10])
{
	int i = 0;
	for (; i < 10; i++) {
		*(b+i) = i;
	}
}

void empty(int *c[10])
{
	int j = 0;
	for (; j < 10; j++) {
		*(c + j) = 0;
	}
}

void reverse(int *d[10])
{
	int tmp;    
		for (int i = 0; i < 9 / 2; i++)
		{
			tmp = d[i];
			d[i] = d[9 - i];
			d[9 - i] = tmp;
		}
}

int main()
{
	int a[10];
	init(&a);
	int k = 0;
	for (; k < 10; k++) {
		printf("%-3d", a[k]);
	}
	printf("\n");
	reverse(&a);
	for (k = 0; k < 10; k++) {
		printf("%-3d", a[k]);
	}
	printf("\n");
	empty(&a);
	for (k = 0; k < 10; k++) {
		printf("%-3d", a[k]);
	}
	printf("\n");
	system("pause");
	return 0;
}