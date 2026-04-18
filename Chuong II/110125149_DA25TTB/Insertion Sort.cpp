#include<stdio.h>
#include<conio.h>

void ISS(int a[50], int n);

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
		
		ISS(a,n);
		printf("\nPhan tu sau khi sap xep la:\t");
		for(i=0;i<n;i++)
		{		
			printf("%d\t",a[i]);
		}
}

void ISS(int a[50], int n)
{
	int pos, i, x;
	for( int i=1; i<n; i++)
	{
		x=a[i];
		pos=i-1;
		while(pos>=0 && a[pos]>x)
		{
			a[pos+1]=a[pos];
			pos--;
		}
		a[pos+1]=x;
	}
}

