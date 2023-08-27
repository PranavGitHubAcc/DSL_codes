#include <stdio.h>

void insertion(int arr[], int size)
{
    for (int i = 0; i < size ; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0 && arr[j] > temp)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = temp;
    }
}

int main()
{
    int arr1[] = {24, 23, 62, 58, 12, 57};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    insertion(arr1, size);
    printf("Sorted array\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr1[i]);
    }
}