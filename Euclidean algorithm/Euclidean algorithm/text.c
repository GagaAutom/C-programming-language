#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int main()
{
	int num1, num2, temp, i;
	printf("please input number:\n");
	scanf("%d %d", &num1, &num2);
	if (num1 < num2)
	{
		temp = num1;
		num1 = num2;
		num2 = temp;
	}
	temp = 0;
	while (1) {
		temp = num1 % num2;
		if (0 == temp)
			break;
		else {
			num1 = num2;
			num2 = temp;
		}
	}
	printf("the max common divisor : %d\n", num2);
	system("pause");
	return 0;
}