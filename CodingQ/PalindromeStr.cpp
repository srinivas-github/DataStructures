#include <iostream>
#include <cstring>

using namespace std;

void isPalindrome(char str[])
{
    int low = 0;
    int high = strlen(str)-1;
    while (high > low)
    {
        if (str[low++] != str[high--])
        {
            std::cout<<" Not Palindrome"<<"\n";
            return ;
        }
    }
    std::cout<<"Palindrome"<<"\n";
}

int main()
{
    isPalindrome("abba");
    isPalindrome("madam");
    isPalindrome("something");
    return 0;
}
