#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int max(int a, int b){return (a>b)?a:b;}

int lcs(char X[100],char Y[100], int n, int m)
{
    if(m==0 || n==0)
    {
        return 0;
    }
    else if(X[m-1] == Y[n-1])
    {
        return 1+ lcs(X, Y, m-1, n-1);
    }
    else
    {
        return max(lcs(X,Y,m,n-1),lcs(X,Y,m-1,n));
    }

}

void main()
{
    int i,m,n;
    char X[100],Y[100];
    printf("enter the string : ");
    scanf("%s",&X);
    printf("enter the pattern : ");
    scanf("%s",&Y);

    m = strlen(X);
    n = strlen(Y);
    i= lcs(X, Y, m, n);
    printf("the longest found subsequense is of length : %d",i);
    
}