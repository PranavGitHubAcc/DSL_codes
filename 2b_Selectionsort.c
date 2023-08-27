#include <stdio.h>

void swap(int*, int*);
void selection(int arr[], int size);

int main()
{
    int arr1[] = {6, 7, 2, 4, 8, 1, 12, 532, 233, 530, 0, -2, -9};
    int size = sizeof(arr1) / sizeof(arr1[0]);
    selection(arr1, size);
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection(int arr[], int size){
    for(int i = 0; i<size-1; i++){
        int imin= i;
        for(int k = i; k<size; k++)
            if(arr[imin]>arr[k]){
                imin = k;
            }
        swap(&arr[i],&arr[imin]);
    }
    for(int j = 0; j<size; j++){
        printf("%d ", arr[j]);
    }
}
