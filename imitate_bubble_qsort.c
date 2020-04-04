#include<stdio.h>
#include<Windows.h>

int int_cmp(const void *x, const void *y)
{
	const int *_x = (int *)x;
	const int *_y = (int *)y;
	if (*_x > *_y) {
		return 1;
	}
	else if (*_x < *_y) {
		return -1;
	}
	else {
		return 0;
	}
}

void my_swap(const void *xp, const void *yp, size_t size) {
	for (size_t i = 0; i < size; i++) {
		char temp = *((char *)xp + i);
		*((char *)xp + i) = *((char*)yp + i);
		*((char*)yp + i) = temp;
	}
}

void my_qsort(void* base, size_t num, size_t size, int(*compar)(const void*, const void*))
{
	for (size_t i = 0; i < num - 1; i++) {
		for (size_t j = 0; j < num - i - 1; j++) {
			if (compar((char *)base + j * size, (char *)base + (j + 1)*size) > 0) {
				my_swap((char*)base + j * size, (char *)base + (j + 1)*size, size);
			}
		}
	}
}

int main()
{
	int a[10] = { 10,29,4,5,23,63,23,66,27,72 };

	my_qsort(a, sizeof(a) / sizeof(a[0]), sizeof(int), int_cmp);

	for (int i = 0; i < sizeof(a) / sizeof(a[0]); i++) {
		printf("%3d", a[i]);
	}
	printf("\n");
	system("pause");
	return 0;
}