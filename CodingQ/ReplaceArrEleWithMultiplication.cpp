/**
 * Example:
 * Input: arr[] = {2, 3, 4, 5, 6}
 * Output: arr[] = {6, 8, 15, 24, 30}
 *
 * We get the above output using following
 * arr[] = {2*3, 2*4, 3*5, 4*6, 5*6} 
 */
#include <cstdio>
void modifyArr(int arr[], int n)
{
   if (n <= 1)
       return ;
   int prev = arr[0];
   arr[0] = arr[0]*arr[1];
   for(int i = 1; i < n-1; i++)
   {
       int curr = arr[i];
       arr[i] = prev * arr[i+1];
       prev = curr;
   }
   arr[n-1] = prev * arr[n-1];
 
}

int main()
{
    int arr[] = {2, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    modifyArr(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
