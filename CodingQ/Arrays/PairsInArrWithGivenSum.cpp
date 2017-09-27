#include <cstdio>
#include <cstdlib>
using namespace std;
#define MAX 100
void printPairs(int arr[], int n, int x)
{
    int i, temp;
    int binMap[MAX] = {0};
    for(i = 0; i <=n; i++)
    {
        temp = x - arr[i];
        if (temp >= 0 && binMap[temp] == 1)
            printf("Pair: (%d, %d): (%d)", temp, arr[i], x);
        binMap[arr[i]] = 1;
    }
}

int main()
{
    int arr[] = {2, 4, 6, 8, 10, 12};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 14;
    printPairs(arr, n,x);
    return 0;
}
