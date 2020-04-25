#include"contact.h"


void menu() {
	printf("******************ͨѶ¼********************\n");
	printf("*** 1.add   2.show    3.delete 4.search ****\n");
	printf("*** 5.empty 6.distory 7.save   8.load   ****\n");
	printf("***************** 0.quit *******************\n");
	printf("********************************************\n");
}

int main()
{
	int select = 0;
	Contact contact;
	InitContact(&contact);
	do{
		menu();
		printf("Pleas intput you changce:");
		scanf("%d", &select);

		switch (select)
		{
		case QUIT: 
			printf("Good bye!\n");
			break;
		case ADD:
			AddContact(&contact);
			break;
		case SHOW:
			ShowContact(&contact);
			break;
		case DEL:
			DelContact(&contact);
			break;
		case SEARCH:
			SearchContact(&contact);
			break;
		case EMPTY:
			EmptyContact(&contact);
			break;
		case DESTORY:
			DestoryContact(&contact);
			break;
		case SAVE:
			SaveContact(&contact);
			break;
		case LOAD:
			LoadContact(&contact);
			break;
		default:
			break;
		}
	} while (select);
	system("pause");
	return 0;
}