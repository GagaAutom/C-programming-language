#include <stdio.h>
#include <Windows.h>
#include<string.h>
#include<assert.h>
#pragma warning(disable:4996)

char * my_strncat(char * destination, const char * source, size_t num)
{
	char *ret = destination;
	assert(destination != NULL);
	assert(source != NULL);
	while (*destination)
	{
		destination++;
	}
	while (num--)
	{
		*destination++ = *source++;
	}
	*destination = '\0';
	return ret;
}


int main()
{
	char str1[20];
	char str2[20];
	strcpy(str1, "To be ");
	strcpy(str2, "or not to be");
	my_strncat(str1, str2, 6);
	puts(str1);
	system("pause");
	return 0;
}