#include"test.h"

int exp(int n, int k)
{
	if (n == 0) {
		return 0;
	}
	if (n == 1) {
		return 1;
	}
	if (k == 0) {
		return 1;
	}
	else {
		return exp(n, k - 1) * n;
	}
}