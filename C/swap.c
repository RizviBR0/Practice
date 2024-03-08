#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 6, b = 3;
    printf("Before X = %d, Y = %d\n", a, b);
    swap(&a, &b);
    printf("After X = %d, Y = %d\n", a, b);
}