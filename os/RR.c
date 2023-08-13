#include <stdio.h>
int main()
{
    int count = 0, j, n, time, remain, flag = 0, time_quantum;
    int wt = 0, tat = 0, at[10], bt[10], rt[10];
    printf("                     ROUND ROBIN SCHEDULING\n");
    printf("                    ========================\n");
    printf("Enter no. of processes :");
    scanf("%d", &n);
    remain = n;
    for (count = 0; count < n; count++)
    {
        printf("\nP[%d]\n", count + 1);
        printf("Arrival time: ");
        scanf("%d", &at[count]);
        printf("Burst Time: ");
        scanf("%d", &bt[count]);
        rt[count] = bt[count];
    }
    printf("Enter time quantum\n");
    scanf("%d", &time_quantum);
    printf("\nProcess\t  Burst time\tWaiting time\tTurnaround time\n");
    for (time = 0, count = 0; remain != 0;)
    {
        if ((rt[count] <= time_quantum) && (rt[count] > 0))
        {
            time += rt[count];
            rt[count] = 0;
            flag = 1;
        }
        else if (rt[count] > 0)
        {
            rt[count] -= time_quantum;
            time += time_quantum;
        }
        if ((rt[count] == 0) && (flag == 1))
        {
            remain--;
            printf("P[%d]\t  %d\t\t%d\t\t%d\n", count + 1, bt[count],
                     time - at[count] - bt[count], time - at[count]);
            wt += time - at[count] - bt[count];
            tat += time - at[count];
            flag = 0;
        }
        if (count == n - 1)
            count = 0;
        else if (at[count + 1] <= time)
            count++;
        else
            count = 0;
    }
    printf("Average waiting time= %f\n", wt * 1.0 / n);
    printf("Average turnaround time= %f\n", tat * 1.0 / n);
    return 0;
}
