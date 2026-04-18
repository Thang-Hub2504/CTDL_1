#include<stdio.h>
#include<conio.h>

void BBS(int a[50], int n);
int Hoanvi(int &a, int &b);

int main()
{
		int a[50], n, i, x;
		printf("so phan tu cua mang la: ");
		scanf("%d", &n);
		
		for(i=0;i<n;i++)
		{
			printf("Nhap phan tu a[%d]: ", i);
			scanf("%d",&a[i]);
			
		}
		
		printf("Phan tu cua mang vua nhap la:\t");
		for(i=0;i<n;i++)
		{		
			printf("%d\t",a[i]);
		}
		
		BBS(a,n);
		printf("\nPhan tu mang sau khi sap xep la:\t");
			for(i=0;i<n;i++)
			{		
				printf("%d\t",a[i]);
			}
}

void BBS(int a[50], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=n-1;j>i;j++)
			if(a[j]<a[j-1])
			Hoanvi(a[j],a[j]);
}

int Hoanvi(int &a, int &b)
{
	int tam;
	tam = a;
	a=b;
	b=tam;	
}
