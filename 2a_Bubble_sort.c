#include <stdio.h>
void swap(int*, int*);
void bubbleSort(int arr[], int size);

int main()
{
    int arr1[] = {6, 7, 2, 4, 8, 1, 12, 532, 233, 530, 0, -2, -9};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    bubbleSort(arr1, size);
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int size){
    for(int i = 0; i<size-1; i++){
        int flag = 1;
        for(int j = 0; j<size-i-1; j++){
            if(arr[j]>arr[j+1]){
                flag = 0;
                swap(&arr[j], &arr[j+1]);
            }
        }
        if(flag)
            break;
    }
    for(int k = 0; k<size;k++){
        printf("%d ", arr[k]);
    }
}