#include <stdio.h>
#include <stdlib.h>

void dijkstra(int cost[30][30], int n, int s)
{
    int dist[30], pred[30], i, visited[30], count, min, v, j;
    for (i = 0; i < n; i++)
    {
        dist[i] = cost[s][i];
        pred[i] = s;
        visited[i] = 0;
    }

    dist[s] = 0;
    visited[s] = 1;
    count = 1;
    while (count < n - 1)
    {
        min = 999;
        // find path
        for (i = 0; i < n; i++)
        {
            if (dist[i] < min && visited[i] != 1)
            {
                min = dist[i];
                v = i;
            }
        }
        visited[v] = 1;

        // find better path

        for (i = 0; i < n; i++)
        {
            if (!visited[i])
            {
                if (min + cost[v][i] < dist[i] && !visited[i])
                {
                    dist[i] = min + cost[v][i];
                    pred[i] = v;
                }
            }
        }
        count++;
    }
    for (i = 0; i < n; i++)
    {
        if (i != s)
        {
            printf("\nDistance between Nodes %d = %d", i, dist[i]);
            printf("\npath = %d", i);
            j = i;
            while (j != s)
            {
                j = pred[j];
                printf("->%d", j);
            }
        }
    }
}

int main()
{
    int cost[30][30], i, j, n, s;
    printf("\nEnter the number of vertices\n");
    scanf("%d", &n);
    printf("\nEnter the matrix\n");
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
    printf("\nEnter the starting node\n");
    scanf("%d", &s);
    dijkstra(cost, s, n);
    return 0;
}
