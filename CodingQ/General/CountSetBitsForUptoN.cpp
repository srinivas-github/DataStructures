#include <cstdio>
#include <cstdlib>

int doCountSetBits(int x)
{
    if ( x <= 0)
        return 0;
    return ( x%2 == 0 ? 0:1) + doCountSetBits(x/2); 
}

int countSetBits(int n)
{
    int bitCnt = 0;
    for (int i = 1; i <= n; i++)
    {
        bitCnt += doCountSetBits(i);
    }
    return bitCnt;
}

int main()
{
    int n = 4;
    printf("Number of set bit count: %d\n", countSetBits(n));
    return 0;
}
