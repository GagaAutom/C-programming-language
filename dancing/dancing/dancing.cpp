
#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#pragma warning(disable:4996)

typedef struct Queue {

	int Front;

	int Rear;

	char elem[100][100];

	int Queuesize;

}Queue;



void Creat_Queue(Queue &Q)

{//建立一个队列

	int n, i;

	Q.Front = Q.Rear = 0;

	printf("请输入跳舞人数:");

	scanf("%d", &n);

	Q.Queuesize = n + 1;

	printf("请输入各跳舞人名：");

	for (i = 0; i < n; i++)

		scanf("%s", &Q.elem[i]);

	Q.Rear = n;

}



int QueueEmpty(Queue Q)

{//判断队列是否为空

	if (Q.Front == Q.Rear)

		return 1;

	else

		return 0;

}

void DeQueue(Queue &Q, char *str)

{//删除队头元素

	strcpy(str, Q.elem[Q.Front]);

	Q.Front = (Q.Front + 1) % Q.Queuesize;

}

void GetQueue(Queue Q, char *str)

{//取队首元素，队头指针不改变

	strcpy(str, Q.elem[Q.Front]);

}



void Judge_Queue(Queue &M, Queue &W)

{//舞伴配对

	int n;

	char str1[100], str2[100];

	printf("请输入舞会的轮数：");

	scanf("%d", &n);

	while (n--)

	{

		while (!QueueEmpty(M))

		{

			if (QueueEmpty(W))

				DeQueue(W, str1);

			DeQueue(M, str1);

			DeQueue(W, str2);

			printf("配对的舞者：%s %s\n", str1, str2);

		}

		M.Front = (M.Front + 1) % M.Queuesize;

		if (QueueEmpty(W))

			DeQueue(W, str1);

		GetQueue(W, str1);

		printf("第一个出场的未配对者的姓名：%s\n", str1);

	}

}



int main()

{

	Queue M, W;

	printf("男队：\n");

	Creat_Queue(M);

	printf("女队：\n");

	Creat_Queue(W);

	if (M.Queuesize > W.Queuesize)

		Judge_Queue(W, M);

	else

		Judge_Queue(M, W);

	system("pause");

	return 0;

}
