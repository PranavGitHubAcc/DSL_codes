#include <stdio.h>

int main()
{
    int n, arr[100], key, j, flag = 1;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter the element you want to find: ");
    scanf("%d", &key);
    for (j = 0; j < n; j++)
    {
        if (arr[j] == key)
        {
            printf("Element present at %d position\n", j + 1);
            flag = 0;
        }
    }
    if (flag)
    {
        printf("Element not present");
    }
}