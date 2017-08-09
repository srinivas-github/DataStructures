#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool isAnagrams(std::string str1, std::string str2)
{
    int l1 = str1.length();
    int l2 = str2.length();
    if ( l1 != l2)
        return false;

    std::sort(str1.begin(), str1.end());
    std::sort(str2.begin(), str2.end());

    for (int i = 0; i < l1; i++)
    {
        if (str1[i] != str2[i])
            return false;
    }
    return true;
}

int main()
{
    std::string str1 = "listen";
    std::string str2 = "silentsds";
    isAnagrams(str1, str2) ? std::cout<<"Yes\n" : std::cout<<"No\n";
    return 0;
}
