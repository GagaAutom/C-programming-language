#include<stdio.h>
int main()
{
	int i;
	float sum = 0;
	for (i = 1; i <= 100; i++) {
		if (i % 2 == 1){
			sum += (1.0/(float)i);
		}
		if (i % 2 == 0) {
			sum -= (1.0/(float)i);

		}
	}
	printf("so 1/1+1/2+......+1/99+1/100= %f", sum);
	system("pause");
	return 0;
}