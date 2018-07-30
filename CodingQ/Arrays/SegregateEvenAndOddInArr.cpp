#include <cstdio>
#include <cstdlib>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void segregateEvenAndOdd(int arr[], int n)
{
    int left = 0;
    int right = n-1;
    
    while (left < right)
    {
        while (arr[left]%2 == 1 && left < right)
            left++;
        while (arr[right]%2 == 0 && left < right)
            right--;
        if (left < right)
        {
            swap(&arr[left], &arr[right]);
            left++;
            right--;
        }
    }
}

int main()
{
    int arr[] = {13, 12, 4, 3, 5, 7, 8, 14, 15, 16};
    int n = sizeof(arr)/sizeof(arr[0]);
    segregateEvenAndOdd(arr, n);
    for(int i = 0 ; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
