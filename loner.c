#include<stdio.h>
#include<Windows.h>

int _catch(int a[])
{
	for (int i = 0; i < 11; i++) {
		for (int j = 0; j < 11; j++) {
			if (a[i] ^ a[j] != 0)
				return a[i];
		}
	}
}
int main()
{
	int a[11] = { 1,1,2,3,3,4,4,5,5,6,6 };
	printf("%d\n", _catch(a));
	system("pause");
	return 0;
}