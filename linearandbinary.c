#include <stdio.h>
#include <stdlib.h>

void main()
{
    int a[50], key,opt,n,i ,L,R,M;
    printf("Enter Your Choice \n");
    while(1)
    {
        printf("\n1.Binary_Search\n2.Linear_Search\n3.Exit\n");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
                printf("Enter The Size of Array\n");
                scanf("%d" ,&n);
                printf("Enter The Element (It Should Be Sorted For Binary Search to Work)\n");
                for (i = 0; i < n; i++)
                {
                    scanf("%d" ,&a[i]);
                }
                printf("Enter The key\n");
                scanf("%d" ,&key);
                L = 0;
                R = n - 1;
                M = (L + R) / 2;
                while(L <= R)
                {
                    if (a[M] == key)
                    {
                        printf("Element Found at %d" ,M);
                        exit(0);
                    }
                    else if (key > a[M])
                    {

                        L = M + 1;
                        R = n;
                        M = (L + R) / 2;
                    }
                    else if (key < a[M])
                    {
                        R = M - 1;
                        L = 0;
                        M = (L + R) / 2;
                    }
                }
                printf("Element Not Found");

                break;

            case 2:
                printf("Enter The Size of Array\n");
                scanf("%d" ,&n);
                printf("Enter The Element\n");
                for (i = 0; i < n; i++)
                {
                    scanf("%d" ,&a[i]);
                }
                printf("Enter The key\n");
                scanf("%d" ,&key);
                for (i = 0; i < n;i++)
                {
                    if(a[i] == key)
                    {
                        printf("Element Found in Position %d\n", i);

                        exit (0);
                    }
                }
                        printf("Key not Found");
                break;
            }
    }

}
