#include<stdio.h>
#include<Windows.h>

int print(int n)
{
	if (n > 9) {
		print(n / 10);
	}
	printf("%d", n % 10);
}

int main()
{
	int n = 123456;
	print(n);
	system("pause");
	return 0;
}