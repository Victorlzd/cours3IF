//
// Created by duazel on 31/10/17.
//

#include <stdio.h>

int min(int a, int b)
{
	return (a<b) ? a:b;
}

int max(int a, int b)
{
	return (a>b) ? a:b;
}

void resFiole(int C, const int fiole[], int nFiole, int result[])
{
	/* le but de la fonction est de donner les quantitées que l'on peut obtenir à partir des fioles
	 * du tableau fiole[]
	 *
	 * le réultat est un tableau qui associe 1 aux valeurs possibles par combinaison des fioles et
	 * 0 pour les autres valeurs
	 */
	
	/* On définit chaque cas comme équivalent à
	 * (cas avec une fiole en moins et même capaité OU cas avec une fiole en moins et capacité abaissé de la valeur de cette fiole)
	 * les cas ou il n'y a plus de fioles ou que la capacité est nulle sont évidents
	 *
	 * on range ces cas dans un tableau à double entrée (capacité/fioles) dans chaque case si on peut obtenir cette capacité par
	 * combinaison des fioles on met 1 sinon on met 0
	 */
	int tabFioleC[2500][20];
	//tableau ayant pour ligne les capacités de 0 à C et pour colonne le nombre de fiole restante de 0 à nFiole
	int i,j;
	
	for (i = 1; i <= C; ++i)
	{
		tabFioleC[i][0] = 0; // s'il n'y a plus de fioles et qu'on est pas à zéro on ne peut pas avoir cette capacité
	}
	
	for (i = 0; i <= nFiole; ++i)
	{
		tabFioleC[0][i] = 1; // Quel que soit le nombre de fiole on peut atteindre une capacité nulle
	}
	
	for (i = 1; i <= C; ++i)
	{
		for (j = 1; j <= nFiole; ++j)
		{
			int nonUtilFiole = tabFioleC[i][j-1];
			// si on utilise pas cette fiole cela équivaut au cas où on a la même capacité et une fiole en moins
			
			if(i-fiole[j-1] < 0)
			{
				tabFioleC[i][j] = nonUtilFiole;
			}
			else
			{
				int utilFiole = tabFioleC[ i-fiole[j-1] ][ j-1 ];
				//si on utilise la fiole cela équivaut au cas avec cette fiole en moins et on abaisse la capacité de la valeur de la fiole
				
				tabFioleC[i][j] = max(utilFiole, nonUtilFiole);
			}
		}
	}
	
	//on ne récupère que la dernière colonne pour obtenir le tableau de ce qu'on peut avoir avec l'ensemble des fioles
	for (i = 0; i <= C; i++)
	{
		result[i] = tabFioleC[i][nFiole];
	}
	
}


int maxMelange(const int fiole1[], const int fiole2[], int C)
{
	/* Cette fonciton récupère ce que l'on peut faire avec chacun des ensembles de fioles
	 * et renvoie la quantité max de solution rouge que l'on peut obtenir
	 */
	
	// on teste tous les mélanges que l'on peut faire avec ces fioles et on garde le max
	
	int max=0;
	int qteS1,qteS2;
	
	for (qteS1 = 1; qteS1 < C; ++qteS1)
	{
		if(fiole1[qteS1] == 1)
		{
			for (qteS2 = 1; qteS2 <= C - qteS1; ++qteS2)
			{
				if(fiole2[qteS2] == 1)
				{
					if (2 * min(qteS1,qteS2) > max)
					{
						max = 2 * min(qteS1,qteS2);
					}
				}
			}
		}
	}
	
	return max;
}




int main(){
	int C;
	int fiole1[20], fiole2[20];
	int resultFiole1[2500], resultFiole2[2500];
	int nFiole1=0, nFiole2=0;
	int courant, type, nFioleTotal, i;
	
	
	scanf("%d", &C);
	scanf("%d", &nFioleTotal);
	
	for (i = 0; i < nFioleTotal; ++i)
	{
		scanf("%d %d", &courant, &type);
		
		if(type == 1)
		{
			fiole1[nFiole1] = courant;
			nFiole1++;
		}
		else
		{
			fiole2[nFiole2] = courant;
			nFiole2++;
		}
	}
	
	resFiole(C, fiole1, nFiole1, resultFiole1);
	resFiole(C, fiole2, nFiole2, resultFiole2);
	
	
	printf("%d\r\n", maxMelange(resultFiole1, resultFiole2, C));
	
	return 0;
}