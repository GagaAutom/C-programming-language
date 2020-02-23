#include<stdio.h>
#include<malloc.h>
#define MAX 20
#pragma warning(disable:4996)

typedef struct BTNode {       /*节点结构声明*/
	char data;               /*节点数据*/
	struct BTNode *lchild;
	struct BTNode *rchild;  /*指针*/
}*BiTree;

void createBiTree(BiTree *t) { /* 先序遍历创建二叉树*/
	char s;
	BiTree q;
	s = getchar();
	if (s == '#') { 
		*t = NULL; 
		return;
	}
	q = (BiTree)malloc(sizeof(struct BTNode));
	if (q == NULL) { 
		printf("Memory alloc failure!"); 
		exit(0);
	}
	q->data = s;
	*t = q;
	createBiTree(&q->lchild); /*递归建立左子树*/
	createBiTree(&q->rchild); /*递归建立右子树*/
}

void PreOrder(BiTree p) {  /* 先序遍历二叉树*/
	if (p != NULL) {
		printf("%c", p->data);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}
void InOrder(BiTree p) {  /* 中序遍历二叉树*/
	if (p != NULL) {
		InOrder(p->lchild);
		printf("%c", p->data);
		InOrder(p->rchild);
	}
}
void PostOrder(BiTree p) {  /* 后序遍历二叉树*/
	if (p != NULL) {
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		printf("%c", p->data);
	}
}
void release(BiTree t) { /*释放二叉树空间*/
	if (t != NULL) {
		release(t->lchild);
		release(t->rchild);
		free(t);
	}
}

int main() {
	BiTree t = NULL;
	printf("\n请输入数据：(空用 # 表示)");
	createBiTree(&t);
	printf("\n\n先序遍历是：");
	PreOrder(t);
	printf("\n\n中序遍历是：");
	InOrder(t);
	printf("\n\n后序遍历是：");
	PostOrder(t);
	release(t);
	system("pause");
	return 0;
}