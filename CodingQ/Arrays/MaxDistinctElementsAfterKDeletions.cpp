#include <iostream>
#include <bits/stdc++.h>

int maxDistinctElements(int arr[], int n, int k)
{
    unordered_map<int, int> um;
    priority_queue<int> pq;
    
    for (int i = 0; i < n; i++)
        um[arr[i]]++;
    for (auto it = um.begin(); it != um.end(); it++)
        pq.push(it->second);
    
    while (k--)
    {
        int temp = ps.top();
        pq.pop();
        temp--;
        if (temp != 0)
            pq.push(temp);   
    }
    return ( (int)pq.size());
}

int main()
{
    int arr[] = {5,7,5,5,2,2,1};
    int k = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    std::cout<<"Max distinct elements:"<<maxDistinctElements(arr, n, k);
    return 0;
}
