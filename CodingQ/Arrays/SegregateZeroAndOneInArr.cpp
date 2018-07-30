#include <stdio.h>

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

void segregateZeroAndOnes(int arr[], int n)
{
    int cnt = 0;
    
    for (int i = 0; i < n; i++)
    {
        if ( arr[i] == 0)
            cnt++;
    }
    
    for (int i = 0; i < cnt; i++)
        arr[i] = 0;
    for( int i = cnt; i < n; i++)
        arr[i] = 1;
    
}

void segregateZeroAndOnes_v1(int arr[], int n)
{
    int left = 0, right = n-1;
    
    while ( left < right)
    {
        while (arr[left] == 0 && left < right)
            left++;
        while (arr[right] == 1 && left < right)
            right--;
        if ( left < right)
        {
            arr[left] = 0;
            arr[right] = 1;
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[] = {0,1,1,0,0,0,1,0,0,1,0,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    printArr(arr, n);
    printf("\n");
    //segregateZeroAndOnes(arr, n);
    segregateZeroAndOnes_v1(arr, n);
    printArr(arr, n);
    
    return 0;
}
