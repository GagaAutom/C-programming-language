#include<stdio.h>
#include<Windows.h>

int find(int a[],int m)
{
	int l = 0;
	int n = 9;
	int r = n - 1;
	while (l < r) {
		int mid = (l + r) / 2;
		if (a[mid] > m) {
			r = mid - 1;
		}
		else if (a[mid] == m) {
			return 1;
		}
		else {
			l = mid + 1;
		}
	}
	return 0;
}

int main()
{
	int a[3][3] = { {1,2,3},{4,5,6},{7,8,9} };
	int m = 5;
	int resalt = find(a,m);
	if (resalt == 0) {
		printf("No\n");
	}
	else {
		printf("Yes\n");
	}
	system("pause");
	return 0;
}