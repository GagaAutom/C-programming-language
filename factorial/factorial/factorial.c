#include<stdio.h>
#include<Windows.h>

int fact(int n)
{
	if (n <= 1) {
		return 1;
	}
	else {
		return n * fact(n - 1);
	}
}

int factor(int n)
{
	int i = 1;
	int sum = 1;
	for (; i <= n; i++) {
		sum *= i;
	}
	return sum;
}

int main()
{
	printf("%d,%d\n", fact(5), factor(5));
	system("pause");
}