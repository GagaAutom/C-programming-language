#include <stdio.h>
#include <Windows.h>
#include<assert.h>
#pragma warning(disable:4996)

char *my_strcat(char *dest, const char*src) {
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);
	while (*dest)
	{
		dest++;
	}
	while ((*dest++ = *src++))
	{
		;
	}
	return ret;
}
int main()
{
	char str1[20];
	char str2[20];
	strcpy(str1, "To be ");
	strcpy(str2, "or not to be");
	my_strcat(str1, str2);
	puts(str1);
	system("pause");
	return 0;
}