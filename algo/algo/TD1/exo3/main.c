#include <stdio.h>

int main()
{
	int a1, b1, a2, b2;
	int inf, sup, aire;
	
	scanf("%d", &a1);
	scanf("%d", &b1);
	scanf("%d", &a2);
	scanf("%d", &b2);
	
	if(a1 > a2)
	{
		inf = a1;
	}
	else
	{
		inf = a2;
	}
	
	if(b1 > b2)
	{
		sup = b2;
	}
	else
	{
		sup = b1;
	}
	
	aire = sup-inf;
	
	if(sup-inf <= 0)
	{
		printf("0\r\n");
	}
	else
	{
		printf("%d\r\n", aire);
	}
	return 0;
}