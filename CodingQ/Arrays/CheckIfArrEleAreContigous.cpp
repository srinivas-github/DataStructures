#include <iostream>
#include <bits/stdc++.h>

bool isElementsContigous(int arr[], int n)
{
    std::sort(arr, arr+n);
    
    for(int i = 1; i < n; i++)
        if ( arr[i] - arr[i-1] > 1)
            return false;
    return true; 
}

int main()
{
    int arr[] = {5,3,2,4,4,6,4,7};
    int n = sizeof(arr)/sizeof(arr[0]);
    if ( isElementsContigous(arr, n))
        std::cout<<"Yes\n";
    else
        std::cout<<"No\n";
    return 0;
}
