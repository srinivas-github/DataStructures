#include <bits/stdc++.h>
using namespace std;

string commonPrefixUtil(string s1, string s2)
{
    string result;
    
    int n1 = s1.length();
    int n2 = s2.length();
    
    for (int i=0, j = 0; i <=n1-1, j<=n2-1; i++, j++)
    {
        if (s1[i] != s2[i])
            break;
        result.push_back(s1[i]);
    }
    return result;
    
}

void commonPrefix(string arr[], int n)
{
    sort(arr, arr+n);
    
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"\n";
    cout<<"Largest Common Prefix: "<<commonPrefixUtil(arr[0], arr[n-1]);
}

int main()
{
    string arr[] = { "geeksforgeeks", "geeksfor", "geekzer" };
    int n = sizeof(arr)/sizeof(arr[0]);
    commonPrefix(arr, n);
    return 0;
    
}
