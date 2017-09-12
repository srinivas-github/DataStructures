#include <cstdio>
#include <cstdlib>
using namespace std;

void UnionOf2Arr(int arr1[], int arr2[], int n1, int n2)
{
    int i = 0, j = 0;
    while ( i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
        {
            printf("%d ", arr1[i++]);
        }
        else if (arr2[j] < arr1[i])
        {
            printf("%d ", arr2[j++]);
        }
        else
        {
            printf("%d ", arr2[j++]);
            i++;
        }
    }
    while ( i < n1)
        printf("%d ", arr1[i++]);
    while ( j < n2)
        printf("%d ", arr2[j++]);
}

void Intersection(int arr1[], int arr2[], int n1, int n2)
{
    int i = 0, j = 0;
    while ( i < n1 && j < n2)
    {
        if (arr1[i] < arr2[j])
            i++;
        else if (arr2[j] < arr1[i])
            j++;
        else
        {
            printf("%d ", arr2[j++]);
            i++;
        }
    }
}

int main()
{
    int arr1[] = {1,2,3,4,5,7,9,11};
    int arr2[] = {2,4,6,8};
    int n1 = sizeof(arr1)/sizeof(arr1[0]);
    int n2 = sizeof(arr2)/sizeof(arr2[0]);
    UnionOf2Arr(arr1, arr2, n1, n2);
    printf("\n");

    Intersection(arr1, arr2, n1, n2);
    return 0;
}
