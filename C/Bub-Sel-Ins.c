#include<stdio.h>
//bubble sort
void bubble(int a[], int n)
{
    int i, j, temp;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

//insertion sort
void insertion(int a[], int n)
{
    int i, j, temp;
    for(i=1;i<n-1;i++)
    {
        temp = a[i];
        j = i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

//selection sort
void selection(int a[], int n)
{
    int i, j, min, temp;
    for(i=0;i<n-1;i++)
    {
        min = i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
    }
}

void display(int a[], int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n\n");
}

int main()
{
    int i;
    int a[] = {98,3,1,6,33,334};
    int n = sizeof(a)/sizeof(a[0]);

    while(1)
    {
        printf("---Menu selection---\n");
        printf("1. Bubble sort\n");
        printf("2. Insertion sort\n");
        printf("3. Selection sort\n");
        printf("4. Exit\n");
        printf("--------------------\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                bubble(a, n);
                display(a, n);
                break;
            case 2:
                insertion(a, n);
                display(a, n);
                break;
            case 3:
                selection(a, n);
                display(a, n);
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}