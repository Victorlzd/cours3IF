#include "pile.h"
#include "malloc.h"

Pile *initPile()
{
	Pile *pile = malloc(sizeof(Pile));
	pile->premier = NULL;
	
	printf("==============> Création Pile\n");
	return pile;
}

void empiler(Pile *pile, int valeur)
{
	EltPile *nouveau = malloc(sizeof(EltPile));
	
	nouveau->valeur = valeur;
	
	if (pile->premier != NULL)
	{
		nouveau->suivant = pile->premier;
	} else
	{
		nouveau->suivant = NULL;
	}
	
	pile->premier = nouveau;
	printf("==============> Création Element Pile\n");
}

int depiler(Pile *pile, int *valeurRetour)
{
	if (pile->premier != NULL)
	{
		EltPile *suppr = pile->premier;
		*valeurRetour = suppr->valeur;
		
		pile->premier = pile->premier->suivant;
		free(suppr);
		printf("==============> Destruction Element Pile\n");
		
		return 1;
	} else
	{
		return 0;
	}
}

void destroyPile(Pile *pile)
{
	while(pile->premier != NULL)
	{
		int x;
		depiler(pile, &x);
	}
	free(pile);
	printf("==============> Destruction Pile\n");
}