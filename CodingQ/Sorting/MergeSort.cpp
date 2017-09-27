#include <cstdio>
#include <cstdlib>

using namespace std;
void Merge(int* A, int *L, int leftCnt, int* R, int rightCnt)
{
    int i, j, k;
    i=j=k=0;

    while ( i < leftCnt && j < rightCnt)
    {
        if (L[i] < R[j])
            A[k++] = L[i++];
        else
            A[k++] = R[j++];
    }

    while (i < leftCnt)
        A[k++] = L[i++];
   while (j < rightCnt)
       A[k++] = R[j++];

}
void MergeSort(int arr[], int n)
{
    int i, mid;
    int *L, *R;
    if (n < 2 )
        return ;

    mid = n/2;
    L = (int*)malloc( mid * sizeof(int));
    R = (int*)malloc( (n-mid) * sizeof(int));

    for (i =0; i < mid; i++)
        L[i] = arr[i];

    for(i = mid; i < n; i++)
        R[i-mid] = arr[i];

    MergeSort(L, mid);
    MergeSort(R, n-mid);

    Merge(arr, L, mid, R, n-mid);

}
int main()
{
    int arr[] = { 33, 14, 13, 21, 1, 5, 66, 7, 9, 88};
    int n = sizeof(arr)/sizeof(arr[0]);
    MergeSort(arr, n);
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
