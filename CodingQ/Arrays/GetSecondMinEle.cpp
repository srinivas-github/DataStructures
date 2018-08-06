#include <limits.h>
#include <stdio.h>

int getMinProd(int arr[], int n)
{
    int first  = INT_MAX;
    int second = INT_MAX;
    
    for (int i = 0; i < n; i++)
    {
        if  (arr[i] < first)
        {  
            second = first;
            first = arr[i];
        }
        else if( arr[i] < second && arr[i] != first)
        {
            second = arr[i];
        }
    }
    printf("Min1: %d, Min2: %d\n", first, second);
    return first * second;
     
}
int main()
{
    int arr[] = {13, 14, 15, 4, 2, 10};
    int n = sizeof(arr)/sizeof(arr[0]);
    int prod = getMinProd(arr, n);
    printf("Min Prod: %d\n", prod);
    return 0;
}
