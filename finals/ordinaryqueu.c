#include <stdio.h>
#include <stdlib.h>

#define Queue_Size 20

void insert_rear(int queue[], int *r, int item)
{
    if (*r == Queue_Size)
    {
        printf("Queue is full\n");
    }
    else
    {
        queue[++(*r)] = item;
        printf("Element added in Queue = %d", item);
    }
}

void delete_front(int queue[], int *f, int *r)
{
    if (*f > *r)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Deleted element are %d\n", queue[(*f)++]);
    }
    if (*f > *r)
    {
        *f = 0;
        *r = -1;
    }
}

void display(int queue[], int f, int r)
{
    int i;
    if (f > r)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("\nElements are :\n");
        for (i = f; i <= r; i++)
        {
            printf(" %d ", queue[i]);
        }
    }
}

void main()
{
    int queue[Queue_Size], f = 0, r = -1, choice, item;
    while (1)
    {
        printf("\n1.Insert\n2.Delete\n3.Display\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the item\n");
            scanf("%d", &item);
            insert_rear(queue, &r, item);
            break;

        case 2:
            delete_front(queue, &f, &r);
            break;

        case 3:
            display(queue, f, r);
            break;
        }
    }
}
