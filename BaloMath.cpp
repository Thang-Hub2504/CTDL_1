#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Balo{
	char dovat[50];
	int cannang;	
}Balo;

typedef struct BLNode{
	Balo *BL;
	BLNode*pNext;
}BLNode;

typedef struct list{
	BLNode *phead;
	BLNode *ptail;
}list;

void addFirst(list &l, BLNode*new_ele)
{
	if(l.phead==NULL)
	{
		l.phead = new_ele;
		l.ptail = l.phead;
	}
	else
	{
		l.ptail = new_ele;
		l.phead = l.phead;
	}
}
	
void AddTail(list &l, BLNode* new_ele)
{
	if(l.phead == NULL)
	{
		l.phead = new_ele;
		l.ptail = l.phead;
	}
	else
	{
		l.ptail->pNext = new_ele;
		l.ptail = new_ele;
	}	
}

void PrintfList(list &l)
{
	BLNode*p = l.phead;
	while(p != NULL)
	{
		printf("|Mon do: %s \n| Trong luong: %d \n|",p->BL->dovat,p->BL->cannang);
		p=p->pNext;
	}
}

int main()
{
	int n;
	char dovat[50];
	list danhsach;
	danhsach.phead = NULL;
	danhsach.ptail = NULL;
	
	printf("Nhap so luong do vat trong balo: ");
	scanf("%d",&n);
		for(int i=0;i<n;i++)
		{
			BLNode *p = (BLNode*)malloc(sizeof(BLNode));
			fflush(stdin);
			printf("Nhap do vat [%d]: ", i);
			fgets(dovat, sizeof(dovat), stdin);
			
			printf("Nhap can nang [%d]: ", i);
			scanf("\t%d\n",&p->BL->cannang);
			
			AddTail(danhsach,p);
		}
		printf("---- Cac mon do co trong balo ----\n");
		PrintfList(danhsach);
		return 0;
}



