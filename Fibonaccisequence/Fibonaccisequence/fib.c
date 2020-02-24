#include"fib.h"

int fib(int n)
{
	if (n <= 2)
		return 1;
	else
		return fib(n - 1) + fib(n - 2);
}

int fib1(int n)
{
	int first = 1;
	int second = 1;
	int third = 1;
	while (n > 2) {
		third = first + second;
		first = second;
		second = third;
		n--;
	}
	return third;
}

