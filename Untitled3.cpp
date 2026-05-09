#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

void NhapDanhSachSinhVien(int n);
void Xuat(LIST ds);
int main()
{
	char luachon;
	int n;
	printf("--------Vui long chon-----------------\n");
	printf("  Lua chon 1: Nhap danh sach          \n");
	printf("  Lua chon 2: Bo sung vao dau         \n");
	printf("  Lua chon 3: Bo sung vao cuoi        \n");
	printf("  Lua chon 4: Tim 1 phan tu           \n");
	printf("  Lua chon 5: Xoa 1 phan tu           \n");
	printf("  Lua chon 6: In danh sach            \n");
	printf("--------------------------------------\n");
	printf("Chon lua chon: ");
	scanf("%c",&luachon);
	
	
	switch(luachon)
	{
		case '1':
			NhapDanhSachSinhVien(n);
			break;
		case '2':
			break;
		case '3':
			break;
		case '4':
			break;
		case '5':
			break;
		case '6':
			printf("\n--- Danh sach sinh vien ---\n");
			PrintList(danhsach);
			break;
		default:
      		printf("Vui long chi lua chon tu 1-6.");
      		break;
	}
	
	getch();
	return 0;
}


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

void NhapDanhSachSinhVien(int n)
{
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
}

void Xuat(LIST ds)
{
    NODE *p;
    p = ds.pHead;
    while (p!=NULL)
	{
        printf("%d\n",p->data);
        p=p->next;
    }
}


































