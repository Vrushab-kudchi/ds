#include<stdio.h>
#include<stdlib.h>

void bubblesort(int a[],int size);
void selectionsort(int a[],int size);

int main()
{
	int a[20],n,i,choice; char ans;
	do
	{
		printf("---SORTING ALGORITHM---\n");
		printf("1.BUBBLE SORT\n2.SELECTION SORT\n3.EXIT\n");
		printf("Enter Choice:\n"); scanf("%d",&choice);
		if(choice>2)
		{
			exit(0);
		}
		else
		{
			printf("How many elements:\n");
			scanf("%d",&n);
			if(n>50)
			{
				printf("Error\n");
				exit(0);
			}
			printf("Enter the Elements:\n");
			for(i=0;i<n;i++) scanf("%d",&a[i]);
			switch(choice)
			{
				case 1: bubblesort(a,n);
						break;
				case 2: selectionsort(a,n);
						break;
				case 3: exit(0);
			}
			printf("Do you want to continue(Y/N):\n");
			scanf("\n%c",&ans);
		}
	}while(ans=='y');
}

void bubblesort(int a[], int size)
{
	int temp,i,j;
	for(i=0;i<size;i++)
	{
		for(j=0;j<size-1;j++)
		{
			if(a[j]>a[j+1])
			{
				temp=a[j];
				a[j]=a[j+1];
				a[j+1]=temp;
			}
		}
	}
	printf("The sorted Array is:\n");
	for(i=0;i<size;i++)
	{
		printf("%d\n",a[i]);
	}
}

void selectionsort(int a[],int size)
{
	int i,j,position,swap;
	for(i=0;i<size;i++)
	{
		for(j=i+1;j<size;j++)
		{
			if(a[i]<a[j])
			{
				swap=a[i];
				a[i]=a[j];
				a[j]=swap;
			}
		}
	}
	printf("Sorted list in Desending Order:\n"); for(i=0;i<size;i++)
	{
		printf("%d\n",a[i]);
	}
}
