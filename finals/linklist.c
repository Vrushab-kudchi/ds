#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *link;
};
typedef struct node *NODE;

NODE getnode()
{
    NODE x;
    x = (NODE)malloc(sizeof(struct node));
    if (x == NULL)
    {
        printf("\nMEMORY ERROR\n");
    }
    return x;
}

NODE freenode(NODE x)
{
    free(x);
}

NODE insert(NODE first, int item)
{
    NODE temp;
    temp = getnode();
    temp->link = first;
    temp->info = item;
    return temp;
}

NODE display(NODE first)
{
    NODE cur, prev;
    if (first == NULL)
    {
        printf("\nList is empty");
        return first;
    }
    cur = first;
    printf("elements are :\n");
    while (cur != NULL)
    {
        printf(" %d ", cur->info);
        cur = cur->link;
    }
}

NODE delete(NODE first)
{
    NODE prev, cur;
    if (first == NULL)
    {
        printf("No List found List is empty\n");
    }
    cur = first;
    cur = cur->link;
    freenode(first);
    return cur;
}

void main()
{
    NODE first;
    first = NULL;
    int item, choice;
    while (1)
    {
        printf("\n1.Insert\n2.Display\n3.Delete\n4.Delete_info\n");
        scanf(" %d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the element\n");
            scanf(" %d", &item);
            first = insert(first, item);
            break;

        case 2:
            display(first);
            break;

        case 3:
            delete
        }
    }
}
