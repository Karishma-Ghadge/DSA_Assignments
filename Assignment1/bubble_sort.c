#include<stdio.h>
#define SIZE 6
#define SWAP(a,b) int temp=a; a=b; b=temp;

void bubble_sort(int[]);
void display(int[]);
void efficient_bubble_sort(int[]);

int main()
{
    int arr[SIZE]={30,20,10,40,50,60};
    printf("\n Before sort: \n");
    display(arr);
    bubble_sort(arr);
    printf("\n After sort:  \n");
    display(arr);

    efficient_bubble_sort(arr);
    display(arr);
    printf("\n");
    return 0;
}

void bubble_sort(int arr[SIZE])
{
    int its,pos;
    int iterations=0,comparisons=0;

    for(its=0;its<SIZE-1;its++)
    {
        iterations++;
        for(pos=0;pos<SIZE-1-its;pos++)
        {
            comparisons++;
            if(arr[pos]>arr[pos+1])
            {
                SWAP(arr[pos],arr[pos+1]);
            }
        }
    }
    printf("\nIterations: %d  Comparisons: %d\n",iterations,comparisons);
}

void display(int arr[SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
}
void efficient_bubble_sort(int arr[SIZE])
{
    int its,pos;
    int iterations=0,comparisons=0,flag;

    for(its=0;its<SIZE-1;its++)
    {
        flag=0;
        iterations++;
        for(pos=0;pos<SIZE-1-its;pos++)
        {
            comparisons++;
            if(arr[pos]>arr[pos+1])
            {
                SWAP(arr[pos],arr[pos+1]);
                flag=1;
            }
        }
        if(flag==0)
        break;
    }
    printf("\nIterations: %d  Comparisons: %d\n",iterations,comparisons);
}