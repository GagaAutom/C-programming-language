#include <stdio.h>
int main()
{
	int i, j;
	for (i = 101; i <= 200; i+=2)//偶数肯定有2的因数，可以直接规避偶数，使用奇数循环
	{
		for (j = 2; j < i; j++)
		{
			if (i%j == 0)
				break; 
		}
		if (j >= i)//当被除数从j的循环中自然流出，而不是被break跳出，说明该数不能被2到该数前的所有数整除
			printf("%d\t", i);
	}
	system("pause");
	return 0;
}