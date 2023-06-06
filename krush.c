#include <stdio.h>
int i, j, a, b, u, v, n;
int parent[10] = {0}, min, ne = 1, mincost = 0, cost[10][10] = {0};
int main()
{
    printf("enter no of vertices\n");
    scanf("%d", &n);
    printf("enter matrix\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
            scanf(" %d", &cost[i][j]);
        if (cost[i][j] == 0)
            cost[i][j] = 999;
    }
    while (ne < n)
    {
        for (i = 1, min = 999; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (cost[i][j] < min)
                {
                    min = cost[i][j];
                    a = u = i, b = v = j;
                }
        if (u != v)
        {
            printf("\n%d Edge (%d%d)=%d", ne++, a, b, min);
            mincost = mincost + min;
            parent[v] = u;
        }
        cost[a][b] = cost[b][a] = 999;
    }
    printf("\n\n\t\t MINCOST=%d", mincost);
    return 0;
}
