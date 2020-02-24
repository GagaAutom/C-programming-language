#include<stdio.h>
#include<windows.h>
void reverse_string(char *p)
{
	int len = strlen(p);
	char tmp = *p;
	*p = *(p + len - 1);
	*(p + len - 1) = '\0';
	if (strlen(p + 1) > 1)
	{
		reverse_string(p + 1);
	}
	*(p + len - 1) = tmp;
}
int main()
{
	char str[] = "abcdef";
	printf("%s\n", str);
	reverse_string(str);
	printf("%s\n", str);
	system("pause");
	return 0;
}