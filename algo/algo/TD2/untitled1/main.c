#include <stdio.h>
#include <string.h>

void pb1()
{
	float s = 0;
	int compteur = 0;
	float courant;
	int n,i;
	
	scanf("%d", &n);
	
	for (i = 0; i < n; ++i)
	{
		scanf("%f", &courant);
		if(courant <= 0)
		{
			s+=courant;
			compteur++;
		}
	}
	
	if(compteur == 0)
	{
		printf("-\r\n");
	}
	else
	{
		printf("%f\r\n",s/compteur);
	}
}

int estDansLaListe(char mot[4], char liste[][4], int taille)
{
	int index=-1;
	int i;
	for (i=0;i<taille; i++)
	{
		if(strcmp(mot, liste[i])==0)
		{
			index = i;
			break;
		}
	}
	return index;
}

void pb2()
{
	char liste[100][4];
	int occ[100];
	int tailleListe,n,i=0;
	char chaine[100];
	
	scanf("%s", chaine);
	while()
}
int main()
{
	pb1();
	return 0;
}