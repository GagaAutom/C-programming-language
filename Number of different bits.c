#include<stdio.h>
#pragma warning(disable:4996)

int count_different_bits(int x, int y)
{
	int num = 0;
	int count = 0;
	num = x ^ y;
	while (num) {
		num &= (num - 1);
		count++;
	}
	return count;
}

int main()
{
	int m, n;
	printf("请输入整数m：");
	scanf("%d", &m);
	printf("请输入整数n：");
	scanf("%d", &n);
	printf("m , n共有 %d 的比特位不同\n", count_different_bits(m, n));
	system("pause");
	return 0;
}