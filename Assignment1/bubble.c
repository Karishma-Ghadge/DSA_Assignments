#include <stdio.h>
#define SIZE 5
int cmp = 0, pass = 0;
int bubble(int arr[SIZE])
{
    int temp;
    for (int i = 0; i < SIZE - 1; i++)
    {
        for (int j = 0; j < SIZE - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                cmp++;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
        pass++;
    }
}
int main()
{
    int arr[SIZE] = {5, 4, 3, 2, 1};
    bubble(arr);
    for (int i = 0; i < SIZE; i++)
    {
        printf("%4d\n", arr[i]);
    }
    printf("Number of Comparisons: %d\n", cmp);
    printf("Number of Passes:%d\n", pass);
    return 0;
}