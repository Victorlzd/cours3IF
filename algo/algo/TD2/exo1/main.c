#include <stdio.h>
#include<math.h>
#include <stdlib.h>

int main()
{
	int x[100];
	int y[100];
	int A,B, n=0, i;
	scanf("%d", &A);
	scanf("%d", &B);
	
	for (i = 0; i < sqrt(A); ++i)
	{
		double test = sqrt(A-i*i);
		int j = (int) test;
		if(test == j)
		{
			
			int i3 = i*i*i;
			int j3 = j*j*j;
			if(i3 + j3 == B)
			{
				x[n] = i;
				y[n] = j;
				n++;
				if(i==j)
				{
					x[n] = i;
					y[n] = j;
					n++;
				}
			}
			else if (i3 - j3 == B)
			{
				x[n] = i;
				y[n] = -j;
				n++;
			}
			else if (-i3 + j3 == B)
			{
				x[n] = -i;
				y[n] = j;
				n++;
			}
		}
	}
	
	if(n==0)
	{
		printf("-\r\n");
	}
	int k;
	for (k = 0; k < n; ++k)
	{
		printf("%d %d\r\n", x[k], y[k]);
	}
	
	
	/*for (int k = n-1; k >= 0; --k)
	{
		printf("%d %d\r\n", y[k], x[k]);
	}*/
	
	return 0;
}