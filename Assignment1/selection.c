#include <stdio.h>
#define SIZE 5
int comp = 0, pass = 0;
int selection_sort(int arr[SIZE])
{
    int temp;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = i + 1; j < SIZE; j++)
        {
            if (arr[i] > arr[j])
            {
                comp++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        pass++;
    }
}
int main()
{
    int arr[SIZE] = {5, 4, 3, 2, 1};

    selection_sort(arr);

    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\n", arr[i]);
    }
    printf("Number of Comparisons: %d\n", comp);
    printf("Number of Passes:%d\n", pass);
    return 0;
}