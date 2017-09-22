#include <cstdio>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r-l)/2;
        if (arr[mid] == x)
            return mid;
        if (arr[mid] > x)
            return binarySearch(arr, l, mid-1, x);
        return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}

int finPos(int arr[], int key)
{
    int l = 0, h =1;
    int val = arr[0];

    while ( val < key)
    {
        l = h;
        h = 2*h;
        val = arr[h];
    }
    return binarySearch(arr, l, h, key);
}

int main()
{
    int arr[] = {3,5,7,9,10,13,15,19, 23, 25, 45, 56, 67, 78, 99, 101, 112};
    int key = 25;
    printf("The index is at: %d\n", finPos(arr, key));
    return 0;
}
