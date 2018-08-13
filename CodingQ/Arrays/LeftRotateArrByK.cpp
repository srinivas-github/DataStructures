#include <stdio.h>

void leftRotate(int arr[], int n)
{
    int temp = arr[0],i;
    for (i = 0; i <n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    arr[i] = temp;
}

void leftRotateByK(int arr[], int k, int n)
{
    for (int i = 0; i < k; i++)
        leftRotate(arr, n);
}

int main()
{
    int arr[] = {1,2,3,4,5,6,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k = 2;
    leftRotateByK(arr, k, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
