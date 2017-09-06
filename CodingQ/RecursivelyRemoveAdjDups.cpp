#include <iostream>
#include <cstring>
using namespace std;

char* removeDups(char* str, int n)
{
    int len = strlen(str);
    int k = 0;
    int i;
    for (i = 1; i < len; i++)
    {
        if (str[i-1] != str[i])
            str[k++] = str[i-1];
        else
            while (str[i-1] == str[i])
                i++;
    }
    str[k++] = str[i-1];
    str[k] = '\0';
    if (k != n)
        removeDups(str, k);
    else 
        return str;
}

int main()
{
    char str1[] = "azxxaxzy";
    std::cout<<removeDups(str1, strlen(str1))<<"\n";
    return 0;
}
