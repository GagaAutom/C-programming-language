#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int count_one_bits(unsigned int value)
{
	int count = 0;
	while (value) {
		value &= (value - 1);
		count++;
	}
	return count;
}

int main()
{
	int num = 0;
	printf("请输入无符号整数：");
	scanf("%d", &num);
	printf("其二进制数中1的个数为：%d\n",count_one_bits(num));
	system("pause");
	return 0;
}