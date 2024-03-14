#include <stdio.h>
#include <stdlib.h>

#define max 5

int stack[max], i, top = -1;

void push()
{
    int item;
    if (top == max - 1)
    {
        printf("Overflow\n");
        return;
    }
    else
    {
        printf("enter the value for push : ");
        scanf("%d", &item);
        top++;
        stack[top] = item;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Underflow.\n");
        return;
    }
    else
    {
        top--;
    }
}

void display()
{
    if (top == -1)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack elements : ");
        for (i = 0; i <= top; i++)
        {
            printf("%d ", stack[i]);
        }
    }
    printf("\n");
}

int main()
{
    int input;

    while (1)
    {
        printf("\n---Menu Selection---\n");
        printf("1) Push\n");
        printf("2) Pop\n");
        printf("3) Display\n");
        printf("0) Quit\n");
        printf("Enter choice: ");
        scanf("%d", &input);

        switch (input)
        {
        case 0:
            printf("...GOOD BYE...\n\n");
            break;
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            printf("%d", top);
            display();
            break;
        default:
            printf("Invalid choice.\n\n");
        }
    }
}