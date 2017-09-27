/**
 * Leaders in Array:
 * An element is leader if it is greater than all the elements to its right side. 
 * And the rightmost element is always a leader. 
 * Example: [16, 17, 4, 3, 5, 2], leaders are 17, 5 and 2.
 */
#include <iostream>
using namespace std;


/** Method 1:(simple)
 *   Use two loops.
 *   The outer loop runs from 0 to size-1 and one by one picks all elements from left to right.
 *   The inner loop compares the picked element to all the elements to its right side.
 *   If the picked element is greater than all the elements to its right side, then the picked element is the leader.
 */
void printLeaders1(int arr[], int sz)
{
    for (int i = 0; i < sz; i++)
    {
        int j;
        for (j = i+1; j < sz; j++)
        {
            if (arr[i] <= arr[j])
                break;
        }
        if (j == sz)
            std::cout<<arr[i]<<" ";
    }
}

/**
 * Method 2 (Scan from right):
 * Scan all the elements from right to left in array and keep track of maximum till now.
 * When maximum changes it's value, print it.
 */
void printLeaders2(int arr[], int sz)
{
    int max_from_right = arr[sz-1];
    std::cout<<max_from_right<<" ";
    for (int i = sz-2; i>=0; i--)
    {
        if (max_from_right < arr[i])
        {
            max_from_right = arr[i];
            std::cout<<max_from_right<<" ";
        }
    }
}


int main()
{
    int arr[] = {16,17,4,3,5,2};
    int sz = sizeof(arr)/sizeof(arr[0]);
    //printLeaders1(arr, sz);
    printLeaders2(arr, sz);
    return 0;
}
