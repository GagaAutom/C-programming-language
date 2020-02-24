#pragma warning(disable:4996);
#include<stdio.h>
#include<malloc.h>
#define ERROR 0
#define OK 1

#define INIT_SIZE 5     
#define INCREM 5        
typedef  int ElemType;  
typedef struct Sqlist {
	ElemType *slist;      
	int length;           
	int listsize;         
}Sqlist;

int InitList_sq(Sqlist *L);                        
int CreateList_sq(Sqlist *L, int n);             
int ListInsert_sq(Sqlist *L, int i, ElemType e);           
int PrintList_sq(Sqlist *L);  
int ListDelete_sq(Sqlist *L, int i); 
int ListLocate(Sqlist *L, ElemType e); 

int InitList_sq(Sqlist *L) {
	L->slist = (ElemType*)malloc(INIT_SIZE * sizeof(ElemType));
	if (!L->slist) return ERROR; 
	L->length = 0;
	L->listsize = INIT_SIZE;
	return OK;
}

int CreateList_sq(Sqlist *L, int n) {
	ElemType e;
	int i;
	for (i = 0; i < n; i++) {
		printf("input data %d£º", i + 1);
		scanf("%d", &e);
		if (!ListInsert_sq(L, i + 1, e))
			return ERROR;
	}
	return OK;
}


int PrintList_sq(Sqlist *L) {
	int i;
	for (i = 1; i <= L->length; i++)
		printf("%5d", L->slist[i - 1]);
	return OK;
}

int ListInsert_sq(Sqlist *L, int i, ElemType e) {
	int k;
	if (i<1 || i>L->length + 1)
		return ERROR;
	if (L->length >= L->listsize) {
		L->slist = (ElemType*)realloc(L->slist,
			(INIT_SIZE + INCREM) * sizeof(ElemType));
		if (!L->slist)
			return ERROR;
		L->listsize += INCREM;
	}
	for (k = L->length - 1; k >= i - 1; k--) {
		L->slist[k + 1] = L->slist[k];
	}
	L->slist[i - 1] = e;
	L->length++;
	return OK;
}
int ListDelete_sq(Sqlist *L, int i) {
	int k;
	if (i<1 || i>L->listsize)
		return ERROR;
	for (k = i - 1; k < L->length; k++) {
		L->slist[k] = L->slist[k + 1];
	}
	L->length--;
	return OK;
}

int ListLocate(Sqlist *L, ElemType e) {
	int i;
	for (i = 0; i < L->length; i++) {
		if (L->slist[i] == e)
			return i + 1;
	}
}
int main() {
	Sqlist sl;
	int n, m, k;
	printf("please input n:");  
	scanf("%d", &n);
	if (n > 0) {
		printf("\n1-Create Sqlist:\n");
		InitList_sq(&sl);
		CreateList_sq(&sl, n);
		printf("\n2-Print Sqlist:\n");
		PrintList_sq(&sl);
		printf("\nplease input insert location and data:(location,data)\n");
		scanf("%d,%d", &m, &k);
		ListInsert_sq(&sl, m, k);
		printf("\n3-Print Sqlist:\n");
		PrintList_sq(&sl);
		printf("\n");
	}
	else   printf("ERROR"); 
	system("pause");
	return 0;
}