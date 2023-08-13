#include<stdio.h>
#include<stdlib.h>
int n,nf,i,j,k,hit=0,pgfaultcnt=0;
int in[100],p[50];

int isHit(int data)
{
    hit=0;
    for(j=0;j<nf;j++)
    {
        if(p[j]==data)
        {
            hit=1;
            break;
        }
    }
    return hit;
}

int getHitIndex(int data)
{
    int hitind;
    for(k=0;k<nf;k++)
    {
        hitind=k;
        break;
    }
    return hitind;
}

void main()
{
    int usedcnt[100];
    int least,repin,sofarcnt=0,bn;
    printf("                     LFU PAGE REPLACEMENT\n");
    printf("                    ======================\n");
    printf("Enter the length of page reference sequence: ");
    scanf("%d",&n);
    printf("Enter the page reference sequence: \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&in[i]);
    }
    printf("Enter the number of frames: ");
    scanf("%d",&nf);
    for(i=0;i<nf;i++)
    {
        usedcnt[i]=0;
        p[i]=9999;
    }
    for(i=0;i<n;i++)
    {
        printf("\nFor %d: ",in[i]);
        if(isHit(in[i]))
        {
            int hitind=getHitIndex(in[i]);
            usedcnt[hitind]++;
            printf("No page fault");
        }
        else
        {
            pgfaultcnt++;
            if(bn<nf)
            {
                p[bn]=in[i];
                usedcnt[bn]=usedcnt[bn]+1;
                bn++;
            }
            else
            {
                least=9999;
                for(k=0;k<nf;k++)
                {
                    if(usedcnt[k]<least)
                    {
                        least=usedcnt[k];
                        repin=k;
                    }
                    p[repin]=in[i];
                    sofarcnt=0;
                    for(k=0;k<=i;k++)
                    {
                        if(in[i]==in[k])
                        {
                            sofarcnt=sofarcnt+1;
                        }
                        usedcnt[repin]=sofarcnt;
                    }
                }
            }
            for(k=0;k<nf;k++)
            {
                if(p[k]!=9999)
                {
                       printf("%d ",p[k]);
                }
            }
        }
    }
    printf("\nTotal number of page fault: %d\n",pgfaultcnt);
}