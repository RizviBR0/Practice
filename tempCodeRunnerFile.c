#include <stdio.h>

int main()
{
    int n, i;
    printf("Enter array size: ");
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Array elements : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    int k = n, j, temp;

    for (i = 0; i < k; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }

    printf("\nSorted elements : ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
}