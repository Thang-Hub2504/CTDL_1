#include<stdio.h>
#include<conio.h>
void ISS(int a[50], int n);
int binarysearch(int a[], int n, int x);
int ManyX(int a[50], int n, int x, int i);
int main()
{
    int a[10], x, n, i;
    printf("nhap so phan tu mang a: ");
    scanf("%d",&n);

    for(i=0;i<n ;i++)
    {   
        printf("a[%d]= ", i);
        scanf("%d", &a[i]);
    }
    
    printf("mang vua nhap la: ");
    for(i=0;i<n;i++)
    {
        printf("\t%d", a[i]);
    }

	ISS(a,n);
		printf("\nPhan tu sau khi sap xep la:\t");
		for(i=0;i<n;i++)
		{		
			printf("%d\t",a[i]);
		}
		
    printf("\nNhap x de tim: ");
    scanf("%d", &x);

    int result = binarysearch(a,n,x);
        if (result != -1) 
        {
            printf("\nTim thay x tai vi tri: %d\n", result);
        } 
        else 
        {
            printf("\nKhong tim thay x trong mang.\n");
        }
	ManyX(a,n,x,i);
    return 0;
}

void ISS(int a[50], int n)
{
	int pos, i, x;
	for(i=1; i<n; i++)
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

int binarysearch(int a[], int n, int x)
{
    int left =0;
    int right = n-1;
    int middle;
    do
    {
        middle =(left+right)/2;
        if(x==a[middle])
                return middle;
            else
                if(x <a[middle])
                    right = middle -1;
                else 
                left = middle +1;
    }
	while(left<=right);
    return -1;
}

int ManyX(int a[50], int n, int x, int i)
{
	int dem=0;
	for(i=0;i<n;i++)
	{
		if(a[i]==x)
		{
			dem++;
		}
	}
	printf("So lan %d xuat hien la: %d", x, dem);
	return 0;
}
