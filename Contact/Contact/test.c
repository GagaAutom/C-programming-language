#define _CRT_SECURE_NO_WARNINGS 1
#include"Contact.h"

//char *strncpy( char *strDest, 
//const char *strSource, size_t count );
char *MyStrncpy(char *dest,const char *src,int count)
{
	//char *p = dest;
	//while(*dest++ = *src++);
	//return p;
	char *p = dest;
	int i = 0;
	while(i < count)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	return p;
}


//char *strncat( char *strDest, 
//const char *strSource, size_t count );
char * Mystrncat(char *dest,const char *src,int count)
{
	char *p = dest;
	int i = 0;
	while(*dest != '\0')
	{
		dest++;
	}
	//*dest = '\0';
	while(i < count)
	{
		*dest = *src;
		dest++;
		src++;
		i++;
	}
	return p;
}
//str1和str2比较
int MyStrcmp(const char *str1,const char *str2)
{
	while(*str1 == *str2)
	{
		if(*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
	}
	if(*str1 > *str2)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int MyStrncmp(const char *str1,const char *str2,int count)
{
	int i = 0;
	int differ = 0;
	while(i < count && ((differ = *str1-*str2)==0) && *str1 != '\0')
	{
		str1++;
		str2++;
		i++;
	}
	return differ;
}
int main()
{
	char str1[20] = "billo";
	char *str2 = "bit";
	int n = MyStrncmp(str1,str2,2);
	printf("%d\n",n);
	return 0;
}

#if 0

/*
1. 添加联系人信息
2. 删除指定联系人信息
3. 查找指定联系人信息
5. 显示所有联系人信息
6. 清空所有联系人
7. 以名字排序所有联系人
8.更新    
**/
void menu()
{
	printf("*************欢迎使用XXX通讯录**********\n");
	printf("********0.exit***********1.add************\n");
	printf("********2.del************3.search***********\n");
	printf("********4.show**********5.clear*************\n");
	printf("********6.sort***********7.destory***********\n");
	printf("***********************************************\n");
	
}


int main()
{
	int input = 0;
	Contact con;
	InitContact(&con);
	do
	{
		menu();
		printf("请输入您的操作：");
		scanf("%d",&input);
		switch(input)
		{
		case EXIT:
			//DestoryContact(&con);
			break;
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEAR:
			break;
		case SHOW:
			ShowContact(&con);
				break;
		case CLEAR:
			ClearContact(&con);
				break;
		case SORT:
				break;
		case DESTORY:
			DestoryContact(&con);
			break;
		default:
					break;
		}
	}while(input);
	return 0;
}
#endif

