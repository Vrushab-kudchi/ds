//Link list

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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
    if(x==NULL)
    {
        printf("Memmory Error\n");
        exit(0);
    }
    return x;
}
 void freenode(NODE x)
 {
    free(x);
 }

NODE insert_front(NODE first,int item)
{
    NODE temp;
    temp = first;
    temp = getnode();
    temp->info = item;
    temp->link = first;
    return temp;
}

NODE delete_front(NODE first)
{
    NODE temp;
    if(first == NULL)
    {
        printf("\nList is Empty\n");
        exit(0);
    }
    temp = first;
    first = first->link;
    printf("\nDeleted list %d\n" ,temp->info);
    freenode(temp);
    return first;
}

void delete_info(NODE first,int item)
{
    NODE cur, pre;
    if(first == NULL)
    {
        printf("\nList is Empty\n");
    }
    cur = first;
    if (item == cur->info)
    {
        pre = cur;
        cur = cur->link;
        printf("\nDeleted list %d", pre->info);
        freenode(pre);
        return cur;
    }
    pre = NULL;
    cur = first;
    while(cur!=NULL && item != cur->info)
    {
        pre = cur;
        cur = cur->link;
    }
    if(cur == NULL)
    {
        printf("No item Found\n");
    }
    pre->link = cur->link;
    freenode(cur);
    return first;
}

void display(NODE first)
{
    NODE temp=first;
    if(first == NULL)
    {
        printf("\nList is Empty\n");
        exit(0);
    }
    printf("Elements are :\n");
    while (temp != NULL)
    {
        printf("%d ",temp->info);
        temp = temp->link;
    }
}

void main()
{
    NODE first = NULL;
    int opt, item ;
    while(1)
    {
        printf("\nEnter Your choice\n");
        printf("\n1.Insert\n2.Delete\n3.Display\n4.Delete_info");
        scanf("%d" ,&opt);
        switch(opt)
        {
            case 1:
                printf("\nEnter An Item\n");
                scanf("%d" ,&item);
                first = insert_front(first, item);
                break;

            case 2:
                first = delete_front(first);
                break;

            case 3:
                display(first);
                break;

            case 4:
                printf("\nEnter An Item\n");
                scanf("%d" ,&item);
                delete_info(first,item);
            }
    }
}
