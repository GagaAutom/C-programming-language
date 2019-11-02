#pragma warning(disable:4996)
#include <stdio.h> 
int main()
{
	int  a, n, i = 1, sn = 0, tn = 0;
	printf("the number and numbers:\n");
	scanf("%d %d", &a, &n);
	for (; i <= n; i++) {
		tn = tn + a;
		sn = sn + tn;
		a = a * 10;
	}
	printf("a+aa+aaa+...=%d\n", sn);
	system("pause");
	return 0;
}