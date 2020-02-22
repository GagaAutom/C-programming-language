#include<stdio.h>
#include<string.h>
#define MAXSIZE 100
#pragma warning(disable:4996)
typedef struct {
	char data[MAXSIZE];
	int length;
}SqString;

int index_bf(SqString *s, SqString *t, int start);
void getNext(SqString *t, int next[]);
int index_kmp(SqString *s, SqString *t, int start, int next[]);
void show_index();

int index_bf(SqString *s, SqString *t, int start) {
	int i = start;
	int j = 1;
	while (i <= s->length&&j <= t->length) {
		if (s->data[i] == t->data[j]) {
			++i;
			++j;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j > t->length)
		return i - t->length;
	else
		return 0;
}

void getNext(SqString *t, int next[]) {
	int i = 0, j = -1;
	next[0] = -1;
	while (i < t->length) {
		if ((j == -1) || (t->data[i] == t->data[j])) {
			i++; j++; next[i] = j;
		}
		else
			j = next[j];
	}
}

int index_kmp(SqString *s, SqString *t, int start, int next[]) {
	int i = start;
	int j = 1;
	while (i <= s->length && j <= t->length){
		if (j == 0 || s->data[i] == t->data[j]) {
			++i;
			++j;
		}
		else {
			j = next[j];
		}
	}
	if (j > t->length) {
		return i - t->length;
	}
	else {
		return 0;
	}
}

void show_index() {
	SqString s, t;
	int k, next[MAXSIZE] = { 0 }, i;
	printf("\n***show index***\n");
	printf("input string s:");
	gets(s.data);
	s.length = strlen(s.data);
	printf("input string t:");
	gets(t.data);
	t.length = strlen(t.data);
	printf("input start position:");
	scanf("%d", &k);
	printf("BF:\nthe result of BF is %d\n", index_bf(&s, &t, k));
	getNext(&t, next);
	printf("KMP:\n");
	printf("next[]:");
	for (i = 0; i < t.length; i++)
		printf("%3d", next[i]);
	printf("\n");
	printf("the result of KMP is %d\n", index_kmp(&s, &t, k, next));
	printf("\n***show over***\n");
}

int main() {
	show_index();
	system("pause");
	return 0;
}