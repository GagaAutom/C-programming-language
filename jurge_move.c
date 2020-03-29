#include<stdio.h>
#include<Windows.h>
#pragma warning(disable:4996)

int jurge(char *a, char *b)
{
	int len1 = strlen(a);
	int len2 = strlen(b);
	if (len1 != len2) {
		return 0;
	}	
	int len = len1;
	while (len--) {
		char temp = *a;
		for (int i = 0; i < len1 - 1; i++) {
			a[i] = a[i + 1];
		}
		a[len1 - 1] = temp;
		if (strcmp(a, b) == 0) {
			return 1;
		}
	}
	len = len2;
	while (len--) {
		char temp = *(a + len2 - 1);
		for (int i = len - 1; i >= 0; i--) {
			a[i] = a[i - 1];
		}
		a[0] = temp;
		if (strcmp(a, b) == 0) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	char a[32];
	char b[32];
	printf("input two string :\n");
	scanf("%s", &a);
	scanf("%s", &b);
	int result = jurge(a, b);
	if (result == 0) {
		printf("no!");
	}
	else {
		printf("yes!");
	}
	system("pause");
	return 0;
}