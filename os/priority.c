#include <stdio.h>
int main()
{
    int bt[20], p[20], wt[20], tat[20], pr[20], i, j, n, total = 0, pos, temp;
    float avwt, avtat;
    printf("                     PRIORITY SCHEDULING\n");
    printf("                    =====================\n");
    printf("Enter number of processes:\n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("\nP[%d]\n", i + 1);
        printf("Burst time :");
        scanf("%d", &bt[i]);
        printf("Priority :");
        scanf("%d", &pr[i]);
        p[i] = i + 1;
    }
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i + 1; j < n; j++)
            if (pr[j] < pr[pos])
                pos = j;
        temp = pr[i];
        pr[i] = pr[pos];
        pr[pos] = temp;

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
        total += wt[i];
    }
    avwt = total / n;
    total = 0;
    printf("\nProcess\t  Burst time\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        total += tat[i];
        printf("P[%d]\t  %d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    avtat = total / n;
    printf("Average waiting time :%f\n", avwt);
    printf("Average turnaround time :%f\n", avtat);
    return 0;
}
