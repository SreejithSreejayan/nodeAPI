#include <stdio.h>
#include <stdlib.h>
int main()
{
    int RQ[100], i, n, TotalHeadMovt = 0, initial;
    printf("                     FCFS DISK SCHEDULING\n");
    printf("                    ======================\n");
    printf("Enter the number of Requests : ");
    scanf("%d", &n);
    printf("Enter the Request Sequence\n");
    for (i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter the initial head position :");
    scanf("%d", &initial);

    for (i = 0; i < n; i++)
    {
        TotalHeadMovt = TotalHeadMovt + abs(RQ[i] - initial);
        initial = RQ[i];
    }

    printf("Total Head Movement is %d\n", TotalHeadMovt);
}