#include <stdio.h>
int main()
{
    int i, j, n, burstTime[10], waitingTime[10], turnaroundTime[10], timeSlice, cycleTimes[10], max;
    float avg_waitingTime = 0, avg_tat = 0, temp = 0;

    printf("Enter the no of processes -- ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("\nEnter Burst Time for process %d -- ", i + 1);
        scanf("%d", &burstTime[i]);
        cycleTimes[i] = burstTime[i];
    }

    printf("\nEnter the size of time slice -- ");
    scanf("%d", &timeSlice);

    max = burstTime[0];

    for (i = 1; i < n; i++) // Finding Maximum BurstTime
    {
        if (max < burstTime[i])
        {
            max = burstTime[i];
        }
    }

    for (i = 0; i < (max / timeSlice) + 1; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (burstTime[j] != 0)
            {
                if (burstTime[j] <= timeSlice)
                {
                    turnaroundTime[j] = temp + burstTime[j];
                    temp = temp + burstTime[j];
                    burstTime[j] = 0;
                }
                else
                {
                    burstTime[j] = burstTime[j] - timeSlice;
                    temp = temp + timeSlice;
                }
            }
        }
    }

    for (i = 0; i < n; i++)
    {
        waitingTime[i] = turnaroundTime[i] - cycleTimes[i];
        avg_tat += turnaroundTime[i];
        avg_waitingTime += waitingTime[i];
    }

    printf("\n\tPROCESS\t BURST TIME \t WAITING TIME\tTURNAROUND TIME\n");
    for (i = 0; i < n; i++)
    {
        printf("\t%d \t %d \t\t %d \t\t %d \n", i + 1, cycleTimes[i], waitingTime[i], turnaroundTime[i]);
    }
    printf("\n\nThe Average Turnaround time is -- %f", avg_tat / n);
    printf("\nThe Average Waiting time is -- %f ", avg_waitingTime / n);
}