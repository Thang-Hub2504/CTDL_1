#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Sinhvien{
	char HoVaTen[30];
	int mssv;
	char Lop[20];
}sv;

typedef struct SVNode{
	char HoVaTen[30];
	int mssv;
	char Lop[20];
	SVNode* pNext;
}SVNode;

typedef struct List{
	SVNode* pHead;
	SVNode* pTail;
}List;

void AddFirst(List &l, SVNode* new_ele)
{
	if(l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele->pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void AddTail(List &l, SVNode* new_ele)
{
	if(l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		l.pTail->pNext = new_ele;
		l.pTail = new_ele;
	}	
}

void PrintList(List &l)
{
	SVNode* p = l.pHead;
	while(p != NULL)
	{
		printf("Ho va ten: %s | MSSV: %d | Lop: %s\n", p->HoVaTen, p->mssv, p->Lop);
		p = p->pNext;
	}
}

int main()
{	
	int n;
	List danhsach;
	danhsach.pHead = NULL;
	danhsach.pTail = NULL;
	
	printf("Nhap so luong sinh vien: ");
	scanf("%d",&n);
	
	for(int i=1;i<=n;i++)
	{	
		SVNode* node = (SVNode*)malloc(sizeof(SVNode));
		node->pNext = NULL;	
		
		printf("Nhap sinh vien [%d]: ",i);
			scanf("%s", node->HoVaTen);
		printf("Nhap ma so sinh vien [%d]:", i);
			scanf("%d", &(node->mssv));
		printf("Nhap ma lop sinh vien [%d]: ", i);
			scanf("%s", node->Lop);
			
		AddTail(danhsach, node);
	}
	
	printf("\n--- Danh sach sinh vien ---\n");
	PrintList(danhsach);
	
	return 0;
}

