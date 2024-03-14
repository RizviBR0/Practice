#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int roll;
    char name[20];
    struct node *next;
};
struct node *head;

int main()
{
    head = NULL;

    printf("Insertion.....\n");
    int r;
    char nam[20];

    struct node *New;
    New = (struct node *)malloc(sizeof(struct node));

    printf("Enter roll: ");
    scanf("%d", &r);
    printf("Enter name: ");
    scanf("%s", nam);

    if (head == NULL)
    {

        New->roll = r;
        strcpy(New->name, nam);
        New->next = NULL;

        head = New;
    }
    else
    {
        int n, m, i;

        printf("1: Insert from front\n");
        printf("2: Insert after specified number of nodes\n");
        scanf("%d", &n);

        switch (n)
        {
        case 1:

            New->roll = r;
            strcpy(New->name, nam);
            New->next = head;

            head = New;
            break;

        case 2:

            printf("\nEnter the node number:");
            scanf("%d", &m);

            int flag = 0;

            struct node *temp1;
            temp1 = head;

            for (i = 1; i < m; i++)
            {
                temp1 = temp1->next;
                if (temp1 == NULL)
                {
                    printf("\nNode does not exist");
                    flag = 1;
                    break;
                }
            }

            if (flag == 0)
            {
                New->roll = r;
                strcpy(New->name, nam);
                New->next = temp1->next;

                temp1->next = New;
            }
            else
                break;
        }
    }
}