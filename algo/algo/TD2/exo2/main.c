#include <stdio.h>

int main()
{
	int n;
	int n50, n20, n10, n5, n1;
	
	scanf("%d", &n);
	
	n50 = n/50;
	n = n%50;
	n20 = n/20;
	n = n%20;
	n10 = n/10;
	n = n%10;
	n5 = n/5;
	n = n%5;
	
	printf("%d\r\n", n50);
	printf("%d\r\n", n20);
	printf("%d\r\n", n10);
	printf("%d\r\n", n5);
	printf("%d\r\n", n);
	return 0;
}