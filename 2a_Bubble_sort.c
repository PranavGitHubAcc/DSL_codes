#include <stdio.h>
void swap(int*, int*);
void bubbleSort(int arr[], int size);

int main()
{
    int size, arr1[100];
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter the elements for sorting: ");
    for(int i = 0; i<size; i++){
        scanf("%d", &arr1[i]);
    }
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
    printf("Sorted elements are: ");
    for(int k = 0; k<size;k++){
        printf("%d ", arr[k]);
    }
}
