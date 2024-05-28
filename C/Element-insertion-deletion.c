#include <stdio.h>

int main()
{
    int J, N, K, item;

    // taking array size from user input
    printf("Enter array size: ");
    scanf("%d", &N);

    int LA[N];

    // adding value to array
    for (int i = 1; i <= N; i++)
    {
        printf("Element %d : ", i);
        scanf("%d", &LA[i]);
    }

    // printing the array
    printf("Your array : ");
    for (int i = 1; i <= N; i++)
    {
        printf("%d ", LA[i]);
    }

    while (1)
    {
        int input;

        // menu for insert and delete
        printf("\nMenu\n----------------\n1. Insert\n2. Delete\n----------------\nEnter your choice: ");
        scanf("%d", &input);

        // switch case for insert and delete
        switch (input)
        {

        // insert case
        case 1:
            printf("Enter the position where you want to insert: ");
            scanf("%d", &K);
            printf("Enter the value you want to insert: ");
            scanf("%d", &item);

            // shifting the array
            for (J = N; J >= K; J--)
            {
                LA[J + 1] = LA[J];
            }
            LA[K] = item;
            N = N + 1;

            // printing the array
            printf("Your array : ");
            for (int i = 1; i <= N; i++)
            {
                printf("%d ", LA[i]);
            }
            printf("\n\n");
            break;

        // delete case
        case 2:
            printf("Enter the position where you want to delete: ");
            scanf("%d", &K);

            // shifting the array
            item = LA[K];
            for (J = K; J <= N - 1; J++)
            {
                LA[J] = LA[J + 1];
            }
            N = N - 1;

            // printing the array
            printf("Your array : ");
            for (int i = 1; i <= N; i++)
            {
                printf("%d ", LA[i]);
            }
            printf("\n\n");
            break;

        // default case
        default:
            printf("Invalid input\n");
            break;
        }
    }
}