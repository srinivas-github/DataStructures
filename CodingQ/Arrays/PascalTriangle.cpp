#include <stdio.h>
void printPascalTriangle(int n)
{
    int arr[n][n];
    
    for (int line = 0; line < n; line++)
    {
        for (int i = 0; i <=line; i++)
        {
            if (line == i || i == 0)
                arr[line][i] = 1;
            else
                arr[line][i] = arr[line-1][i-1] + arr[line-1][i];
            printf("%d ", arr[line][i]);
        }
        printf("\n");
    }
}

int main()
{
    int n = 7;
    printPascalTriangle(n);
    return 0;
}
