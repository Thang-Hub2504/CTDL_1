#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

typedef struct TNODE{
	int key;
	struct TNODE *pleft, *pright;
}TNODE;
typedef TNODE*TREE;

TNODE* createNode(int x) {
    TNODE *p = (TNODE*)malloc(sizeof(TNODE));
    p->key = x;
    p->pleft = p->pright = NULL;
    return p;
}

void insert(TREE *root, int x) {
    if (*root == NULL) {
        *root = createNode(x);
    } else if (x < (*root)->key) {
        insert(&(*root)->pleft, x);
    } else {
        insert(&(*root)->pright, x);
    }
}

void NLR(TREE root)
{
	if (root != NULL)
	{	
		printf("%d\t", root->key);
		NLR(root->pleft);
		NLR(root->pright);
	}
}

void LNR(TREE root)
{
	if (root != NULL)
	{
		LNR(root->pleft);
		printf("%d\t", root->key);
		LNR(root->pright);
	}
}

void LRN(TREE root)
{
	if (root != NULL)
	{
		LRN(root->pleft);
		LRN(root->pright);
		printf("%d\t", root->key);
	}
}

int CountNODEs(TREE root)
{
	if(root != NULL)
		return 1 + CountNODEs(root->pleft) + CountNODEs(root->pright);
	else 
		return 0;
}

int TREEheights(TREE root)
{
	if(root == NULL) return -1;
	int leftH = TREEheights(root->pleft);
	int rightH = TREEheights(root->pright);
	return 1 + max(leftH,rightH);
}

int CountLeaves(TREE root)
{
	if(root == NULL) return 0;
	if(root->pleft == NULL && root->pright == NULL)
    return 1;
    return CountLeaves(root->pleft) + CountLeaves(root->pright);
}

void Timkiem(TREE &p, TREE &q)
{
	if(q->pleft) Timkiem(p, q->pleft);
	else
	{
		p->key = q->key;
		p=q;
		q=q->pright;
	}
}

int delNODE(TREE &T, int a)
{
	if(T==NULL) return 0;
	if(T->key > a) return delNODE (T ->pleft, a);
	if(T->key < a) return delNODE (T ->pright, a);
	else
	{
		TNODE* p=T;
		if(T->pleft == NULL) T= T->pright;
		else if(T->pright == NULL) T = T->pleft;
		else
		{
				Timkiem(p,T->pright);
		}
		delete p;
		return 1;
	}
}

int main()	
{	
	int n,x;
	printf("Nhap so phan tu ban muon: ");
	scanf("%d",&n);
	TREE root = NULL;
	for(int i=1;i<=n;i++)
	{
		printf("Nhap phan tu so %d: ", i);
		scanf("%d",&x);
		insert(&root, x);
	}
	
	
	
	printf("\nDuyet NLR: ");
	NLR(root);
	
	printf("\nDuyet LNR: ");
	LNR(root);
	
	printf("\nDuyet LRN: ");
	LRN(root);
	
	printf("\nTong so nut tren cay la: %d", CountNODEs(root));
	printf("\nChieu cao cay nhi phan la: %d", TREEheights(root));
	printf("\nTong so nut la tren cay la: %d", CountLeaves(root));
	
	return 0;
}
