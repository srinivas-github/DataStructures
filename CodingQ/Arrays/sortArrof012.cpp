#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
    int temp =*a;
    *a = *b;
    *b = temp;
}

void printArr(int arr[], int sz)
{
   for(int i = 0; i < sz; i++)
       std::cout<<arr[i]<<" ";
   std::cout<<"\n";
}

void sort012(int arr[], int sz)
{
    int lo = 0;
    int hi = sz-1;
    int mid = 0;

    while (mid <= hi)
    {
        switch(arr[mid])
        {
            case 0:
                swap(&arr[lo++], &arr[mid++]);
                break;
            case 1:
                mid++;
                break;
            case 2:
                swap(&arr[mid], &arr[hi--]);
                break;
        }
    }
}

int main()
{
    int arr[] = {2,2,2,1,1,1,0,0,2,1,1,0,0,2,1,0,0,1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    sort012(arr, sz);
    printArr(arr, sz);
    return 0;
}
