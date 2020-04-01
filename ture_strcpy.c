#include <stdio.h>
#include <Windows.h>
#include<assert.h>
#pragma warning(disable:4996)

char *my_strcpy(char *dest, const char*src)
{
	char *ret = dest;
	assert(dest != NULL);
	assert(src != NULL);

	while ((*dest++ = *src++))
	{
		;
	}
	return ret;
}
int main()
{
	char str1[20];
	my_strcpy(str1, "To be ");
	puts(str1);
	system("pause");
	return 0;
}