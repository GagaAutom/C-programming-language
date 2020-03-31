#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int main()
{
	int soda;
	int sum = 0;
	int nul = 0;
	printf("how money?\n");
	scanf("%d", &soda);
	sum = soda;
	while (soda > 0) {
		soda += nul;
		sum += (soda / 2);
		nul = soda % 2;
		soda /= 2;
	}
	printf("%d", ++sum);
	system("pause");
	return 0;
}