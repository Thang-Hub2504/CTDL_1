#include<stdio.h>
#include<stdlib.h>

typedef struct TNODE
{
	int key;
	struct TNODE *pLeft, *pRight;
}TNODE;

TNODE *createTNODE(int x)
{
	TNODE *p = (TNODE*)malloc(sizeof(TNODE));
	if(p == NULL)
	{
		printf("Loi khong du bo nho de cung cap!!!\n");
		exit(1);
	}
	p->key = x;
	p->pLeft = NULL;
	p->pRight= NULL;
	return p;
}

TNODE* insert(TNODE *root, int x)
{
    if(root == NULL)
        return createTNODE(x);
    if(x < root->key)
        root->pLeft = insert(root->pLeft, x);
    else
        root->pRight = insert(root->pRight, x);
    return root;
}

void NLR(TNODE *root)
{
	if(root != NULL)
	{
		printf("%d ", root -> key);
		NLR(root -> pLeft);
		NLR(root -> pRight);
	}
}

void LNR(TNODE *root)
{
	if(root != NULL)
	{
		LNR(root -> pLeft);
		printf("%d ", root -> key);
		LNR(root -> pRight);
	}
}

void LRN(TNODE *root)
{
	if(root != NULL)
	{
		LRN(root -> pLeft);
		LRN(root -> pRight);
			printf("%d ", root -> key);
	}
}

int main()
{	
	int n, m;
	TNODE *root = NULL;
	printf("Nhap so phan tu: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		printf("Nhap phan tu [%d]: ", i);
		scanf("%d",&m);
		root = insert(root,m);
	}
	printf("\nDuyet NLR: ");
	NLR(root);
	printf("\nDuyet LNR: ");
	LNR(root);
	printf("\nDuyet LRN: ");
	LRN(root);
}
