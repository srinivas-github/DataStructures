#include <iostream>
#include <climits>
using namespace std;

int maximumSubArr(int arr[], int sz)
{
    int max_so_far = INT_MIN;
    int max_ending_here = 0;
    for (int i = 0; i < sz; i++)
    {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;

        if (max_ending_here < 0 )
            max_ending_here = 0;
    }
    return max_so_far;
}

int main()
{
    int arr[] = {-2, -3, 4, -1,-2, 1, 5, -3};
    int sum = maximumSubArr(arr, sizeof(arr)/sizeof(arr[0]));
    std::cout<<"Max SubArr: "<<sum<<"\n";
    return 0; 
}
