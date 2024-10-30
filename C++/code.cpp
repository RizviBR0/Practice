#include <iostream>
using namespace std;

// insertion sort
void insertion(int a[], int n)
{
    int i, j, t;
    for (j = 1; j < n; j++)
    {
        t = a[j];
        i = j - 1;
        while (i >= 0 && a[i] > t)
        {
            a[i + 1] = a[i];
            i--;
        }
        a[i + 1] = t;
    }
}

// bubble sort
void bubble(int a[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
            }
        }
    }
}

// selection sort
void selection(int a[], int n)
{
    int i, j, min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            swap(a[min], a[i]);
        }
    }
}

// swap function
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

// display function
void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n---------------------------------\n");
}

int main()
{
    int n, i;

    printf("Enter number of elem: ");
    scanf("%d", &n);

    int a[n];

    for (i = 0; i < n; i++)
    {
        printf("Elem %d: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("\n---------------------------------\n");
    printf("Array : ");
    display(a, n);

    // selection(a, n);
    // insertion(a, n);
    bubble(a, n);

    printf("Sorted array : ");
    display(a, n);
}