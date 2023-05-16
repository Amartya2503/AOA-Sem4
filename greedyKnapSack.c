#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int p[MAX], w[MAX];
float pwr[MAX];
void sort(int n)
{
    int i, j, k, temp1, temp2, temp3;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (pwr[j] < pwr[j + 1])
            {
                temp1 = pwr[j];
                pwr[j] = pwr[j + 1];
                pwr[j + 1] = temp1;

                temp2 = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp2;

                temp3 = w[j];
                w[j] = w[j + 1];
                w[j + 1] = temp3;
            }
        }
    }
    printf("sorted the objects by profit/weight ratio\n ");
    for (i = 0; i < n; i++)
    {
        printf("(%d , %d)", p[i], w[i]);
    }
}

void greedyKnapsack(int n, int weight)
{
    int remweight = weight, i = 0, profit = 0;
    float tempprof, j;
    while (remweight != 0 && i < n)
    {

        if (w[i] < weight)
        {

            if (w[i] < remweight)
            {
                remweight -= w[i];
                printf("placed (%d , %d) in bag total profit = %d , remaining weight = %d\n", p[i], w[i], profit += p[i], remweight);
                i++;
            }

            else if (remweight < w[i])
            {

                j = ((float)remweight / w[i]);
                tempprof = (float)j * p[i];

                printf("placed (%d , %d) in bag total profit = %d,remaining weight = %d\n", p[i], w[i], profit += tempprof, 0);
                remweight = 0;
                i++;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i++;
        }
    }
}

void main()
{
    int i, n, weight;
    printf("enter the number of objects : ");
    scanf("%d", &n);

    printf("enter the weight capacity : ");
    scanf("%d", &weight);

    printf("enter the profit    weight  of object in sequence\n");
    for (i = 0; i < n; i++)
    {

        scanf("%d %d", &p[i], &w[i]);
        pwr[i] = p[i] / w[i];
    }
    sort(n);
    greedyKnapsack(n, weight);
}