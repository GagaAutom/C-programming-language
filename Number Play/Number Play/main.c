#include<stdio.h>
#include<windows.h>
#include<time.h>
#pragma warning(disable:4996)
const char *name = "xuenuo";
const char *key = "104934";

void Showtime();
void Login();
void Game();
void Play();

void Login()
{
	int chance = 3;
	int time = 1;
	while (chance > 0) {
		char N[50];
		char K[50];
		printf("Please Enter your name:\n");
		scanf("%s", &N);
		printf("Please Enter your key:\n");
		scanf("%s", &K);
		if (0 == strcmp(name, N) && 0 == strcmp(key, K)) {
			Showtime();
			break;
		}
		else {
			printf("Your Enter Message Is Error!\n");
			chance--;
			printf("You have %d more chances\n", chance);
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

void Game()
{
	while (1) {
		int select = 0;
		printf("###################################\n");
		printf("######### 1. Play   2. Exit #######\n");
		printf("###################################\n");
		printf("Please Select: ");
		scanf("%d", &select);
		switch (select)
		{
		case 1:
			Play();
			break;
		case 2:
			printf("See you again!\n");
			return;
		default:
			printf("Enter Error! Try Again\n");
			break;
		}
	}

}

void Play()
{
	srand((unsigned long)time(NULL));
	int x = rand() % 200 + 1;//[1..200]
	int data;
	while (1) {
		printf("Guess: ");
		scanf("%d", &data);
		if (data > x) {
			printf("guess Big!\n");
		}
		else if (data < x) {
			printf("guess Small!\n");
		}
		else {
			printf("guess Right!\n");
			break;
		}
	}
}

int main()
{
    Login();
	Game();
	system("pause");
	return 0;
}