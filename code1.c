#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    printf("Enter array size: ");
    scanf("%d", &n);

    int a[n];

    for (i = 1; i <= n; i++)
    {
        printf("Enter element %d: ", i);
        scanf("%d", &a[i]);
    }

    printf("Array elements : ");
    for (i = 1; i <= n; i++)
    {
        printf("%d ", a[i]);
    }

    int j, temp;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }

        printf("\nSorted elements : ");
        for (i = 1; i <= n; i++)
        {
            printf("%d ", a[i]);
        }
    }
}
