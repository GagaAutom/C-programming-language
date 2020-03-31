#include <stdio.h>
#include <string.h>
#include <Windows.h>
#pragma warning(disable:4996)

char * _strcat(char * destination, const char * source)
{
	int i = 0;
	int count = 0;
	while (source[count] != '\0') {
		if (destination[i] == '\0') {
			destination[i] = source[count];
			destination[i + 1] = '\0';
			count++;
		}
		i++;
	}
	destination[i + count] = '\0';
	return destination;
}

int main()
{
	char str[80];
	strcpy(str, "these ");
	_strcat(str, "strings ");
	_strcat(str, "are ");
	_strcat(str, "concatenated.");
	puts(str);
	system("pause");
	return 0;
}