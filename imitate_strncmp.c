#include <stdio.h>
#include <Windows.h>
#include<assert.h>
#pragma warning(disable:4996)

int my_strncmp(const char * str1, const char * str2, size_t num)
{
	int ret = 0;
	assert(str1 != NULL);
	assert(str2 != NULL);
	while (!(ret = *(unsigned char *)str1 - *(unsigned char *)str2) && --num)
		++str1, ++str2;
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	return ret;
}

int main()
{
	char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n < 3; n++)
		if (my_strncmp(str[n], "R2xx", 2) == 0)
		{
			printf("found %s\n", str[n]);
		}
	system("pause");
	return 0;
}