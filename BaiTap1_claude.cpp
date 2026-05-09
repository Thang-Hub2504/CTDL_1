#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

typedef struct SNNode{
	int So_duong;
	int So_am;
	SNNode* pNext;
}SNNode;

typedef struct List{
	SNNode* pHead;
	SNNode* pTail;
}List;

void    AddFirst(List &l, SNNode* new_ele);
void    AddTail (List &l, SNNode* new_ele);
List    NhapSoNguyen();
void    Xuat(List ds);
void    PrintList(List &l);

int main()
{
	char luachon;
	// FIX 1: Khai bao bien danhsach trong main
	List danhsach;
	danhsach.pHead = NULL;
	danhsach.pTail = NULL;

	// FIX 2: Boc menu trong vong lap de co the chon nhieu lan
	do {
		printf("\n--------Vui long chon-----------------\n");
		printf("  Lua chon 1: Nhap danh sach          \n");
		printf("  Lua chon 2: Bo sung vao cuoi        \n");
		printf("  Lua chon 3: Dem so luong phan tu    \n");
		printf("  Lua chon 4: In danh sach            \n");
		printf("  Lua chon 0: Thoat                   \n");
		printf("--------------------------------------\n");
		printf("Chon lua chon: ");
		scanf(" %c", &luachon); // them khoang trang truoc %c de bo qua newline

		switch(luachon)
		{
			case '1':
				danhsach = NhapSoNguyen();
				break;
			case '2':
				// TODO: them xu ly bo sung vao cuoi
				break;
			case '3':
				// TODO: them xu ly dem so luong phan tu
				break;
			case '4':
				Xuat(danhsach);
				break;
			case '0':
				printf("Da thoat.\n");
				break;
			default:
				printf("Vui long chi lua chon tu 0-4.\n");
				break;
		}
	} while(luachon != '0');

	getch();
	return 0;
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
		new_ele->pNext = l.pHead;
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

List NhapSoNguyen()
{
    List danhsach;
    danhsach.pHead = NULL;
    danhsach.pTail = NULL;

    int n;
    printf("Nhap so luong so nguyen: ");
    scanf("%d", &n);

    for(int i = 1; i <= n; i++)
    {
        SNNode* node = (SNNode*)malloc(sizeof(SNNode));
        node->pNext  = NULL;

        printf("Phan tu %d - Nhap so duong: ", i);
        scanf("%d", &node->So_duong);

        printf("Phan tu %d - Nhap so am  : ", i);
        scanf("%d", &node->So_am);

        AddTail(danhsach, node);
    }

    return danhsach;
}

void PrintList(List &l)
{
    SNNode* p = l.pHead;
    while(p != NULL)
    {
        printf("So duong: %d | So am: %d\n", p->So_duong, p->So_am);
        p = p->pNext;
    }
}

void Xuat(List ds)
{
    SNNode* p = ds.pHead;
    while(p != NULL)
    {
        printf("So duong: %d | So am: %d\n", p->So_duong, p->So_am);
        p = p->pNext;
    }
}
