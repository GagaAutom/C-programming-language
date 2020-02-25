#include <stdio.h>
void print1(int n)
{
	int i = 0;
	for (i = 31; i > 0; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
	for (i = 32; i > 0; i -= 2)
	{
		printf("%d", (n >> i) & 1);
	}
	printf("\n");
}

int main()
{
	int num;
    printf("请输入整数：");
    scanf("%d", &num);
	print1(num);
	system("pause");
}

//劣质版
//#include<stdio.h>
//#pragma warning(disable:4996)
//
//int main()
//{
//	int num;
//	printf("请输入整数：");
//	scanf("%d", &num);
//	int count = 0;
//	int a[32], b[32];
//	int i = 0, j = 0;
//	while (num) {
//		if (count % 2 == 0) {
//			a[i] = num % 2;
//			i++;
//		}
//		if (count % 2 == 1) {
//			b[i] = num % 2;
//			j++;
//		}
//		count++;
//	}
//	for (i = 0; i < 32; i++) {
//		printf("%d",a[i]);
//	}
//	printf("\n");
//	for (j = 0; j < 32; i++) {
//		printf("%d", b[i]);
//	}
//	system("pause");
//	return 0;
//}