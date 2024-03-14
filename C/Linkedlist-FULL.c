#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int roll;
    char name[20];     // info
    struct node *next; // link
} node;
struct node *head;

void LinkedListInsert()
{
    int r;
    char nam[20];

    node *New;
    New = (node *)malloc(sizeof(node));

    printf("Enter roll: ");
    scanf("%d", &r);
    printf("\nEnter name: ");
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
        printf("2: Insert before specified number of nodes\n");
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

            node *temp1;
            temp1 = head;

            if (m == 1)
            {
                New->roll = r;
                strcpy(New->name, nam);
                New->next = head;
                head = New;
            }
            else
            {
                for (i = 1; i < m - 1; i++)
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
}

void LinkedListDisplay()
{
    node *tt;

    if (head == NULL)
        printf("\n...NO Item in Link List...\n");

    else
    {
        tt = head;

        while (tt != NULL)
        {
            printf("\nRoll No: %d", tt->roll);
            printf("\nName: %s\n", tt->name);
            tt = tt->next;
        }
    }
}

void LinkedListDelete()
{
    int inp;
    int s, i, flag;

    if (head == NULL)
    {
        printf("\nNo node to delete....\n");
    }
    else
    {
        node *t;
        t = (node *)malloc(sizeof(node));

        printf("1: Delete from front: \n");
        printf("2: Delete specified number of node: \n");
        scanf("%d", &inp);

        switch (inp)
        {
        case 1:
            t = head;
            head = t->next;

            free(t);
            break;

        case 2:
            printf("\nEnter the node number:");
            scanf("%d", &s);

            t = head;
            flag = 0;

            node *old1;
            old1 = (node *)malloc(sizeof(node));

            for (i = 1; i < s; i++)
            {
                old1 = t;
                if (old1->next == NULL)
                {
                    printf("\nnode does not exist:");
                    flag = 1;
                    break;
                }
                t = t->next;
            }

            if (flag == 0)
            {
                old1->next = t->next;
                free(t);
                break;
            }
            else
                break;
        }
    }
}

int main()
{
    int input;

    head = NULL;
    while (1)
    {
        printf("\n-- Menu Selection --\n");
        printf("0) Quit\n");
        printf("1) Insert\n");
        printf("2) Display\n");
        printf("3) Delete\n");
        printf("Enter choice: ");
        scanf("%d", &input);

        switch (input)
        {
        case 0:
            printf("Program Terminated\n");
            return 0;

        case 1:
            printf("Insertion.....\n");
            LinkedListInsert();
            break;

        case 2:
            printf("Display.....\n");
            LinkedListDisplay();
            break;

        case 3:
            printf("Delete....\n");
            LinkedListDelete();
            break;

        default:
            printf("Invalid Choice!\n");
        }
    }
}