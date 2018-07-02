#include <stdio.h>

int fiboV1(int n)
{
	if ( n <= 1)
		return n;
	return fiboV1(n-1) + fiboV1(n-2);
}

int fiboV2(int n)
{
	int f[n+2];
	
	f[0] = 0;
	f[1] = 1;
	
	for (int i = 2; i <=n; i++)
		f[i] = f[i-1] + f[i-2];

	return f[n];
}

void printFiboUptoN(int n)
{
	int f1 =0, f2 = 1;
	if ( n  < 1)
		return ;
	
	for (int i = 1; i <= n; i++)
	{
		printf("%d ", f2);
		int next = f1 + f2;
		f1 = f2;
		f2 = next;
	}
}

int  main()
{
	int n = 7;
	printf("fiboV1: %d\n", fiboV1(n));
	printf("fiboV2: %d\n", fiboV2(n));
	
	printf("Fibo series upto n:%d\n", n);
	printFiboUptoN(n);
	return 0;
}
