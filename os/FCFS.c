#include <stdio.h>
int main()
{
	int n, bt[20], wt[20], tat[20], i, j;
	float avwt, avtat;
	printf("                     FCFS SCHEDULING\n");
	printf("                    =================\n");
	printf("Enter total number of processes: ");
	scanf("%d", &n);
	printf("\nEnter burst time :\n");
	for (i = 0; i < n; i++)
	{
		printf("P[%d]: ", i + 1);
		scanf("%d", &bt[i]);
	}
	wt[0] = 0;
	for (i = 0; i < n; i++)
	{
		wt[i] = 0;
		for (j = 0; j < i; j++)
			wt[i] += bt[j];
	}
	printf("\nProcess\t  Burst time\tWaiting time\tTurnaround time\n");
	for (i = 0; i < n; i++)
	{
		tat[i] = bt[i] + wt[i];
		avwt += wt[i];
		avtat += tat[i];
		printf("P[%d]\t  %d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
	}
	avwt /= i;
	avtat /= i;
	printf("\nAverage Waiting Time: %f\n", avwt);
	printf("Average Turnaround Time: %f\n", avtat);
	return 0;
}
