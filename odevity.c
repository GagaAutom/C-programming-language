#include<stdio.h>
#include<Windows.h>

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,0 };
	int n = sizeof(a) / sizeof(a[0]);
	int b[10];
	int o = 0, j = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 != 0) {
			b[j] = a[i];
			j++;
		}
		else {
			b[n / 2 + o] = a[i];
			o++;
		}
	}
	for (int i = 0; i < n; i++) {
		printf("%3d", b[i]);
	}
	system("pause");
	return 0;
}