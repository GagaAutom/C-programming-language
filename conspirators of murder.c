#include<stdio.h>

int main()
{
	char killer;
	for (killer = 'A'; killer <= 'D'; killer++) {
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D')){
			printf("Ð×ÊÖÊÇ%c\n", killer);
			system("pause");
			return 0;
		}
	}
}