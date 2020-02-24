#include <stdio.h>
#pragma warning (disable:4996)
int main() {
	int i, j, n;
	while (1) {
		printf("You want _*_ ?\n");
		printf("Enter 0 to exit.\n");
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= i; j++) {
				printf("%d*%d=%2d  ", i, j, i*j);
			}
			printf("\n");
		}
		if (0 == n) {
			break;
		}
	}
	system("pause");
	return 0;
}
//#include <stdio.h>
//int main() 
//{
//	int i, j;
//	for (i = 1; i <= 9; i++) {
//		for (j = 1; j <= 9; j++) {
//			if (j < i)
//				//打印八个空格，去掉空格就是左上三角形 
//				printf("        ");
//			else
//				printf("%d*%d=%2d  ", i, j, i*j);
//		}
//
//		printf("\n");
//	}
//	system("pause");
//	return 0;
//}