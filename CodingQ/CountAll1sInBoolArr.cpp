#include <cstdio>
using namespace std;

int getCountOfOnes(bool arr[], int low, int high)
{
    int mid;
    if (high >= low)
    {
        mid = low + (high-low)/2;
        if ( ( (mid == high) || (arr[mid+1] == 0)) && arr[mid] == 1)
            return mid+1;
        else if (arr[mid] == 1)
            return getCountOfOnes(arr, mid+1, high);
        else 
            return getCountOfOnes(arr, low, mid-1);
    }
}

int main()
{
    bool arr[] = {1,1,1,1,1,1,0,0,0,0,0,0,0,0};
    int sz = sizeof(arr)/sizeof(arr[0]);
    printf("1's Count: %d\n", getCountOfOnes(arr, 0, sz-1));
    return 0;
}
