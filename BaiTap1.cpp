#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct SNNode{
	int So_nguyen;
	SNNode* pNext;
}SNNode;

typedef struct List{
	SNNode* pHead;
	SNNode* pTail;
}List;

void    AddFirst(List &l, SNNode* new_ele);
void    AddTail (List &l, SNNode* new_ele);
void    NhapThemSoNguyen(List &l);
void    Xuat(List ds);

int main()
{	
	char luachon;
	int n;
	List danhsach;
	danhsach.pHead = NULL;
	danhsach.pTail = NULL;
	
	int soCodinh[] = {1, 2, 3, 4, 5};
    for(int i = 0; i < 5; i++)
    {
        SNNode* node = (SNNode*)malloc(sizeof(SNNode));
        node->pNext = NULL;
        node->So_nguyen = soCodinh[i];
        AddTail(danhsach, node);
    }
    printf("Da khoi tao danh sach voi 5 so co dinh!\n");
	
do
{
	printf("\n--------Vui long chon-----------------\n");
	printf("  Lua chon 1: Nhap danh sach           \n");
	printf("  Lua chon 2: Bo sung vao cuoi         \n");
	printf("  Lua chon 3: Dem so luong phan tu     \n");
	printf("  Lua chon 4: In danh sach             \n");
	printf("---------------------------------------\n");
	printf("Chon lua chon: ");
	scanf(" %c",&luachon);
	
	
	switch(luachon)
	{
		case '1':
			NhapThemSoNguyen(danhsach);
			break;
		case '2':
		{
			SNNode* node = (SNNode*)malloc(sizeof(SNNode));
			node->pNext = NULL;
			printf("Nhap so nguyen can them vao cuoi: ");
			scanf("%d", &(node->So_nguyen));
			AddTail(danhsach, node);
			printf("Da them thanh cong!\n");
			break;
		}
		case '3':
			{
			int dem = 0;
			SNNode* p = danhsach.pHead;
			while(p != NULL) { dem++; p = p->pNext; }
			printf("So luong phan tu: %d\n", dem);
			break;
			}
		case '4':
			Xuat(danhsach);
			break;
		default:
      		printf("Vui long chi lua chon tu 1-6.");
      		break;
	}
} while(luachon != '0');
	getch();
	return 0;
}

void NhapThemSoNguyen(List &l)
{
	int n;
	printf("Nhap so luong so nguyen muon them: ");
	scanf("%d", &n);

	for(int i = 1; i <= n; i++)
	{
		SNNode* node = (SNNode*)malloc(sizeof(SNNode));
		node->pNext = NULL;
		printf("Phan tu %d - Nhap so nguyen: ", i);
		scanf("%d", &(node->So_nguyen));
		AddTail(l, node);
	}
	printf("Da them %d phan tu vao danh sach!\n", n);
}


void AddFirst(List &l, SNNode* new_ele)
{
	if(l.pHead == NULL)
	{
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else
	{
		new_ele -> pNext = l.pHead;
		l.pHead = new_ele;
	}
}

void AddTail(List &l, SNNode* new_ele)
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
    SNNode* p = l.pHead;
    while(p != NULL)
    {
        printf("So nguyen: %d\n", p->So_nguyen);
        p = p -> pNext;
    }
}

void Xuat(List ds)
{
    SNNode* p = ds.pHead;
    while(p != NULL)
    {
        printf("So nguyen: %d\n", p->So_nguyen);
        p = p->pNext;
    }
}


































