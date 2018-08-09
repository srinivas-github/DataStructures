#include <stdio.h>
#include <stdlib.h>

void productArr(int arr[], int n)
{
    int *L = (int*)malloc(sizeof(int) * n);
    int *R = (int*)malloc(sizeof(int) * n);
    int *P = (int*)malloc(sizeof(int) * n);
    
    L[0] = 1;
    R[n-1] = 1;
    
    for (int i = 1; i < n; i++)
        L[i] = arr[i-1] * L[i-1];
        
    for (int j = n-2; j>=0; j--)
        R[j] = arr[j+1] * R[j+1];
    
    for(int p = 0; p < n; p++)
        P[p] = L[p] * R[p];
    
    for (int i = 0; i < n; i++)
        printf("%d ", P[i]);
    
}

int main()
{
    int arr[] = {10, 0, 3, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    productArr(arr, n);
    return 0;
}
