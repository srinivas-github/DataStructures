#include <iostream>
#include <climits>

void print2Largest(int arr[], int n)
{
    int fisrt = INT_MIN;
    int second = INT_MIN;
    
    if ( n < 2)
        return ;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > fisrt)
        {
            second = fisrt;
            fisrt =arr[i];
        }
        else if ( arr[i] > second && arr[i] != fisrt)
            second = arr[i];
    }
    
    if ( second == INT_MIN)
        printf("No Second Largest");
    else
        printf("Second Largest: %d\n", second);
}

int main()
{
    int arr[] = {23, 5, 45, 47,47,47, 66, 11, 33};
    //int arr[] = {1,1,1,1,1,1};
    int n = sizeof(arr)/sizeof(arr[0]);
    print2Largest(arr, n);
    return 0;
}
