#include<stdio.h>
int main()
{
	int a, b, c, x;
	for (a = 100; a <= 999; a++){
		x = a / 100;
		c = (a - x * 100) / 10;
		b = a % 10;
		if (a == x * x*x + c * c*c + b * b*b)
			printf("%d\t", a);
	}
	printf("是水仙花数\n");
	system("pause");
	return 0;
}