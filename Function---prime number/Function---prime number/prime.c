#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

void prime(int m)
{
	int k, j;
	k = (int)sqrt((double)m);
	for (j = 2; j < k; j++)
	{
		if (0 == m % j)
			printf("Not a prime number!Please try again...\n");
			break;
	}
	if (j >= k)
		printf("%d is a prime number\n", m);
}

int main()
{
	int n;
	printf("Please Enter a number:\n");
	scanf("%d", &n);
	prime(n);
	system("pause");
	return 0;
}