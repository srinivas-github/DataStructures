#include <bits/stdc++.h>
using namespace std;
const int MAX_CHARS = 26;

void sortName(string& str)
{
    int charCount[MAX_CHARS] = {0};
    
    for (int i = 0; i < str.length(); i++)
        charCount[str[i]-'a']++;
    for (int i = 0; i < MAX_CHARS; i++)
        for (int j = 0; j < charCount[i]; j++)
            cout<<(char)('a' + i);
}
int main()
{
    string str = "jillalasrinivasreddy";
    sortName(str);
    return 0;
}
