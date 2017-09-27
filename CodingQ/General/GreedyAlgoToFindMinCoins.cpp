#include <cstdio>
#include <vector>

using namespace std;

void findCoins(int V)
{
    int deno[] = {1,2,5,10,20,50,100,200,500,2000};
    int n = sizeof(deno)/sizeof(deno[0]);
    std::vector<int> ans;
    for(int i = n-1; i >= 0; i--)
    {
        while (V >= deno[i])
        {
            V -= deno[i];
            ans.push_back(deno[i]);            
        }
    }
    for (int i = 0; i < ans.size(); i++)
        printf("%d ", ans[i]);
}

int main()
{
    int n = 2093;
    findCoins(n);
    return 0;
}
