#include <stdio.h>

int bs(int arr[], int, int, int);

int main()
{
    
    int n, arr1[100], key, result;;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr1[i]);
    }
    printf("Enter the number that you want to search: ");
    scanf("%d", &key);
    result = bs(arr1, key, 0, 6); 
    if(result>0){
        printf("%d is present at %d", key, result);
    }
    else
        printf("Not present");
    
}

int bs(int arr[], int number, int lower, int higher)
{
    if(lower<=higher){
        int mid = (higher+lower)/2;
        if (arr[mid] == number)
            return mid+1;
        else if(arr[mid]<number)
            return bs(arr,number,++mid,higher);
        else
            return bs(arr,number,lower,--mid);
    }
    else
        return(-1);
}
