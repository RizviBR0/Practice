#include <stdio.h>

int main()
{

    int n;
    printf("Number of Process: ");
    scanf("%d", &n);
    int burstTime[n], process[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter Burst Time for Process %d: ", i);
        scanf("%d", &burstTime[i]);
        process[i] = i;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (burstTime[j] < burstTime[i])
            {
                int temp = burstTime[j];
                burstTime[j] = burstTime[i];
                burstTime[i] = temp;
                temp = process[j];
                process[j] = process[i];
                process[i] = temp;
            }
        }
    }

    int waitingTime[n];
    waitingTime[0] = 0;
    int tat[n]; // tat - Turn Around Time
    double total_waitingTime = 0, total_tat = 0;

    for (int i = 1; i < n; i++)
    {
        waitingTime[i] = burstTime[i - 1] + waitingTime[i - 1];
        tat[i - 1] = burstTime[i - 1] + waitingTime[i - 1];
    }
    tat[n - 1] = burstTime[n - 1] + waitingTime[n - 1];

    printf("-----------------------------------------------------------\nProcesses   Burst time     Waiting time   Turn around time\n");
    for (int i = 0; i < n; i++)
    {
        total_waitingTime = total_waitingTime + waitingTime[i];
        total_tat = total_tat + tat[i];
        printf("    P%d ", process[i]);
        printf("\t\t%d ", burstTime[i]);
        printf("\t\t%d", waitingTime[i]);
        printf("\t\t%d\n", tat[i]);
    }

    double avg_waitingTime = total_waitingTime / n;
    double avg_tat = total_tat / n;
    printf("-----------------------------------------------------------\nAverage waiting time\t\t= %.3lf", avg_waitingTime);
    printf("\n");
    printf("Average turn around time\t= %.3lf ", avg_tat);
    return 0;
}