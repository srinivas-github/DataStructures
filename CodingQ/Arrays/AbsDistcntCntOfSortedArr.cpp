#include <bits/stdc++.h>
using namespace std;

int distinctCnt(int arr[], int n)
{
    unordered_set<int> s;
    
    for (int i = 0; i <n; i++)
    {
        s.insert(abs(arr[i]));
    }
    
    return s.size();
}

/**
 * Below method assumes that the array is sorted
 */
int distinctCnt_O1(int arr[], int n)
{
    int count = n;
    
    int i = 0, j = n-1, sum = 0;
    while (i < j)
    {
        while (i != j && arr[i] == arr[i+1])
        {
            count--;
            i++;
        }
        while (i != j && arr[j] == arr[j-1])
        {
            count--;
            j--;
        }
    
        if (i==j)
            break;
        sum = arr[i] + arr[j];
        if (sum == 0)
        {
            count--;
            i++;
            j--;
        }
        else if(sum < 0)
            i++;
        else
            j--;
    }
    return count;
}

int main()
{
    int arr[] = {0,-1,1,-1,-1,1,0,2,-2,2,-1,-1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    int dCnt = distinctCnt(arr, n);
    printf("V1: %d \n", dCnt);
    
    int arr1[] = {-2,-1,0, 1,2};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    
    int dCnt1 = distinctCnt_O1(arr1, n1);
    printf("V2: %d\n", dCnt1);
    return 0;
}
