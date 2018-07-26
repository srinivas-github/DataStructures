#include <stdio.h>
/**
 *  To rearrange the array of neg, pos numbers alternatively
 */

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void rearrange(int arr[], int n)
{
    int i = -1;
    for (int j = 0; j < n; j++)
    {
        if ( arr[j] < 0)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    
    int pos = i+1;
    int neg = 0;
    
    while ( pos < n && neg < pos && arr[neg]< 0)
    {
        swap(&arr[neg], &arr[pos]);
        pos++;
        neg += 2;
    }
}

int main()
{
    int arr[] = {-1, 2, -2, -3, -1, -2, 3, 2, -1, -4, -5, 6, 3, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    rearrange(arr, n);
    
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    
    return 0;
}
