#include <iostream>
#include <cstring>

void sieveOfEratosthenes(int n)
{
    bool primes[n+1];
    memset(primes, true, sizeof(primes));

    for (int p = 2; p*p <= n; p++)
    {
        if (primes[p] == true)
        {
           for (int i = p*2; i<= n; i += p)
           {
               primes[i] = false;
           }
        }
    }
    for (int i = 2; i <= n; i++)
       if (primes[i])
           std::cout<<i<<"  ";
}

int main()
{
    int n = 30;
    sieveOfEratosthenes(n);
    return 0;
}
