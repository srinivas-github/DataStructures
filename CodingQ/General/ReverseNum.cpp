#include <stdio.h>
#include <string.h>

int reverse(int n, int temp)
{
	if ( n == 0)
		return temp;
	temp = (temp * 10) + ( n % 10);
	return reverse( (n/10), temp);
}
int main()
{
	int n = 121;
	int temp = reverse(n, 0);
	if ( temp == n)
		printf("Yes\n");
	else
		printf("No\n");
	return 0;
}
