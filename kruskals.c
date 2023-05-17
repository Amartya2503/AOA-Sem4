#include<stdio.h>
#define MAX 100
int parent[MAX];
int cost[MAX][MAX];
//this helps us find the parent of any node i 
int find(int i){
    while(parent[i])
    {
        i = parent[i];
    }
    return i;
}
// uni function assigns the parent to node j in i,j if i and j dont belong to same parents
int uni(int i, int j)
{
    if(i != j){
        parent[j] = i;
        return 1;
    }
    return 0;
}

void main()
{
    int n,i,j,ne = 1,min;
    int a,b,u,v,tcost =0;
    printf("enter the number of nodes: ");
    scanf("%d",&n);
    printf("entert the adjesency matrix : \n");
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%d",&cost[i][j]);
            if(cost[i][j] == 0)
            {
                cost[i][j] = 999;
            }
        }
    }

    printf("by kruskals algo : \n");
    while(ne<n)
    {
        for(i =1,min = 999; i<=n; i++)
        {
            for(j=1; j<=n; j++)
            {
                if(cost[i][j]<min)
                {
                    min = cost[i][j];
                    a = u = i;
                    b = v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if(uni(u,v))
        {
            tcost = tcost+ cost[a][b];
            printf("\n%d\tedge (%d , %d) costs %d\ttotal cost = %d",ne++, a,b,min,tcost);

        }
        cost[a][b] = cost[b][a]= 999;
        
    }
}