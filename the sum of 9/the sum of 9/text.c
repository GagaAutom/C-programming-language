#include<stdio.h>
int main()
{
	int i, sum = 0;
	for (i = 1; i <= 100; i++) {
		if (i % 10 == 9) {
			sum++;
		}
		if (i / 10 == 9) {
			sum++;
		}
		if (i == 99) {
			sum--;
		}
	}
	printf("the sum of 9 : %d", sum);
	system("pause");
	return 0;
}