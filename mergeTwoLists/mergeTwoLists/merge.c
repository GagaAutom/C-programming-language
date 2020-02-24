#include<stdio.h> 
#include<malloc.h>

#pragma warning(disable:4996)

typedef struct ListNode {
	int val;
	struct ListNode *next;
}ListNode,*LinkList;


LinkList CreateList(int n) {
	ListNode *p, *q, *head;
	int i;
	head = (LinkList)malloc(sizeof(ListNode));        
	head->next = NULL;
	p = head;
	for (i = 0; i < n; i++) {
		q = (LinkList)malloc(sizeof(ListNode));       
		printf("input data %i:", i + 1);
		scanf("%d", &q->val);            
		q->next = NULL;                    
		p->next = q;                       
		p = q;
	}    
	return head;
}

void PrintList(LinkList L) {
	ListNode *p;
	p = L->next;  
	while (p != NULL) {
		printf("%5d", p->val);
		p = p->next;
	}
}

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
	if (l1 == NULL)
		return l2;
	if (l2 == NULL)
		return l1;
	if (l1->val < l2->val) {
		l1->next = mergeTwoLists(l1->next, l2);
		return l1;
	}
	else if(l1->val == l2->val){
		l2->next = mergeTwoLists(l1->next, l2->next);
		return l2;
	}else{
		l2->next = mergeTwoLists(l1, l2->next);
		return l2;
	}
}

int MaxList(struct ListNode* l){
	int n;
	ListNode *p;
	p = l->next;
	n = p->val;
	while (p->next){
		if ((p->next->val) > n)
			n = p->next->val;
		p = p->next;
	}
	return n;
}



int main()
{
	int p;
	//LinkList L1 = NULL;
	//LinkList L2 = NULL;
	//LinkList L3 = NULL;
	LinkList L4 = NULL;
	//printf("\n请输入L1长度:");  
	//scanf("%d", &n);
	//if (n > 0) {
	//	printf("\n建立L1链表:\n");
	//	L1 = CreateList(n);
	//	printf("\nL1显示:\n");
	//	PrintList(L1);
	//}
	//printf("\n请输入L2长度:");
	//scanf("%d", &m);
	//if (m > 0) {
	//	printf("\n建立L2链表:\n");
	//	L2 = CreateList(m);
	//	printf("\nL2显示:\n");
	//	PrintList(L2);
	//}
	//printf("\n合并两个有序链表\n");
	//L3 = mergeTwoLists(L1, L2);
	//printf("\n合并后显示:\n");
	//PrintList(L3);
	printf("\n请输入L4长度:");
	scanf("%d", &p);
	if (p > 0) {
		printf("\n建立L4链表:\n");
		L4 = CreateList(p);
		printf("\nL1显示:\n");
		PrintList(L4);
	}
	printf("\nL4链表中最大的值:\n%d\n",MaxList(L4));
	system("pause");
	return 0;
}