#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int minDiff(int A[], int B[], int m, int n)
{
    int a = 0, b = 0;
    int result = INT_MAX;
    std::sort(A, A+n);
    std::sort(B, B+m);
    
    while ( a < m && b < n)
    {
        if (abs(A[a]-B[b] < result)
            result = abs(A[a] - B[b]);
        if ( A[a] < B[b] )
            a++;
        else
            b++;
    }
    return result;
}

int main()
{
    int A[] = {12,3,4,555, 67, 11};
    int B[] = {45, 5, 67, 89, 77};
    
    int res = minDiff(A, B, sizeof(A)/sizeof(A[0]), sizeof(B)/sizeof(B[0]);
    return 0;
}
