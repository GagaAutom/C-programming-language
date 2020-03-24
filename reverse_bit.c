#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

unsigned int reverse_bit(unsigned int value) {
	int bit = 0, m = 0;
	int n = 32;
	while (n--) {
		bit = value & 1;
		m <<= 1;
		m |= bit;
		value >>= 1;
	}
	return m;
}

int main()
{
	unsigned int n;
	scanf("%d", &n);
	printf("%d\n", reverse_bit(n));
	system("pause");
	return 0;
}
