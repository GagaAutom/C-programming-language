#include<stdio.h>
#include<windows.h>
#include<string.h>

int main()
{
	while (1) {
		char a[50];
		printf("Please Enter a string or a char:\n");
		gets(a);
		int i = 0;
		int num = strlen(a);
		for (; i < num + 1; i++) {
			if (a[i] >= 'a' && a[i] <= 'z') {
				a[i] -= 32;
				printf("After change :%c\n", a[i]);
			}
			else if (a[i] >= 'A' && a[i] <= 'Z') {
				a[i] += 32;
				printf("After change :%c\n", a[i]);
			}
			else {
				printf("Enter Error! Try Again\n");
				continue;
			}
		}
	}
	system("pause");
	return 0;
}