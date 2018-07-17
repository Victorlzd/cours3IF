#include <stdio.h>

int sacADos(int poidsTotal, int poids[], int nPoids)
{
	int tab[10000][100];
	int i,j;
	
	/*for (j = 0; j <= poidsTotal; ++j)
	{
		for (i = 0; i <= nPoids; ++i)
		{
			tab[j][i] = 0;
		}
	}*/
	
	for (i = 0; i <= nPoids; ++i)
	{
		tab[0][i] = 1;
	}
	for (i = 1; i <= poidsTotal; ++i)
	{
		tab[i][0] = 0;
	}
	
	for (j = 1; j <= poidsTotal; ++j)
	{
		for (i = 1; i <= nPoids; ++i)
		{
			if(j-poids[i-1] < 0)
			{
				tab[j][i] = tab[j][i-1];
			}
			else
			{
				tab[j][i] = (tab[j][i-1] > tab[j-poids[i-1]][i-1]) ? tab[j][i-1] : tab[j-poids[i-1]][i-1];
			}
		}
	}
	
	/*printf("\r\n\r\n");
	for (j = 0; j <= poidsTotal; ++j)
	{
		for (i = 0; i <= nPoids; ++i)
		{
			printf("%d ", tab[j][i]);
		}
		printf("  <= %d\r\n", j);
	}
	printf("\r\n\r\n");*/
	
	return tab[poidsTotal][nPoids];
}


int main()
{
	int total;
	int poids[100];
	int courant;
	int test;
	int i = 0;
	
	scanf("%d", &total);
	scanf("%d", &courant);
	
	while (courant != -1)
	{
		poids[i] = courant;
		i++;
		scanf("%d", &courant);
	}
	
	test = sacADos(total, poids, i);
	if (test)
	{
		printf("OUI\r\n");
	} else
	{
		printf("NON\r\n");
	}
	return 0;
}
