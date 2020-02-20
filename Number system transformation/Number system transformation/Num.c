#include<stdlib.h>
#include<stdio.h>
#include<stddef.h>
#define MAXSIZE 50
#pragma warning(disable:4996)

typedef char ElemType;

typedef struct
{
	ElemType data[MAXSIZE];
	int top;
}SeqStack, *PSeqStack;


PSeqStack Init_SeqStack()
{
	PSeqStack s;
	s = (PSeqStack)malloc(sizeof(SeqStack));
	if (s)
		s->top = -1;
	return s;
}


int Empty_SeqStack(PSeqStack s)
{
	if (s->top == -1)
		return 1;
	else
		return 0;
}


int Push_SeqStack(PSeqStack s, ElemType x)
{
	if (s->top == MAXSIZE - 1)
		return 0;
	else
	{
		s->top = s->top + 1;
		s->data[s->top] = x;
		return 1;
	}
}

int Pop_SeqStack(PSeqStack s, ElemType *x)
{
	if (Empty_SeqStack(s))
		return 0;
	else
	{
		*x = s->data[s->top];
		s->top = s->top - 1;
		return 1;
	}
}


int GetTop_SeqStack(PSeqStack s, ElemType *x)
{
	if (Empty_SeqStack(s))
		return 0;
	else
		*x = s->data[s->top];
	return 1;
}

void Destroy_SeqStack(PSeqStack *s)
{
	if (*s)
		free(*s);
	*s = NULL;
	return;
}


void Conversion(int num, int r)
{
	PSeqStack s;
	ElemType x;
	if (!r)
	{
		printf("基数不能为0");
		return;
	}
	s = Init_SeqStack();
	if (!s)
	{
		printf("初始化栈空间失败");
		return;
	}
	while (num)
	{
		if (num%r > 9)
			Push_SeqStack(s, num%r + 'A' - 10);   
		else
			Push_SeqStack(s, num%r + '0');   
		num = num / r;
	}
	while (!Empty_SeqStack(s))
	{
		Pop_SeqStack(s, &x);
		printf("%c", x);
	}
}
int main()
{
	int r, num;
	printf("请输入要转换的数据:\n");
	scanf("%d", &num);
	printf("请输入要转换成几进制：\n");
	scanf("%d", &r);
	printf("转换后数：\n");
	Conversion(num, r);
	printf("\n");
	system("pause");
	return 0;
}
