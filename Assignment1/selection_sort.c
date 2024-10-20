#include<stdio.h>
#define SIZE 6
#define SWAP( a, b) int temp=a; a=b; b=temp;


void selection_sort(int[]);
void display(int[]);

int main()
{

    int arr[SIZE]={22,33,66,55,77,11};
    printf("Before sort: ");
    display(arr);
    selection_sort(arr);
    printf("\nAfter sort:   ");
    display(arr);
    printf("\n");
    return 0;
}

void selection_sort(int arr[SIZE])
{

    int  sel_pos, pos;
    int iterations=0,comparisons=0;

    for(sel_pos=0;sel_pos<SIZE-1;sel_pos++)
    {
        iterations++;
        for(pos=sel_pos+1;pos<SIZE;pos++)
        {
            comparisons++;
            if(arr[sel_pos]>arr[pos])
            {
                SWAP(arr[sel_pos],arr[pos]);
            }
        }
    }
    printf("\nIterations: %d Comparisons:%d\n",iterations,comparisons);
}

void display(int arr[SIZE])
{
    for(int i=0;i<SIZE;i++)
    {
        printf("%4d",arr[i]);
    }
}