#include <stdio.h>
#include <stdlib.h>

// Swap utility
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// Simple bubble sort ascending
void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main()
{
    int n, head, size;
    printf("Enter disk size (max track number): ");
    scanf("%d", &size);
    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];
    printf("Enter request queue (space-separated):\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    printf("Enter head movement direction (0 = towards 0, 1 = towards %d): ", size - 1);
    int dir;
    scanf("%d", &dir);

    // Add head and end as requests
    int total = n + 2; // 10
    int all[total];    // all[10]
    for (int i = 0; i < n; i++)
    {
        all[i] = req[i];
    }
    all[n] = head;
    all[n + 1] = (dir == 1 ? size - 1 : 0); // all[10] = 51, all[11] = 0 or size - 1

    sort(all, total);

    // Find index of head in sorted list
    int idx;
    for (int i = 0; i < total; i++)
    {
        if (all[i] == head)
        {
            idx = i;
            break;
        }
    }

    long seek = 0;
    printf("\nService order:\n");

    if (dir == 1)
    {
        // Move right from head to end
        for (int i = idx; i < total - 1; i++)
        {
            printf("%d -> ", all[i]);
            seek += abs(all[i + 1] - all[i]);
        }
        // Then reverse: from end backwards to before head
        for (int i = total - 1; i > 0; i--)
        {
            printf("%d -> ", all[i]);
            seek += abs(all[i] - all[i - 1]);
        }
    }
    else
    {
        // Move left from head to 0
        for (int i = idx; i > 0; i--)
        {
            printf("%d -> ", all[i]);
            seek += abs(all[i] - all[i - 1]);
        }
        // Then reverse: from 0 upwards past head
        for (int i = 0; i < total - 1; i++)
        {
            printf("%d -> ", all[i]);
            seek += abs(all[i + 1] - all[i]);
        }
    }
    printf("end\n");
    printf("\nTotal head movement = %ld tracks\n", seek);

    return 0;
}