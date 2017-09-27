#include <cstdio>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
} 

void selectionSort(int A[], int n)
{
    int i, j, min_idx;

    for (i =0; i < n-1; i++)
    {
        min_idx = i;
        for(j = i+1; j < n; j++)
            if (A[j] < A[min_idx])
                min_idx = j;
        swap(&A[min_idx], &A[i]);
    }
}

int main()
{
    int A[] = {13, 33, 4, 56, 7, 88, 19, 23, 12, 1};
    int n = sizeof(A)/sizeof(A[0]);
    selectionSort(A, n);
    for(int i = 0; i < n; i++)
        printf("%d ", A[i]);
    return 0;
}
