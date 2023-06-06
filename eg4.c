//Queue Program

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Queue_size 5


int r = -1, f = 0 , queue[Queue_size];

int Insert_rear(int item)
{
    if(r == Queue_size-1)
    {
        printf("\nQueue is full\n");
        return 0;
    }
    queue[++r] = item;
    printf("\nElement Added\n");
}

int Delete_front()
{
    if(f > r)
    {
        printf("\nQueue is Empty\n");
        return 0;
    }
    printf("\nElement Deleted %d\n" ,queue[f++]);
    if(f > r)
    {
        f = 0;
        r = -1;
    }
}
 int display()
 {
    if(f>r)
    {
        printf("Queue is Empty\n");
        return 0;
    }
    printf("Elements are \n");
    for (int i = f; i <= r; i++)
    {
        printf("%d\t" ,queue[i]);
    }
 }

 void main()
 {
    int item, opt;
    while(1)
    {
        printf("Enter Your Choice \n");
        printf("\n1.Insert from Rear\n2.Delete from Front\n3.Display\n4.Exit\n");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
            printf("Enter Element to Insert \n");
            scanf("%d" ,&item);
            Insert_rear(item);
            break;

            case 2:
            Delete_front();
            break;

            case 3:
            display();
            break;

            case 4:
            exit(0);
            break;

            default:
            printf("\nInvalid Input\n");
            }
    }
 }
