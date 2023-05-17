#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define inf 999

int distance[MAX], parent[MAX], node[MAX], list[MAX], cost[MAX][MAX];

void initialize(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        distance[node[i]] = inf;
        list[node[i]] = 0;
        parent[node[i]] = inf;
    }
    distance[node[0]] = 0;
    parent[node[0]] = -1;
}

int minNode(int n)
{
    int i, min = MAX, mini = -1;

    for (i = 0; i < n; i++)
    {
        if (distance[node[i]] < min && list[node[i]] != 1)
        {
            mini = i;
            min = distance[node[i]];
        }
    }
    if (mini != -1)
    {
        list[node[mini]] = 1;
    }
    return mini;
}
void prims(int n)
{
    int i, j, u;
    u = minNode(n);
    while (u != -1)
    {
        for (i = 0; i < n; i++)
        {
            if (cost[u][i] != inf && list[node[i]] != 1 && cost[u][i] < distance[node[i]])
            {
                distance[node[i]] = cost[u][i];
                parent[node[i]] = u;
            }
        }
        u = minNode(n);
    }
}
void main()
{
    int i, j, n, e, a, b, w;
    printf("enter the number of nodes: ");
    scanf("%d", &n);
    printf("\nenter the nodes : \n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &node[i]);
    }
    printf("\nenter the number of edges ");
    scanf("%d", &e);
    for (i = 0; i < e; i++)
    {
        for (j = 0; j < n; j++)
        {
            cost[i][j] = inf;
        }
    }
    printf("enter the srartnode endnode weight\n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        cost[a][b] = w;
        cost[b][a] = w;
    }
    initialize(n);
    prims(n);
    printf("The final distants are:\n");
    printf("edge\tdistance\n");
    for (i = 0; i < n; i++)
    {
        printf("%d - %d\t%d\n", parent[node[i]], i, distance[node[i]]);
    }
}