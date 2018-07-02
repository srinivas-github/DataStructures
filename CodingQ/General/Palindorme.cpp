#include <stdio.h>
#include <string.h>

bool isPalindrome(char str[])
{
	int len = strlen(str);
	int l = 0, r = len-1;
	
	while ( r > l)
	{
		if ( str[l++] != str[r--])
			return false;
		
	}
	return true;
}

int main()
{
	char str[] = "madam";
	if (isPalindrome(str))
		printf("Yes\n");
    else
		printf("No\n");
	return 0;
}
