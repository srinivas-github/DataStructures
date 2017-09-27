#include <cstdio>
#include <cstdlib>
using namespace std;

void findCommon(int ar1[], int ar2[], int ar3[], int n1, int n2, int n3)
{
    int i,j,k;
    i=j=k=0;

    while ( i < n1 && j < n2 && k < n3)
    {
        if (ar1[i] == ar2[j] && ar2[j] == ar3[k])
        {
            printf("%d ", ar1[i++]);
            j++;
            k++;
        }
        else if (ar1[i] < ar2[j])
            i++;
        else if (ar2[j] < ar3[k])
            j++;
        else
            k++;
    }
}

int main()
{
    int ar1[] = {2, 5, 7, 9, 11, 15};
    int ar2[] = {5, 7, 17};
    int ar3[] = {2, 5, 7, 21, 23};
    int n1 = sizeof(ar1)/sizeof(ar1[0]);
    int n2 = sizeof(ar2)/sizeof(ar2[0]);
    int n3 = sizeof(ar3)/sizeof(ar3[0]);

    findCommon(ar1, ar2, ar3, n1, n2, n3);
    return 0;
}
