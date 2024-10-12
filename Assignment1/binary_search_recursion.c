#include <stdio.h>
#define SIZE 9
int comparisons;
int binary_search(int[], int);
int rec_binary_search(int[], int, int, int);

int main()
{
    int arr[SIZE] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int key;

    printf("Enter the key to search: ");
    scanf("%d", &key);

    printf("\n Recursive Binary Search:\n");
    int res = rec_binary_search(arr, key, 0, SIZE - 1);
    if (res == -1)
        printf("Key not found!\n");
    else
        printf("Key found at index=%d\n", res);
    return 0;
}
int rec_binary_search(int arr[SIZE], int key, int left, int right)
{
    int mid, res;
    if (left > right)
        return -1;
    mid = (left + right) / 2;
    if (key == arr[mid])
        return mid;
    if (key < arr[mid])
    {
        res = rec_binary_search(arr, key, left, mid - 1);
    }
    else
    {
        res = rec_binary_search(arr, key, mid + 1, right);
    }
    return res;
}