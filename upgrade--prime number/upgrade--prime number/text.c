#include <stdio.h>
#include <math.h>
int main()
{
	int i, j;//i为被除数，j为除数
	int k;//暂存的平方根结果
	for (i = 100; i <= 200; i++)
	{
		k = (int)sqrt((double)i);// 求平方根，注意sqrt()的参数为 double 类型，这里要强制转换i的类型
		for (j = 2; j < k; j++)
		{
			if (i % j == 0)
				break;
		}
		if (j >= k)
			printf("%d\t", i);
	}
	system("pause");
	return 0;
}