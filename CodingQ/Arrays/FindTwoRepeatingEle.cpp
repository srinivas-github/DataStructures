#include <stdio.h>
#include <stdlib.h>

void repeatingEle(int arr[], int size)
{
    int* count = (int*)calloc(sizeof(int), (size-2));
    
    printf("Repeating elements:\n");
    for (int i = 0; i < size; i++)
    {
        if (count[arr[i]] == 1)
            printf("%d ", arr[i]);
        else
            count[arr[i]]++;
    }
}

int main()
{
    int arr[] = {10, 3, 5, 6, 2, 3, 1,4,7,9,8,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    repeatingEle(arr, n);
    return 0;
}
