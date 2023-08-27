#include <stdio.h>

void merge(int arr[],int lb,int mid,int ub, int size)
{
    int i=lb, j=mid+1, k=lb;
    int b[size];
    if(lb<ub){
        while(i<=mid && j<=ub){
            if(arr[i]<=arr[j]){
                b[k] = arr[i];
                i++;
            }
            else{
                b[k] = arr[j];
                j++;
            }
            k++;
        }
        if(i>mid){
            while(j<=ub){
                b[k] = arr[j];
                j++;
                k++;
            }
        }
        else
            while(i<=mid){
                b[k] = arr[i];
                i++;
                k++;
            }
    }
    for(k=lb;k<=ub;k++){
        arr[k] = b[k];
    }
}

void ms(int arr[], int lb, int ub, int size){
    if(lb<ub){
        int mid = (lb+ub)/2;
        ms(arr, lb, mid, size);
        ms(arr, mid+1, ub, size);
        merge(arr, lb, mid, ub, size);
    }
}

int main(){
    int arr[] = {-12, 52, 21, 90, -30, 42, 5, 32};
    int size = sizeof(arr)/ sizeof(arr[0]);
    ms(arr, 0, size-1, size);
    for(int i = 0; i< size; i++){
        printf("%d ",arr[i]);
    }
}