#include <stdio.h>

#define MAX 100
#define inf 999

int cost[MAX][MAX];
int parent[MAX], distance[MAX], list[MAX], node[MAX];

void initialize(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        list[node[i]] = 0;
        distance[node[i]] = inf;
        parent[node[i]] = inf;
    }
    distance[node[0]] = 0;
    printf("initialization completed\n");
}

void relax(int u, int v)
{
    distance[v] = (distance[v] > distance[u] + cost[u][v]) ? distance[u] + cost[u][v] : distance[v];
}

int getminNode(int n)
{
    int i, j, mini, min;
    mini = -1;
    min = MAX;
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

void djikstras(int n)
{
    int i, j, u;
    u = getminNode(n);
    while (u != -1)
    {
        for (i = 0; i < n; i++)
        {
            if (cost[u][i] != inf)
            {
                relax(u, i);
            }
        }
        u = getminNode(n);
    }
}

void main()
{
    int i, j, a, b, w, e, n;

    printf("enter the number of nodes : ");
    scanf("%d", &n);
    printf("enter the nodes: \n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &node[i]);
    }
    printf("enter the number of edges: ");
    scanf("%d", &e);
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cost[i][j] = inf;
        }
    }
    printf("enter the edges weight as node1 node2 weight : \n");
    for (i = 0; i < e; i++)
    {
        scanf("%d %d %d", &a, &b, &w);
        cost[a][b] = w;
        cost[b][a] = w;
    }
    initialize(n);
    djikstras(n);
    printf("the final distances are :\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", distance[i]);
    }
}