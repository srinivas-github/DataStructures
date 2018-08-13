#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Pair
{
    int min;
    int max;
};

struct Pair getMinMax(int arr[], int n)
{
    struct Pair pair;
    
    if (n == 1)
    {
        pair.min = arr[0];
        pair.max = arr[0];
        return pair;
    }
    
    if (arr[0] > arr[1])
    {
        pair.max = arr[0];
        pair.min = arr[1];
    }
    else
    {
        pair.max = arr[1];
        pair.min = arr[0];
    }
    
    for (int i = 2; i < n; i++)
    {
        if (arr[i] > pair.max)
            pair.max = arr[i];
        else if (arr[i] < pair.min)
            pair.min = arr[i];
    }
    return pair;
}

struct Pair getMinMax_v2(int arr[], int low, int high)
{
    struct Pair pair;
    struct Pair left_pair;
    struct Pair right_pair;
    
    int mid;
    
    if (low == high)
    {
        pair.min = arr[0];
        pair.max = arr[0];
        return pair;
    }
    
    if ( high == low+1)
    {
        if (arr[low] > arr[high])
        {
            pair.min = arr[high];
            pair.max = arr[low];
        }
        else
        {
            pair.min = arr[low];
            pair.max = arr[high];
        }
        return pair;
    }
    
    mid = (low+high)/2;
    left_pair = getMinMax_v2(arr, low, mid);
    right_pair = getMinMax_v2(arr, mid+1, high);
    
    if (left_pair.min < right_pair.min)
        pair.min = left_pair.min;
    else
        pair.min = right_pair.min;
        
    if (left_pair.max > right_pair.max)
        pair.max = left_pair.max;
    else
        pair.max = right_pair.max;
        
    return pair;
    
}

int main()
{
    int arr[] = {1001, 100, 1, 111, 110, 50, 101};
    int n = sizeof(arr)/sizeof(arr[0]);
    struct Pair pair = getMinMax(arr, n);
    printf("Min: %d, Max: %d \n", pair.min, pair.max);
    
    pair = getMinMax_v2(arr, 0, n-1);
    printf("Min: %d, Max: %d \n", pair.min, pair.max);
    return 0;
}
