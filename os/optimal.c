#include <stdio.h>
int n, nf;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int pgfaultcnt = 0;
void getData()
{
    printf("                     OPTIMAL\n");
    printf("                    =========\n");
    printf("\nEnter length of page reference sequence :");
    scanf("%d", &n);
    printf("\nEnter the page reference sequence:");
    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);
    printf("\n Enter the number of frames:");
    scanf("%d", &nf);
}
void initialize()
{
    pgfaultcnt = 0;
    for (i = 0; i < nf; i++)
        p[i] = 9999;
}
int isHit(int data)
{
    hit = 0;
    for (j = 0; j < nf; j++)
    {
        if (p[j] == data)
        {
            hit = 1;
            break;
        }
    }
    return hit;
}
int getHitindex(int data)
{
    int hitind;
    for (k = 0; k < nf; k++)
    {
        if (p[k] == data)
        {
            hitind = k;
            break;
        }
    }
    return hitind;
}
void dispPages()
{
    for (k = 0; k < nf; k++)
    {
        if (p[k] != 9999)
            printf("%d", p[k]);
    }
}
void dispPgFaultCnt()
{
    printf("\nTotal No of page faults :%d", pgfaultcnt);
}
void optimal()
{
    initialize();
    int near[50];
    for (i = 0; i < n; i++)
    {
        printf("\n for %d:", in[i]);
        if (isHit(in[i]) == 0)
        {
            for (j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for (k = i; k < n; k++)
                {
                    if (pg == in[k])
                    {
                        near[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if (!found)
                    near[j] = 9999;
            }
            int max = -9999;
            int repindex;
            for (j = 0; j < nf; j++)
            {
                if (near[j] > max)
                {
                    max = near[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;
            dispPages();
        }
        else
            printf("no page fault");
    }
    dispPgFaultCnt();
}
int main()
{
    getData();
    optimal();
    return 0;
}
