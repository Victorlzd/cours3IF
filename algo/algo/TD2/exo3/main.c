#include <stdio.h>

int max(int a, int b, int c)
{
	int d = (a > b) ? a:b;
	return (d > c) ? d:c;
}

int sacADos(int poidsTotal, const int poids[], int taillePoids)
{
	int i;
	if(poidsTotal==0)
	{
		return 1;
	} else if (poidsTotal < 0 || taillePoids == 0)
	{
		return 0;
	}
	else
	{
		int poidsAct = poids[taillePoids-1];
		return max(sacADos(poidsTotal-poidsAct, poids, taillePoids),
		           sacADos(poidsTotal-poidsAct, poids, taillePoids-1),
                   sacADos(poidsTotal, poids, taillePoids-1));
	}
}

int main()
{
	int poidsTotal;
	int poids[100];
	int courant;
	int i=0;
	
	scanf("%d", &poidsTotal);
	scanf("%d", &courant);
	
	while (courant != -1)
	{
		poids[i] = courant;
		i++;
		scanf("%d", &courant);
	}
	
	int test =sacADos(poidsTotal, poids, i);
	
	if(test == 1)
	{
		printf("OUI\r\n");
	} else	{
		printf("NON\r\n");
	}
	return 0;
}