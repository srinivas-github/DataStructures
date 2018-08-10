#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printSortedArr(int arr[], int n)
{
    int front = -1, back = -1;
    for (int i = 1; i < n; i++)
    {
        if ( arr[i] < arr[i-1])
        {
            front = i-1;
            break;
        }
    }
    for (int i = n-2; i>=0; i--)
    {
        if (arr[i] > arr[i+1])
        {
            back = i+1;
            break;
        }
    }
    if (front == -1 && back == -1)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", arr[i]);
            return ;
        }
    }
    while (front < back)
    {
        swap(&arr[front], &arr[back]);
        front++;
        back--;
    }
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    return ;    
}

int main()
{
    int arr[] = {2,4,6,12,20, 55, 50, 45, 40, 60,70,80,90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printSortedArr(arr, n);
    return 0;
}
