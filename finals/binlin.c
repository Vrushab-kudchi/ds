#include <stdio.h>
#include <stdlib.h>

void binarySearch(int a[30], int key, int n)
{
    int i, L = 0, R = n, M = (L + R) / 2;
    while (L <= R)
    {
        if (key == a[M])
        {
            printf("\nElement found in position %d\n", M);
            exit(0);
        }
        else if (key > a[M])
        {
            L = M + 1;
            R = n;
            M = (L + R) / 2;
        }
        else
        {
            R = M - 1;
            L = 0;
            M = (L + R) / 2;
        }
    }
    printf("\nElement not found");
}

void LinearSearch(int a[30], int key, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
        {
            printf("Element Found in position %d", i);
            exit(0);
        }
    }
    printf("Element Not Found ");
}

void main()
{
    int a[30], key, i, n, choice;
    printf("\nEnter the Size of array \n");
    scanf(" %d", &n);
    printf("\nEnter the Content");
    for (i = 0; i < n; i++)
    {
        scanf(" %d", &a[i]);
    }

    printf("\n Enter you Key\n");
    scanf(" %d", &key);
    printf("\n1.Linear_Search\n2.Binary_search\n3.Exit\n");
    scanf(" %d", &choice);

    switch (choice)
    {
    case 1:
        LinearSearch(a, key, n);
        break;

    case 2:
        binarySearch(a, key, n);
        break;

    case 3:
        exit(0);
        break;

    default:
        printf("invalid coud");
        break;
    }
}
