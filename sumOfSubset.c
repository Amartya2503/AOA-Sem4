#include<stdio.h>
#include<stdlib.h>

void printSubSet(int set[], int size)
{
    int i;
    printf("\n");
    for(i=0; i<size; i++)
    {
        printf("%d\t",set[i]);
    }
}

void subsetSumUtil(int set[],int subset[], int n, int subsetSize, int sum, int targetsum)
{
    if(sum == targetsum)
    {
        printSubSet(subset,subsetSize);
        return;
    }
    else if(n==0 || sum> targetsum)
    {
        return;
    }
    else
    {
        subsetSumUtil(set,subset,n-1,subsetSize,sum,targetsum);
        subset[subsetSize] = set[n-1];
        subsetSumUtil(set,subset,n-1,subsetSize += 1,sum += set[n-1], targetsum);
    }
}

void subsetSum(int set[], int n, int targetsum)
{
    int subsetSize = 0,subset[n],sum = 0;
    subsetSumUtil(set,subset,n,subsetSize, sum,targetsum);
}

void main()
{
    int set[] ={3,34,4,12,5,2};
    int n = sizeof(set)/sizeof(set[0]);
    int targetsum = 7;
    subsetSum(set,n,targetsum);
}