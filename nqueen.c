#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>


int x[100],n;

bool isSafe(int k, int i)
{
    int j;
    for(j=1; j<=k-1; j++)
    {
        if(x[j] == i || abs(x[j] - i) == abs(j-k) )
        {
            return false;
        }
    }
    return true;
}

void nQueen(int k)
{
    int i,j;
    for(i=1; i<= n; i++)
    {
        if(isSafe(k,i))
        {
            x[k] = i;
            if(k == n)
            {
                for(j=1; j<=n; j++)
                {
                    printf("%d\t",x[j]);
                }
                printf("\n");
            }
            else
            {
                nQueen(k+1);
            }
        }
    }
}
void main()
{
    int i;
    printf("enter the number of queens: ");
    scanf("%d",&n);
    nQueen(1);
}