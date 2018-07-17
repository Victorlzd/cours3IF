#include <stdio.h>

int main()
{
	int n;
	int fact = 1;
	int i;
	scanf("%d", &n);
	
	for (i = 2; i <= n; ++i)
	{
		fact *= i;
	}
	
	printf("%d\r\n", fact);
	
	return 0;
}