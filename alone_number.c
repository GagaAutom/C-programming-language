#include<stdio.h>
#include<Windows.h>

int int_cmp(const void *xp,const void *yp)
{
	int *_xp = (int*)xp;
	int *_yp = (int*)yp;
	if (*_xp > *_yp){
		return 1;
	}
	else {
		return -1;
	}
}

int main()
{
	int a[20] = { 1,1,2,2,3,3,4,5,6,6,7,7,8,8,9,9,0,0 };
	int size = sizeof(a) / sizeof(a[0]);
	qsort(a, size, sizeof(int), int_cmp);
	for (int i = 0; i < size; i++) {
		if (a[i] == a[i + 1]) {
			i++;
			continue;
		}
		else {
			printf("%3d",a[i]);
		}
	}
	system("pause");
	return 0;
}