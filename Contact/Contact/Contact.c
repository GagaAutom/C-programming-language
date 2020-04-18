#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

void LoadContact(Contact *pcon)
{
	FILE *pf = fopen("Contact.bat","rb");
	PersonInfo tmp = {0};
	if(pf == NULL)
	{
		return;
	}
	//fread函数的返回值是：读取成功的字节数
	while(fread(&tmp,sizeof(PersonInfo),1,pf) > 0)
	{
		//必须判断是否为满，如果满了扩容
		CheckFullAndRe(pcon);
		pcon->per[pcon->usedSize++] = tmp;
	}
	fclose(pf);
	pf = NULL;
}

void InitContact(Contact *pcon)
{
	/*pcon->usedSize = 0; 普通版本
	memset(pcon->per,0,sizeof(pcon->per));*/

	pcon ->usedSize = 0;
	pcon->cpaticty = DEFAULT_SIZE;
	pcon->per = (PersonInfo *)malloc(
		sizeof(PersonInfo) * pcon->cpaticty);
	assert(pcon->per != NULL);

	LoadContact(pcon);
}
//返回值代表 扩容是否成功  1
static int CheckFullAndRe(Contact *pcon)
{
	if(pcon->usedSize == pcon->cpaticty)
	{
		PersonInfo * ptr = NULL;
		ptr = (PersonInfo *)realloc(pcon->per,
			sizeof(PersonInfo) * pcon->cpaticty * 2);
		if(ptr !=NULL)
		{
			pcon->per = ptr;
			pcon->cpaticty *= 2; 
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

void AddContact(Contact *pcon)
{
	/*if(pcon->usedSize == MAX_NUMBER)
	{
		printf("不好意思老铁，满了\n");
		return;
	}*/

	if(CheckFullAndRe(pcon) != 1)
	{
		printf("扩容失败\n");
		return;
	}

	printf("请输入姓名：");
	scanf("%s",pcon->per[pcon->usedSize].name);
	printf("请输入年龄：");
	scanf("%d",&(pcon->per[pcon->usedSize].age));
	printf("请输入性别：");
	scanf("%s",pcon->per[pcon->usedSize].sex);
	printf("请输入电话：");
	scanf("%s",pcon->per[pcon->usedSize].tele);
	printf("请输入住址：");
	scanf("%s",pcon->per[pcon->usedSize].addr);
	pcon->usedSize++;
	printf("添加成功\n");
}

int SearchContact(Contact *pcon)
{
	int i = 0;
	char name[MAX_NAME] = {0};
	if(pcon->usedSize == 0)
	{
		printf("通讯录为空\n");
		return -1;
	}
	printf("请输入你要删除的姓名：");
	scanf("%s",name);
	for(i = 0;i < pcon->usedSize;i++)
	{
		if(strcmp(pcon->per[i].name,name) == 0)
		{
			return i;
		}
	}
	return -1;
}

void DelContact(Contact *pcon)
{
	int index = SearchContact(pcon);
	int i = 0;
	if(index == -1)
	{
		printf("查无此人\n");
		return;
	}
	for(i = index;i < pcon->usedSize-1;i++)
	{
		pcon->per[i] = pcon->per[i+1];
	}
	pcon->usedSize--;
	printf("删除成功\n");
}


void ShowContact(Contact *pcon)
{
	int i = 0;
	printf("%-10s %-5s %-5s %-11s %-20s\n","姓名","年龄",
		"性别","电话","住址");
	for(i = 0;i < pcon->usedSize;i++)
	{
		printf("%-10s %-5d %-5s %-11s %-20s\n",
			pcon->per[i].name,pcon->per[i].age,
			pcon->per[i].sex,pcon->per[i].tele,
			pcon->per[i].addr);
	}
}

void ClearContact(Contact *pcon)
{
	pcon->usedSize = 0;
}
//........... 
void SaveContact(Contact *pcon)
{
	int i = 0;
	FILE *pf = fopen("Contact.bat","wb");
	assert(pf != NULL);
	for(i = 0;i < pcon->usedSize;i++)
	{
		fwrite(pcon->per+i,sizeof(PersonInfo),1,pf);
	}
	fclose(pf);
	pf = NULL;
}
void DestoryContact(Contact *pcon)
{
	SaveContact(pcon);
	free(pcon->per);
	pcon->per = NULL;//预防野指针  
	pcon->cpaticty = 0;
	pcon->usedSize = 0;
}
