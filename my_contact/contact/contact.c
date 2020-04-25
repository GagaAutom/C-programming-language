#include "contact.h"

//初始化通讯录 
void InitContact(Contact *pcon) {
	//普通版本
	//pcon->usedSize = 0; 
	//memset(pcon->per,0,sizeof(pcon->per));

	pcon->usedsize = 0;
	pcon->capacity = DEFAULT_SIZE;
	pcon->per = (PersonInfo *)malloc(
		sizeof(PersonInfo) * pcon->capacity);
	assert(pcon->per != NULL);

	LoadContact(pcon);
}
//添加成员 
void AddContact(Contact *pcon) {
	//普通版本，无扩容解决办法
	//if(pcon->usedSize == MAX_NUMBER)
	//{
	//	printf("this contact is full\n");
	//	return;
	//}

	if (CheckFullAndRe(pcon) != 1)
	{
		printf("扩容失败\n");
		return;
	}

	printf("请输入姓名：");
	scanf("%s", pcon->per[pcon->usedsize].name);
	printf("请输入年龄：");
	scanf("%d", &(pcon->per[pcon->usedsize].age));
	printf("请输入性别：");
	scanf("%s", pcon->per[pcon->usedsize].sex);
	printf("请输入电话：");
	scanf("%s", pcon->per[pcon->usedsize].tele);
	printf("请输入住址：");
	scanf("%s", pcon->per[pcon->usedsize].addr);
	pcon->usedsize++;
	printf("添加成功\n");
}
//打印通讯录 
void ShowContact(Contact *pcon) {
	int i = 0;
	printf("%-10s %-5s %-5s %-11s %-20s\n", "姓名", "年龄",
		"性别", "电话", "住址");
	for (i = 0; i < pcon->usedsize; i++)
	{
		printf("%-10s %-5d %-5s %-11s %-20s\n",
			pcon->per[i].name, pcon->per[i].age,
			pcon->per[i].sex, pcon->per[i].tele,
			pcon->per[i].addr);
	}
}
//删除成员 
void DelContact(Contact *pcon) {
	int index = SearchContact(pcon);
	int i = 0;
	if (index == -1)
	{
		printf("删除失败，查无此人\n");
		return;
	}
	for (i = index; i < pcon->usedsize - 1; i++)
	{
		pcon->per[i] = pcon->per[i + 1];
	}
	pcon->usedsize--;
	printf("删除成功\n");
}
//查找成员 
int SearchContact(Contact *pcon) {
	int i = 0;
	char name[MAX_NAME] = { 0 };
	if (pcon->usedsize == 0)
	{
		printf("通讯录为空\n");
		return -1;
	}
	printf("请输入你要删除的姓名：");
	scanf("%s", name);
	for (i = 0; i < pcon->usedsize; i++)
	{
		if (strcmp(pcon->per[i].name, name) == 0)
		{
			return i;
		}
	}
	return -1;
}
//清空通讯录 
void EmptyContact(Contact *pcon) {
	pcon->usedsize = 0;
}
//摧毁通讯录(动态版本) 
void DestoryContact(Contact *pcon) {
	SaveContact(pcon);
	free(pcon->per);
	pcon->per = NULL;//预防野指针  
	pcon->capacity = 0;
	pcon->usedsize = 0;
}
//文件版本 //保存联系人到文件 
void SaveContact(Contact *pcon) {
	int i = 0;
	FILE *pf = fopen("Contact.bat", "wb");
	assert(pf != NULL);
	for (i = 0; i < pcon->usedsize; i++)
	{
		fwrite(pcon->per + i, sizeof(PersonInfo), 1, pf);
	}
	fclose(pf);
	pf = NULL;
}
//加载联系人 
void LoadContact(Contact *pcon) {
	FILE *pf = fopen("Contact.bat", "rb");
	PersonInfo tmp = { 0 };
	if (pf == NULL)
	{
		return;
	}
	//fread函数的返回值是：读取成功的字节数
	while (fread(&tmp, sizeof(PersonInfo), 1, pf) > 0)
	{
		//必须判断是否为满，如果满了扩容
		CheckFullAndRe(pcon);
		pcon->per[pcon->usedsize++] = tmp;
	}
	fclose(pf);
	pf = NULL;
}
//扩容通讯录
static int CheckFullAndRe(Contact *pcon) {
	if (pcon->usedsize == pcon->capacity)
	{
		PersonInfo * ptr = NULL;
		ptr = (PersonInfo *)realloc(pcon->per,
			sizeof(PersonInfo) * pcon->capacity * 2);
		if (ptr != NULL)
		{
			pcon->per = ptr;
			pcon->capacity *= 2;
			printf("扩容成功\n");
			return 1;
		}
		else
		{
			return 0;//扩容失败
		}
	}

	return 1;
}