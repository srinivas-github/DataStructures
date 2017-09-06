/**
 * Given a sorted array in which all elements appear twice (one after one) and 
 * one element appears only once. Find that element in O(log n) complexity.
 *
 * Example:
 * arr[] = {1,1,3,3,4,5,5,6,6};
 * o/p: 4
 *
 * arr[] = {1,1,2,2,3,3,4,4,5,5,6};
 * o/p: 6
 * Use Binary Search (sort of)
 */

#include <cstdio>
using namespace std;

void search(int arr[], int low, int high)
{
   if(low > high)
        return ;
   if (low ==high)
   {
       printf("Required Element: %d\n", arr[low]);
       return ;
   }

   int mid = (low+high)/2;
   if (mid % 2 == 0)
   {
       if (arr[mid] == arr[mid+1])
           search(arr, mid+2, high);
       else
           search(arr, low, mid);
   }
   else
   {
       if (arr[mid] == arr[mid-1])
           search(arr, mid-2, high);
       else
           search(arr, low, mid-1);
   }
    
}


int main()
{
    int arr[] = {1,1,2,3,3,4,4,5,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    search(arr, 0, len-1);
    return 0;
}

 
