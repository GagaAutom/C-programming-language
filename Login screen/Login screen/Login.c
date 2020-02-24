#include<stdio.h>
#include<windows.h>
#pragma warning(disable:4996)
const char *name = "xuenuo";
const char *key = "104934";

void Showtime()
{
	char word_str[] = "Login success!";
	char sym_str[] = "##############";
	int left = 0;
	int right = strlen(word_str) - 1;
	printf("%s\n", sym_str);
	while (left <= right) {
		sym_str[left] = word_str[left];
		sym_str[right] = word_str[right];
		printf("%s\r", sym_str);
		left++, right--;
		Sleep(500);
	}
	printf("\n");
}

void Login()
{
	int chance = 3;
	int time = 1;
	while (chance > 0) {
		char _name[50];
		char _key[50];
		printf("Please Enter your name:\n");
		scanf("%s", &_name);
		printf("Please Enter your key:\n");
		scanf("%s", &_key);
		if (0 == strcmp(name, _name) && 0 == strcmp(key, _key)) {
			Showtime();
			break;
		}
		else {
			printf("Your Enter Message Is Error!\n");
			chance--;
			printf("You have %d more chances\n",chance);
		}
		if (chance <= 0) {
			printf("You have no chance,Lock %d s,Wait....\n", time * 10);
			Sleep(10000 * time);
			chance = 3;
			time++;
			if (time >= 3) {
				printf("You never get a chance!\n");
				break;
			}
		}
	}
}

int main()
{
	Login();
	system("pause");
	return 0;
}