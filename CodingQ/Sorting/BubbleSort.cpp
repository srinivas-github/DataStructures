#include <cstdio>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    int i, j;
    for( i = 0; i < n-1; i++)
        for(j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);
}

int main()
{
    int A[] = {34, 12, 43, 15, 67, 89, 4, 7, 8, 100};
    int n = sizeof(A)/sizeof(A[0]);
    bubbleSort(A, n);
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}
