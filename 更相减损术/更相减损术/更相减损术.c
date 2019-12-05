#include<stdio.h>
#include<windows.h>
#include<math.h>
#pragma warning(disable:4996)

int main()
{
	int num1, num2, temp = 0, times = 0, i = 0;
	printf("please input number:\n");
	scanf("%d %d", &num1, &num2);
	while(0 == num1 % 2 && 0 == num2 % 2) {
		num1 = num1 / 2;
		num2 = num2 / 2;
		times++;
	}
	while (1) {
		if (num1 < num2)
		{
			i = num1;
			num1 = num2;
			num2 = i;
		}
		temp = num1 - num2;
		num1 = temp;
		if (temp == num2) {
			printf("the max common divisor : %d\n", temp*(int)pow(2, times));
			break;
		}
	}
	system("pause");
	return 0;
}