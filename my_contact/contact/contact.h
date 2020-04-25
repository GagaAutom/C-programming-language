#ifndef __CONTACT_H__ 
#define __CONTACT_H__ 
#include<string.h> 
#include<stdio.h> 
#include<assert.h> 
#include<stdlib.h> 
enum Option
{
	QUIT,
	ADD,
	SHOW,
	DEL,
	SEARCH,
	EMPTY,
	DESTORY,
	SAVE,
	LOAD
};
#define MAX_NAME 20 
#define SEX_NAME 5 
#define TEL_NAME 12 
#define ADDR_NAME 20 
//通讯录最多为1000人 
#define MAX_PER_NUM 1000 
//动态扩容版本 
#define DEFAULT_SIZE 2; 

#pragma warning(disable:4996)

typedef struct PersonInfo
{
	char name[MAX_NAME];
	char sex[SEX_NAME];
	short age;
	char tele[TEL_NAME];
	char addr[TEL_NAME];
}PersonInfo;
typedef struct Contact
{
	//PersonInfo per[MAX_PER_NUM] ;普通版本 
	PersonInfo* per;
	int usedsize;//有效数据个数 
	int capacity;//初始容量 
}Contact;//通讯录 
//初始化通讯录 
void InitContact(Contact *con);
//添加成员 
void AddContact(Contact *con);
//打印通讯录 
void ShowContact(Contact *con);
//删除成员 
void DelContact(Contact *con);
//查找成员 
int SearchContact(Contact *con);
//清空通讯录 
void EmptyContact(Contact *con);
//摧毁通讯录(动态版本) 
void DestoryContact(Contact *con);
//文件版本 //保存联系人到文件 
void SaveContact(Contact *con);
//加载联系人 
void LoadContact(Contact *con);
#endif //__CONTACT_H__