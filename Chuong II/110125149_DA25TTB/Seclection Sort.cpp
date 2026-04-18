#include<stdio.h>
#include<conio.h>

void SLS(int a[50], int n);
int Hoanvi(int &a, int &b);

int main()
{
		int a[50], n, i, x;
		printf("so phan tu cua mang la: ");
		scanf("%d", &n);
		
		for(i=0;i<=n;i++)
		{
			printf("Nhap phan tu a[%d]: ", i);
			scanf("%d",&a[i]);
			
		}
		
		printf("Phan tu cua mang vua nhap la:\t");
		for(i=0;i<=n;i++)
		{		
			printf("%d\t",a[i]);
		}
		
		SLS(a,n);
		printf("\nPhan tu mang sau khi sap xep la:\t");
		for(i=0;i<=n;i++)
		{		
			printf("%d\t",a[i]);
		}
}

int Hoanvi(int &a, int &b)
{
	int tam;
	tam = a;
	a=b;
	b=tam;	
}

void SLS(int a[50], int n)
{
	int min;
	for(int i=0; i<=n; i++)
	{
		min=i;
		for(int j=i+1; j<=n; j++)
		if(a[j]<a[min])
		min = j;
		Hoanvi(a[min], a[i]);
	}
}
