#include <stdio.h>

int main()
{
    int n, m; // n = number of processes, m = number of resources

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int max[n][m];        // Maximum resources a process can request
    int allocation[n][m]; // Resources already allocated to each process
    int available[m];     // Available resources
    int need[n][m];       // Need = Max - Allocation

    // Get max resource matrix
    printf("Enter max resource matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }

    // Get allocation matrix
    printf("Enter allocation matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &allocation[i][j]);
        }
    }

    // Get available resources
    printf("Enter available resources:\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &available[i]);
    }

    // Calculate need matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // Print need matrix
    printf("\nNeed Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    // Banker's Algorithm for deadlock avoidance
    int finish[n];
    for (int i = 0; i < n; i++)
    {
        finish[i] = 0; // Initialize finish array
    }

    int work[m];
    for (int i = 0; i < m; i++)
    {
        work[i] = available[i]; // Initialize work array with available resources
    }

    int safeSeq[n];
    int count = 0;

    // Find safe sequence
    while (count < n) // while(0 < 5)
    {
        int found = 0;
        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                // Check if process can be allocated all needed resources
                int can_allocate = 1;
                for (int j = 0; j < m && can_allocate; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        can_allocate = 0;
                    }
                }
                if (can_allocate)
                {
                    // Process can execute - update work array and mark as finished
                    for (int k = 0; k < m; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safeSeq[count++] = i;
                    finish[i] = found = 1;
                }
            }
        }
        if (!found)
        {
            break;
        } // No safe sequence found
    }

    // Output results
    if (count < n)
    {
        printf("\nSystem is in UNSAFE state! Deadlock might occur.\n");
        printf("Deadlock causing processes are:\n");
        for (int i = 0; i < n; i++)
        {
            if (!finish[i])
            {
                printf("P%d ", i);
            }
        }
        printf("\n");
    }
    else
    {
        printf("\nSystem is in SAFE state.\n");
        printf("Safe sequence is: ");
        for (int i = 0; i < n; i++)
        {
            printf("P%d ", safeSeq[i]);
        }
        printf("\n");
    }

    return 0;
}