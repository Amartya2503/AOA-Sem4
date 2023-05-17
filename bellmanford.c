#include<stdio.h>
#include<stdlib.h>

#define MAX 100
#define INF 999

int distance[MAX],cost[MAX][MAX],node[MAX];
int edge1[MAX],edge2[MAX];

void initialize(int n)
{
    int i;
    for(i = 0; i<n; i++)
    {
        distance[node[i]] = INF;
        
    }
    distance[node[0]] = 0;
}

void relax(int u, int v)
{
    if(distance[u] == INF && distance[v] == INF)
    {
        return;
    }
    if(distance[v] == INF)
    {
        distance[v] = distance[u] + cost[u][v];
        return;
    }
    distance[v] = (distance[v]>distance[u] + cost[u][v])? distance[v] = distance[u] + cost[u][v] : distance[v];
}

void bellmanford(int n, int e)
{
    int i,j;
    for( i=0; i<n-1; i++)
    {
        for(j=0; j<e; j++)
        {
            relax(edge1[j], edge2[j]);
        }
        for(j=0; j<n; j++)
        {
            printf(" %d\t",distance[node[j]]);
        }
        printf("\n");
    }

}
void main()
{
    int n,i,j,e,a,b,w;
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    printf("enter the nodes:\n");
    for(i=0; i<n; i++)
    {
        scanf("%d",&node[i]);
    }
    printf("enter the number of edges : ");
    scanf("%d",&e);
    for(i=0; i<n; i++)
    {
        for(j=0; j<n; j++)
        {
            cost[i][j] = INF; 
        }
    }
    printf("enter the startnode endnode weight\n");
    for(i=0; i<e; i++)
    {
        scanf("%d %d %d",&a,&b,&w);
        edge1[i] = a;
        edge2[i] = b;
        cost[a][b] = w;
    }
    initialize(n);
    bellmanford(n,e);
    printf("\n final distances\n");
    for(i=0; i<n; i++)
    {
        printf(" %d\t",distance[node[i]]);
    }

}