#include <stdio.h>
int n, nf;
int in[100];
int p[50];
int hit = 0;
int i, j, k;
int pgfaultcnt = 0;
void getData()
{
    printf("                     LRU PAGE REPLACEMENT\n");
    printf("                    ====================== \n");
    printf("\nEnter length of page reference sequence:");
    scanf("%d", &n);
    printf("\nEnter page reference sequence:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &in[i]);
    printf("\nEnter no. of frames:");
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

int getHItIndex(int data)
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
            printf("%d ", p[k]);
    }
}

void dispPgFaultCnt()
{
    printf("\nTotal no. of page faults:%d\n", pgfaultcnt);
}

void lru()
{
    initialize();
    int least[50];
    for (i = 0; i < n; i++)
    {
        printf("\nFor %d:", in[i]);
        if (isHit(in[i]) == 0)
        {
            for (j = 0; j < nf; j++)
            {
                int pg = p[j];
                int found = 0;
                for (k = i - 1; k >= 0; k--)
                {
                    if (pg == in[k])
                    {
                        least[j] = k;
                        found = 1;
                        break;
                    }
                    else
                        found = 0;
                }
                if (!found)
                    least[j] = -9999;
            }
            int min = 9999;
            int repindex;
            for (j = 0; j < nf; j++)
            {
                if (least[j] < min)
                {
                    min = least[j];
                    repindex = j;
                }
            }
            p[repindex] = in[i];
            pgfaultcnt++;
            dispPages();
        }
        else
            printf("No page fault!");
    }
    dispPgFaultCnt();
}
int main()
{
    getData();
    lru();
    return 0;
}
