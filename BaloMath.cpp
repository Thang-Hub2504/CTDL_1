#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Balo {
    char dovat[50];
    float cannang;
    float giatri;
    float dongia;   
    float soluong;  
} Balo;

typedef struct BLNode {
    Balo    *BL;
    BLNode  *pNext;
} BLNode;

typedef struct list {
    BLNode *phead;
    BLNode *ptail;
} list;

void AddTail(list &l, BLNode *new_ele) {
    new_ele->pNext = NULL;
    if (l.phead == NULL) {
        l.phead = l.ptail = new_ele;
    } else {
        l.ptail->pNext = new_ele;
        l.ptail = new_ele;
    }
}

void SortByDonGia(list &l) {
    if (!l.phead) return;
    int swapped;
    do {
        swapped = 0;
        BLNode *p = l.phead;
        while (p->pNext) {
            if (p->BL->dongia < p->pNext->BL->dongia) {
                Balo *tmp = p->BL;
                p->BL       = p->pNext->BL;
                p->pNext->BL = tmp;
                swapped = 1;
            }
            p = p->pNext;
        }
    } while (swapped);
}


void PrintList(list &l) {
    printf("%-15s %-12s %-10s %-10s\n",
           "Loai do vat", "Trong luong", "Gia tri", "Don gia");
    printf("-------------------------------------------------------\n");
    BLNode *p = l.phead;
    while (p) {
        printf("%-15s %-12.2f %-10.2f %-10.2f\n",
               p->BL->dovat,
               p->BL->cannang,
               p->BL->giatri,
               p->BL->dongia);
        p = p->pNext;
    }
}


void GiaiThuat(list &l, float W) {
    float conlai        = W;
    float tongGiaTri    = 0;
    float tongTrongLuong = 0;

    printf("\n==== KET QUA CHON DO VAT (Greedy) ====\n");
    printf("%-15s %-12s %-10s\n", "Loai do vat", "So luong", "Gia tri");
    printf("------------------------------------------\n");

    BLNode *p = l.phead;
    while (p && conlai > 0) {
        
        int soLuong = (int)(conlai / p->BL->cannang);

        if (soLuong > 0) {
            float gtChon = soLuong * p->BL->giatri;
            float tlChon = soLuong * p->BL->cannang;
            conlai          -= tlChon;
            tongGiaTri      += gtChon;
            tongTrongLuong  += tlChon;
            p->BL->soluong   = soLuong;

            printf("%-15s %-12d %-10.2f\n",
                   p->BL->dovat, soLuong, gtChon);
        }
        p = p->pNext;
    }

    printf("------------------------------------------\n");
    printf("Tong trong luong da chon : %.2f / %.2f\n", tongTrongLuong, W);
    printf("Tong gia tri dat duoc   : %.2f\n", tongGiaTri);
}

int main() {
    int   n;
    float W;
    list  danhsach;
    danhsach.phead = danhsach.ptail = NULL;

    printf("Nhap trong luong toi da cua balo: ");
    scanf("%f", &W);

    printf("Nhap so loai do vat: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        BLNode *node  = (BLNode *)malloc(sizeof(BLNode));
        node->BL      = (Balo   *)malloc(sizeof(Balo));
        node->pNext   = NULL;
        node->BL->soluong = 0;

        printf("\nNhap ten do vat [%d]: ", i + 1);
        scanf(" %49[^\n]", node->BL->dovat);

        printf("Nhap trong luong [%s]: ", node->BL->dovat);
        scanf("%f", &node->BL->cannang);

        printf("Nhap gia tri    [%s]: ", node->BL->dovat);
        scanf("%f", &node->BL->giatri);

        node->BL->dongia = node->BL->giatri / node->BL->cannang;

        AddTail(danhsach, node);
    }

    printf("\n==== DANH SACH DO VAT BAN DAU ====\n");
    PrintList(danhsach);

    SortByDonGia(danhsach);

    printf("\n==== SAU KHI SAP XEP THEO DON GIA GIAM DAN ====\n");
    PrintList(danhsach);

    GiaiThuat(danhsach, W);

    return 0;
}

