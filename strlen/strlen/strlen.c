#include<stdio.h>
#include<Windows.h>

int strlen(char *str)
{
	if (*str == '\0') {
		return 0;
	}
	else {
		return 1 + strlen(str + 1);
	}
}

int strlen1(char *str)
{
	int size = 0;
	while (*str != '\0') {
		size++;
		str++;
	}
	return size;
}

int main()
{
	char *p = "abcdef";
	int len = strlen(p);
	int len1 = strlen1(p);
	printf("%d,%d\n", len, len1);
	system("pause");
	return 0;
}