#include <stdio.h>
#include <stdlib.h>
void dijkastra(int cost[30][30], int s, int n)
{
    int dist[30], visited[30], pred[30], i, count, min, v, j;
    for (i = 0; i < n; i++)
    {
        dist[i] = cost[s][i];
        visited[i] = 0;
        pred[i] = s;
    }
    dist[s] = 0;
    visited[s] = 1;
    count = 1;
    while (count < n - 1)
    {
        min = 999;
        for (i = 0; i < n; i++)
        {
            if (dist[i] < min && visited[i] == 0)
            {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;
        // check if a better path exists through nextnode
        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (min + cost[v][i] < dist[i])
                {
                    dist[i] = min + cost[v][i];
                    pred[i] = v;
                }
            }
        }
        count++;
    }
    // print the output
    for (i = 0; i < n; i++)
    {
        if (i != s)
        {
            printf("\nDistance of node %d = %d", i, dist[i]);
            printf("\nPath = %d", i);
            j = i;
            while (j != s)
            {
                j = pred[j];
                printf(" <- %d", j);
            }
        }
    }
}
int main()
{
    int cost[30][30], s, n, i, j;
    printf("Enter the number of Vertices:\n ");
    scanf("%d", &n);
    printf("Enter the cost matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if (cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }
    printf("\nEnter the starting Node: \n");
    scanf("%d", &s);
    dijkastra(cost, s, n);
    return 0;
}
