#include <cstdio>
#include <algorithm>

using namespace std;

void getAllDistinctEle(int arr[], int n)
{
    std::sort(arr, arr+n);
    for (int i = 0; i < n; i++)
    {
        while ( i < n-1 && arr[i] == arr[i+1])
            i++;
        printf("%d ", arr[i]);
    }    
}

int main()
{
    int arr[] = {12, 10, 9, 3, 45, 10, 10, 12, 3, 4};
    int sz = sizeof(arr)/sizeof(arr[0]);
    getAllDistinctEle(arr, sz);
    return 0;
}
