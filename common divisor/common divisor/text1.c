#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int num1, num2, temp, i;
	printf("please input number:\n");
	scanf("%d %d", &num1, &num2);
	//if (num1 < num2)
	//{
	//	temp = num1;
	//	num1 = num2;
	//	num2 = temp;
	//}
	temp = 0;
	for (i = 1; i < num1; i++)
	{
		if (num1%i == 0 && num2%i == 0)
		{
			temp = i;
		}
	}
	printf("the max common divisor : %d\n", temp);
	system("pause");
	return 0;
}