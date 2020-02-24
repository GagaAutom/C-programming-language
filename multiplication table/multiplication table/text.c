#include <stdio.h> 
#include <windows.h>
int main()
{
	int i, j;
	for (i = 1; i < 10; i++)//循环嵌套，使被乘数1~9遍历
	{
		for (j = 1; j < 10; j++)//循环嵌套，使乘数1~9遍历
		{
			Sleep(1000);
			printf("%d*%d=%d\t", i, j, i*j);
		}
		printf("\n");
	}	
	system("pause");
	return 0;
}