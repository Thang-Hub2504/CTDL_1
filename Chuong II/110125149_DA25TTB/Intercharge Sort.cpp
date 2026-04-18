#include<stdio.h>
#include<conio.h>

void ITS(int a[50], int n);
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
		
		ITS(a,n);
		printf("\nPhan tu mang sau khi sap xep la:\t");
		for(i=0;i<n;i++)
			{		
				printf("%d\t",a[i]);
			}
}

void ITS(int a[50], int n)
{
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			if(a[j]<a[i])
			Hoanvi(a[i],a[j]);
}

int Hoanvi(int &a, int &b)
{
	int tam;
	tam = a;
	a=b;
	b=tam;	
}
