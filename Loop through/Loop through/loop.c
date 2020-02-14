#include<stdio.h>
#pragma warning(disable:4996)

int main()
{
	int a[] = { 0,1,3,4,6,7,9,19,32,37 };
	int num = sizeof(a) / sizeof(a[0]);
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	for (; i < num; i++) {
		if (a[i] == n) {
			printf("ture\n");
			break;
		}
	}
	if (i >= num) {
		printf("false\n");
	}
	system("pause");
	return 0;
}