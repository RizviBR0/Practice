#include <stdio.h>
#include <stdlib.h>

int mutex = 1; // what is mutex here? ans-> mutex is a binary semaphore that is used to control access to a shared resource in concurrent programming.
int full = 0; // full is a counter that keeps track of the number of items in the buffer.
int empty = 5; // max_size is the maximum size of the buffer.

void producer()
{
    mutex--;
    full++;
    empty--;
    printf("\nProducer produces item %d", full);
    mutex++;
}

void consumer()
{
    mutex--;
    full--;
    empty++;
    printf("\nConsumer consumes item %d", full);
    mutex++;
}

int main()
{
    int n;
    printf("\n1. Press 1 for Producer"
           "\n2. Press 2 for Consumer"
           "\n3. Press 3 for Exit");

    while(1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);

        switch (n)
        {
        case 1:
            if (mutex == 1 && empty > 0)
            {
                producer();
            }
            else
            {
                printf("Buffer is full!");
            }
            break;

        case 2:
            if (mutex == 1 && full > 0)
            {
                consumer();
            }
            else
            {
                printf("Buffer is empty!");
            }
            break;

        case 3:
            exit(0);
            break;
        }
    }
    return 0;
}