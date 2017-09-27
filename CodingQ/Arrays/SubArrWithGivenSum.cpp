/**
 * Given an unsorted array of nonnegative integers, find a continous subarray 
 * which adds to a given number.
 * Examples:
 * 
 * Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
 * Ouptut: Sum found between indexes 2 and 4
 *
 * Input: arr[] = {1, 4, 0, 0, 3, 10, 5}, sum = 7
 * Ouptut: Sum found between indexes 1 and 4
 *
 * Input: arr[] = {1, 4}, sum = 0
 * Output: No subarray found
 */
#include <stdio.h>
void subArrWithSum(int arr[], int n, int sum)
{
    int cur_sum = 0;
    int i, j;
    for (i = 0; i <=n; i++)
    {
        cur_sum = arr[i];
        for (j = i+1; j<=n; j++)
        {
            if (cur_sum == sum)
            {
                printf("Found at %d to %d\n", i, j-1);
                return ;
            }
            if (cur_sum > sum || j == n)
                break;

            cur_sum += arr[j];
        }
    }
}

int main()
{
    int arr[] = {14, 8, 3, 12, 10, 13};
    int sz = sizeof(arr)/sizeof(arr[0]);
    subArrWithSum(arr, sz, 33);
    return 0;
}
