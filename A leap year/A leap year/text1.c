#include <stdio.h>
int main()
{
	int i;
	for (i = 1000; i <= 2000; i++)
	{
		if (i % 100 != 0)
		{
			if (i % 4 == 0)//根据闰年定义，首先不能被100整除的普通年，如果能被4整除则为闰年
				printf("%d\t", i);
		}
		else if (i % 400 == 0)//如果是能被100整除的世纪年，若能被400整除，则为闰年
			printf("%d\t", i);
		/*if (i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
			printf("%d\t", i);*/
	}
	system("pause");
	return 0;
}