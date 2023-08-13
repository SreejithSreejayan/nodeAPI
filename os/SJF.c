#include <stdio.h>
int main()
{
    int bt[20], p[20], wt[20], tat[20], i, j, n, total = 0, pos, temp;
    float avwt, avtat;
    printf("                     SJF SCHEDULING\n");
    printf("                    ================\n");
    printf("Enter number of processes:\n");
    scanf("%d", &n);
    printf("Enter burst time:\n");
    for (i = 0; i < n; i++)
    {
        printf("P[%d] :", i + 1);
        scanf("%d", &bt[i]);
        p[i] = i + 1;
    }
    printf("\nProcess\t\tBurst time\t\tWaiting time\t\tTurnaround time\n");
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
            if (bt[j] < bt[pos])
                pos = j;
        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }
    wt[0] = 0;
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        for (j = 0; j < i; j++)
            wt[i] += bt[j];
    }
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        printf("P[%d]\t\t%d\t\t\t%d\t\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    avwt /= i;
    avtat /= i;
    printf("Average waiting time :%f\n", avwt);
    printf("Average turnaround time :%f\n", avtat);
    return 0;
}
