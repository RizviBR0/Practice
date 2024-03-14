#include <stdio.h>
#define max 5
int queue[max], front = -1, rear = -1, i, item;

void enqueue()
{
    if (rear == max - 1)
    {
        printf("Overflow.\n");
        return;
    }
    else
    {
        printf("Enter the element: ");
        scanf("%d", &item);
        rear++;
        queue[rear] = item;
    }
}

void dequeue()
{
    if (front == max || front == rear)
    {
        printf("Underflow.\n");
        return;
    }
    else
    {
        front++;
    }
}

void display()
{
    printf("Queue : ");
    for (i = front + 1; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }
}

int main()
{
    int choice;
    while (1)
    {
        printf("\n\n------Menu------\n1. Insert.\n2. Delete.\n3. Display.\n0. Exit.\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 0:
            exit(0);
            break;

        case 1:
            enqueue();
            break;

        case 2:
            dequeue();
            break;

        case 3:
            display();
            break;

        default:
            printf("Invalid choice.\n");
            break;
        }
    }
}