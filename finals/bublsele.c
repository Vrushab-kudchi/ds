#include <stdio.h>
#include <stdlib.h>

void bubblesort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
    printf("\nSorted Elements are \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}

void selectionsort(int a[], int n)
{
    int i, j, temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    printf("\nSorted Elements are \n");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}
void main()
{
    int a[30], i, n, choice;
    printf("\nEnter the Size of array \n");
    scanf(" %d", &n);
    printf("\nEnter the Content");
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &a[i]);
    }
    printf("\n1.bubblesort\n2.selectionsort\n3.Exit\n");
    scanf(" %d", &choice);

    switch (choice)
    {
    case 1:
        bubblesort(a, n);
        break;

    case 2:
        selectionsort(a, n);
        break;

    case 3:
        exit(0);
        break;

    default:
        printf("invalid coud");
        break;
    }
}
