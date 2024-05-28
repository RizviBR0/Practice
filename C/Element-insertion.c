#include<stdio.h>

int main()
{
    int J,N,K,item;

    //taking array size from user input
    printf("Enter array size: ");
    scanf("%d", &N);

    int LA[N];

    //adding value to array
    for(int i=1;i<=N;i++)
    {
        printf("Element %d : ", i);
        scanf("%d", &LA[i]);
    }

    //printing the array
    printf("Your array : ");
    for(int i=1;i<=N;i++)
    {
        printf("%d ", LA[i]);
    }
    printf("\n");

    //the value
    printf("Enter a value: ");
    scanf("%d", &item);

    //enter a position where you want to insert a value
    printf("Enter a position: ");
    scanf("%d", &K);

    //insertion algorithm
    J=N;
    while(J>=K)
    {
        LA[J+1]=LA[J];
        J--;
    }
    LA[K] = item;
    N++;

    //printing the array  after insertion
    printf("Array after insertion: ");
    for(int i=1;i<=N;i++)
    {
        printf("%d ", LA[i]);
    }
}