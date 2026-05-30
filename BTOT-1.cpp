#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
typedef struct SinhVien
{
	char Hovaten[50];
	char MSSV[15];
	float gpa;
	SinhVien* pNext;
}SinhVien;

typedef struct List
{
	SVNode* pHead;
	SVNode* pTail;
}List;

void AddFirst(List &l, SinhVien* new_ele);
void AddTail(List &l, SinhVien* new_ele);
void Nhapsinhvien(List &l);
void Xuat(List &l);

int main()
{
	char luachon;;
	int n;
	List danhsach;
	danhsach.pHead = NULL;
	danhsach.pTail = NULL;
	
	do
	{
	printf("\n--------Vui long chon-----------------\n");
	printf("  Lua chon 1: Them sinh vien            \n");
	printf("  Lua chon 2: Bo sung vao cuoi          \n");
	printf("  Lua chon 3: Xoa sinh vien	            \n");
	printf("  Lua chon 4: Sap xep sinh vien         \n");
	printf("  Lua chon 5: In danh sach              \n");
	printf("----------------------------------------\n");
	printf("Chon lua chon: ");
	scanf(" %c",&luachon);
	
	switch(luachon)
		{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				printf("Vui long chon 1-5.");
				break;
		}
	}while(luachon != '0');
	getch();
	return 0;
}

void Nhapthemsinhvien(List &l)
{
	int n;
	printf("Nhap so luong sinh vien muon them: ");
	scanf("%d",&n);
	{
		for(int i=0;i<n;i++)
		{
			
		}
	}
}


