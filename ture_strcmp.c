#include <stdio.h>
#include <Windows.h>
#include<assert.h>
#pragma warning(disable:4996)

int my_strcmp(const char * src, const char * dest) {
	int ret = 0;
	assert(src != NULL);
	assert(dest != NULL);
	while (!(ret = *(unsigned char *)src - *(unsigned char *)dest) && *dest)
		++src, ++dest;
	if (ret < 0)
		ret = -1;
	else if (ret > 0)
		ret = 1;
	return(ret);
}

int main()
{
	char str[][5] = { "R2D2" , "C3PO" , "R2A6" };
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n < 3; n++)
		if (my_strcmp(str[n], "R2D2") == 0)
		{
			printf("found %s\n", str[n]);
		}
	system("pause");
	return 0;
}