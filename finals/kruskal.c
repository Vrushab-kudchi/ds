#include <stdio.h>

void main()
{
    int i, j, a, b, u, v, mincost = 0, n, cost[30][30], min, ne = 1;
    printf("\nEnter the Number of Vertices\n");
    scanf("%d", &n);
    printf("Enter the matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    while (ne < n)
    {
        min = 999;
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j < n; j++)
            {
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        if (u != v)
        {
            printf("\n%d EDGES (%d,%d) =%d \n", ne++, a, b, min);
            mincost = mincost + min;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\n mincost = %d", mincost);
}
