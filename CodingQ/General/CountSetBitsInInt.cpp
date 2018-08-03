
#include <stdio.h>

unsigned int countSetBits(int x)
{
    int cnt = 0;
    while (x)
    {
        cnt += x & 1;
        x>>=1;
    }
    return cnt;
    
}

unsigned int countSetBits_v2(int x)
{
    if (x == 0)
        return 0;
    return ( x & 1) + countSetBits_v2(x>>1);
}

int main()
{
    int x = 7;
    printf("%d ", countSetBits(x));
    printf("%d ", countSetBits_v2(x));
    return 0;
}
