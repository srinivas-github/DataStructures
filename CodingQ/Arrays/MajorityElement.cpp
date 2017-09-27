/**
 * Majority Element: A majority element in an array A[] of size n is an element 
 * that appears more than n/2 times.
 *
 * Using Moore.s Voting Algorithm
 * Step 1:
 *  The first step gives the element that may be majority element in the array.
 * Step 2:
 *  Check if the element obtained from above step is majority element
 * Example: [2, 2, 3, 5, 2, 2, 6]
 * 1.Initialize:
 *  maj_index = 0, count = 1 -> candidate -> 2?
 *  2, 2, 3, 5, 2, 2, 6
 *  Same as a[maj_index] => count = 2
 *  2, 2, 3, 5, 2, 2, 6
 *  Different from a[maj_index] => count = 1
 *  2, 2, 3, 5, 2, 2, 6
 *  Different from a[maj_index] => count = 0
 *  Since count = 0, change candidate for majority element to 5 => maj_index = 3, count = 1
 *  2, 2, 3, 5, 2, 2, 6
 *  Different from a[maj_index] => count = 0
 *  Since count = 0, change candidate for majority element to 2 => maj_index = 4
 *  2, 2, 3, 5, 2, 2, 6
 *  Same as a[maj_index] => count = 2
 *  2, 2, 3, 5, 2, 2, 6
 *  Different from a[maj_index] => count = 1
 *  Finally candidate for majority element is 2.
 *
 * 2.Check if the element obtained in step 1 is majority  
 * 
 */

#include <iostream>
using namespace std;

int findMajority(int a[], int size)
{
    int maj_index = 0, count =1;
    int i;
    for (i = 1; i < size; i++)
    {
        if (a[maj_index] == a[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            maj_index = i;
            count = 1;
        }
    }
    return a[maj_index];
}

bool isMajority(int a[], int sz, int cand)
{
    int i, count = 0;
    for (i = 0; i< sz; i++)
        if (a[i] == cand)
            count++;
    if (count > sz/2)
        return 1;
    else 
        return 0;
}

void printMajority(int a[], int sz)
{
    int cand = findMajority(a, sz);
    if (isMajority(a, sz, cand))
        std::cout<<"Majority ele: "<<cand<<"\n";
    else
        std::cout<<"No Majority Element"<<"\n";
     
}

int main()
{
    int arr[] = {3,3,4,2,4,4,2,4,4};
    int sz = sizeof(arr)/sizeof(arr[0]);
    printMajority(arr, sz);
    return 0;
}
