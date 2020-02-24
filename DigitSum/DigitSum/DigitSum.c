#include<stdio.h>
#include<Windows.h>

int DigitSum(int n)
{
	if (n < 10) {
		return n;
	}
	else {
		return n % 10 + DigitSum(n / 10);
	}
}

int main()
{
	printf("%d\n", DigitSum(1729));
	system("pause");
	return 0;
}