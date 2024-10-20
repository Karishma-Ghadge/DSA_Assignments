#include <stdio.h>
#define SIZE 6
int pass, cmp;
void insertion_sort(int[]);
void display(int[]);
int main()
{
    int arr[SIZE] = {5, 2, 3, 7, 4, 6};
    printf("Array Before Sort: \n");

    display(arr);

    insertion_sort(arr);
    printf("\nArray After Sort: \n");
    display(arr);
    printf("Number of Comparisons: %d\n", cmp);
    printf("Number of Passes:%d\n", pass);
    return 0;
}

void insertion_sort(int arr[SIZE])
{
    int i, j, temp;
    for (i = 1; i < SIZE; i++)
    {
        pass++;
        temp = arr[i];
        for (j = i - 1; j >= 0 && temp < arr[j]; j--)
        {
            cmp++;
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
    }
}
void display(int arr[SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%4d", arr[i]);
    }
}
