#include<stdint.h>
#include<Windows.h>
#include<string.h>
#include<assert.h>

char * my_strncpy(char * destination, const char * source, size_t num)
{
	char *ret = destination;
	assert(destination != NULL);
	assert(source != NULL);

	while (num--)
	{
		*destination++ = *source++;
	}
	return ret;
}

int main()
{
	char str1[] = "To be or not to be";
	char str2[40];
	char str3[40];

	/* copy to sized buffer (overflow safe): */
	my_strncpy(str2, str1, sizeof(str2));

	/* partial copy (only 5 chars): */
	my_strncpy(str3, str2, 5);
	str3[5] = '\0';   /* null character manually added */

	puts(str1);
	puts(str2);
	puts(str3);
	system("pause");
	return 0;
}