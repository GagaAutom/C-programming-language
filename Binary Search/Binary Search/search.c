#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)

int Search(int a[], int n, int y)
{
	int L = 0;
	int R = n - 1;
	while (L < R) {
		int mid = (L + R) / 2;
		if (y > a[mid]) {
			L = mid + 1;
		}
		else if (y < a[mid]) {
			R = mid - 1;
		}
		else {
			return 1;
		}
	}
	return 0;
}


int main()
{
	int a[] = { 0,1,3,4,6,7,9,19,32,37 };
	int num = sizeof(a) / sizeof(a[0]);
	int b = 0;
	int result = 0;
	printf("Please Enter your number:\n");
	while(1){
		scanf("%d", &b);
		result = Search(a, num, b);
		if (result){
			printf("Yes!you get!");
			break;
		}
		else{
			printf("No!you don't get!Please try again:\n");
		}
	}
	system("pause");
	return 0;
}