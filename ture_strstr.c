#include <stdio.h>
#include <Windows.h>
#include<assert.h>
#pragma warning(disable:4996)

char *my_strstr(const char* str1, const char* str2)
{
	assert(str1);
	assert(str2);

	char *cp = (char*)str1;
	char *substr = (char *)str2;
	char *s1 = NULL;

	if (*str2 == '\0')
		return NULL;

	while (*cp)
	{
		s1 = cp;
		substr = str2;
		while (*s1 && *substr && (*s1 == *substr))
		{
			s1++;
			substr++;
		}
		if (*substr == '\0')
			return cp;
		cp++;
	}
}

int main()
{
	char str[] = "This is a simple string";
	char * pch;
	pch = my_strstr(str, "simple");
	strncpy(pch, "sample", 6);
	puts(str);
	system("pause");
	return 0;
}