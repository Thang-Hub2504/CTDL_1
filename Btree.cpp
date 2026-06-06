#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
struct Balo{
	char mahg[50];
	char tehg[50];
	int sl;
	int dg;
	int tt;
};

typedef struct BLnode{
	struct Balo data;
	BLnode*pNext;
}BLnode;

typedef struct List{
	BLnode* pHead;
	BLnode* pTail;
}List;
BLnode *new_ele; 
BLnode x;

void addtail(List &l, BLnode *new_ele){
	if(l.pHead == NULL){
		l.pHead = new_ele;
		l.pTail = l.pHead;
	}
	else{
		l.pTail -> pNext = new_ele;
		l.pTail = new_ele;
	}	
}
BLnode* createNode(int x){
	BLnode *p = (BLnode*)malloc(sizeof(BLnode));
	if(p == NULL){
		printf("\nLoi cap phat bo nho: ");
		return NULL;
	}
	return p;
}

void Nhap(List &danhsach, int &n){
	printf("Nhap so luong hang de bo vao Balo: ");
	scanf(" %d", &n);
	for(int i = 0; i < n; i++){
		BLnode*p = (BLnode*)malloc(sizeof(BLnode));
		p -> pNext = NULL;
		printf("\nNhap ma hang [%d]: ", i);
		scanf("%s", p->data.mahg);
		printf("\nNhap ten hang [%d]: ", i);
		scanf("%s", p->data.tehg);
		printf("\nNhap so luong hang [%d]: ", i);
		scanf("%d", &p->data.sl);
		printf("\nNhap don gia hang [%d]: ", i);
		scanf("%d", &p->data.dg);
		p->data.tt = p->data.sl * p->data.dg;
		printf("\nTong tien don hang [%d]: %d\n", i, p->data.tt);	
		addtail(danhsach, p);					
	}
}

void xuat(List &l) {
	printf("\n| %s |\n", "DANH SACH DO VAT TRONG BALO");
    printf("\n| %-3s | %-7s | %-8s | %-8s | %-7s | %-10s |\n",
           "STT","Ma hang", "Ten hang", "So luong", "Don gia", "Thanh tien");
    BLnode *p = l.pHead;
    while (p) {
    	int i;
    	i++;
        printf("| %-3d | %-7s | %-8s | %-8d | %-7d | %-10d |\n", i,  p->data.mahg, p->data.tehg, p->data.sl, p->data.dg, p->data.tt);
        p = p->pNext;
    }
}

int main(){
	List danhsach = {NULL,NULL};
	int n;
	Nhap(danhsach, n);
	
    xuat(danhsach);
	return 0;
	
}
