#include <cstdio>
using namespace std;

int main()
{
    char arr[3] = {'a', 'b', 'c'};
    for (int i = 0; i < 3; i++)
        for(int j = 0; j<3; j++)
            for(int k = 0; k < 3; k++)
                if (i!=j && j!=k && i!=k)
                    printf("%c%c%c\n", arr[i], arr[j], arr[k]);
    return 0;
}
