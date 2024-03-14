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
    int input;

    head = NULL;

    while (1)
    {
        printf("\n-- Menu Selection --\n");
        printf("0) Quit\n");
        printf("1) Delete\n");
        printf("Enter choice: ");
        scanf("%d", &input);

        switch (input)
        {
        case 0:
        default:
            printf("Goodbye......\n");
            exit(0);
            break;

        case 1:
            printf("Delete....\n");
            int inp;
            int s, i, flag;

            if (head == NULL)
            {
                printf("\nNo node to delete....\n");
            }
            else
            {
                struct node *t;
                t = (struct node *)malloc(sizeof(struct node));

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

                    struct node *old1;
                    old1 = (struct node *)malloc(sizeof(struct node));

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
            break;

            return 0;
        }
    }
}