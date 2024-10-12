#include <stdio.h>
#define SIZE 9
int linear_search(int[], int, int);
int comparisons;
int main()
{
    int arr[SIZE] = {33, 55, 88, 77, 44, 11, 66, 22, 99};
    int key;

    printf("Enter the key to search: ");
    scanf("%d", &key);

    int result = linear_search(arr, key, 0);

    if (result == -1)
    {
        printf("Key not found! \n");
    }
    else
    {
        printf("Key found at index=%d\n", result);
    }
    printf("comparisons=%d\n", comparisons);
    return 0;
}

int linear_search(int arr[], int key, int index)
{
    comparisons++;
    if (index >= SIZE)
    {
        return -1;
    }
    if (arr[index] == key)
    {
        return index;
    }
    return linear_search(arr, key, index + 1);
}