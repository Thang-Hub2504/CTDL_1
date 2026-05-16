#include <stdio.h>   // Fix 1: "inlcude" -> "include", thêm dấu cách
#include <stdlib.h>  // Cần cho malloc()

typedef struct TNODE {
    int key;              // Fix 2: "Data" không tồn tại -> dùng int
    struct TNODE *pleft, *pright; // Fix 3: "NODE" -> "TNODE" cho đúng tên struct
} TNODE;
typedef TNODE *TREE;

// Hàm tạo node mới
TNODE* createNode(int x) {
    TNODE *p = (TNODE*)malloc(sizeof(TNODE));
    p->key = x;
    p->pleft = p->pright = NULL;
    return p;
}

// Hàm thêm node vào BST
void insert(TREE *root, int x) {
    if (*root == NULL) {
        *root = createNode(x);
    } else if (x < (*root)->key) {
        insert(&(*root)->pleft, x);
    } else {
        insert(&(*root)->pright, x);
    }
}

// NLR: Node - Left - Right (Tiền thứ tự)
void NLR(TREE root) {
    if (root != NULL) {
        printf("%d ", root->key); // Fix 4: Thêm lệnh in key (bị thiếu hoàn toàn)
        NLR(root->pleft);         // Fix 5: Đúng thứ tự NLR: Node trước, rồi mới Left/Right
        NLR(root->pright);
    }
}

// LNR: Left - Node - Right (Trung thứ tự)
void LNR(TREE root) {
    if (root != NULL) {
        LNR(root->pleft);         // Fix 6: "root->left" -> "root->pleft"
        printf("%d ", root->key); // Fix 7: Thêm lệnh in key (bị thiếu hoàn toàn)
        LNR(root->pright);        // Fix 8: "root->Right" -> "root->pright"
    }
}

// LRN: Left - Right - Node (Hậu thứ tự)
void LRN(TREE root) {
    if (root != NULL) {
        LRN(root->pleft);         // Fix 9: "root->left" -> "root->pleft"
        LRN(root->pright);
        printf("%d ", root->key); // Fix 10: Thêm lệnh in key (bị thiếu hoàn toàn)
    }
}

int main() {
    int n, x;
    int i;        // Fix 11: Biến i chưa được khai báo
    TREE root = NULL; // Thêm biến cây

    printf("Nhap so phan tu ban muon: ");
    scanf("%d", &n);

    for (i = 1; i <= n; i++) {
        printf("Nhap phan tu so %d: ", i);
        scanf("%d", &x); // Fix 12: Thiếu dấu ";" sau scanf
        insert(&root, x); // Thêm vào cây
    }

    printf("\nDuyet NLR (tien thu tu): ");
    NLR(root);

    printf("\nDuyet LNR (trung thu tu): ");
    LNR(root);

    printf("\nDuyet LRN (hau thu tu): ");
    LRN(root);

    printf("\n");
    return 0;
}
