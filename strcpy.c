#include <stdio.h>
#include <Windows.h>
#pragma warning(disable:4996)

char * _strcpy(char * destination, const char * source)
{
	int i = 0;
	while (source[i] != '\0') {
		destination[i] = source[i];
		i++;
	}
	destination[i] = '\0';
	return destination;
}

int main()
{
	char str1[] = "Sample string";
	char str2[40];
	_strcpy(str2, str1);
	printf("str1: %s\nstr2: %s\nstr: %s\n", str1, str2, _strcpy(str2, str1));
	system("pause");
	return 0;
}