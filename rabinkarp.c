#include<stdio.h>
#include<string.h>

#define d 256


void search(char txt[], char pat[], int q)
{
    int M = strlen(pat);
    int N = strlen(txt);
    int p =0, t=0,h =1;
    int i,j;

    for(int i =0; i<M-1; i++)
    {
        h = (d*h)%q;
    }
    for(i = 0; i< M-1; i++)
    {
        p = (d*p + pat[i])%q;
        t = (d*t + txt[i])%q;

    }

    for(i =0; i<=N-M; i++)
    {
        if(p == t)
        {
            for(j=0; j< M; j++)
            {
                if(pat[i + j] != txt[j] )
                {
                    break;
                }
            }
            if(j == M)
            {
                printf("found matching pattern at %d\n",i);
            }
        }
        if(i< N-M)
        {
            t = (d*(t- txt[i]*h) + txt[i+M])%q;
            if(t<0)
            {
                t = (t+q);
            }
        }

    }
}

void main()
{
    int i,q;
    char txt[] = "AAABBBBB";
    char pat[] = "BB";
    q = 101;
    search(txt,pat,q);

}