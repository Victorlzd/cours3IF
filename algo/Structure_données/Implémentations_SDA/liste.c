//
// Created by duazel on 29/10/17.
//
#include <malloc.h>
#include "liste.h"

Liste* initListe(void)
{
	Liste* liste = malloc(sizeof(Liste));
	liste->premier = NULL;
	liste->dernier = NULL;
	liste->taille = 0;
	printf("======>CREATION LISTE\n");
	
	return liste;
}

EltListe* createEltListe(int valeur)
{
	EltListe* eltListe = malloc(sizeof(EltListe));
	eltListe->precedent = NULL;
	eltListe->suivant = NULL;
	eltListe->valeur = valeur;
	
	printf("======>CREATION ELT LISTE\n");
	return eltListe;
}

void destroyEltListe(EltListe *eltListe)
{
	free(eltListe);
	printf("======>DESTRUCTION ELT LISTE\n");
}

EltListe *premier(Liste *liste)
{
	return liste->premier;
}

EltListe *dernier(Liste *liste)
{
	return liste->dernier;
}

void destroyListe(Liste *liste)
{
	while(premier(liste) != dernier(liste))
	{
		destroyEltListe(suivant(liste, premier(liste)));
	}
	destroyEltListe(premier(liste));
	free(liste);
	printf("======>DESTRUCTION ELT LISTE\n");
}

EltListe *suivant(Liste *liste, EltListe *position)
{
	if (position == NULL)
	{
		return NULL;
	} else
	{
		return position->suivant;
	}
}

EltListe *precedent(Liste *liste, EltListe *position)
{
	if(position == NULL)
	{
		return  NULL;
	}
	else
	{
		return position->precedent;
	}
}

void insererAvant(Liste *liste, EltListe *position, int valeur)
{
	if (position == NULL)
	{
		insererPremier(liste, valeur);
	} else
	{
		EltListe *eltListe = createEltListe(valeur);
		
		eltListe->precedent = position->precedent;
		
		if (eltListe->precedent == NULL)
		{
			liste->premier = eltListe;
		} else
		{
			eltListe->precedent->suivant = eltListe;
		}
		
		position->precedent = eltListe;
		eltListe->suivant = position;
		
		liste->taille += 1;
	}
}

void insererApres(Liste *liste, EltListe *position, int valeur)
{
	if (position == NULL)
	{
		insererPremier(liste, valeur);
	} else
	{
		EltListe *eltListe = createEltListe(valeur);
		
		eltListe->suivant = position->suivant;
		
		if (eltListe->suivant == NULL)
		{
			liste->dernier = NULL;
		} else
		{
			eltListe->suivant->precedent = eltListe;
		}
		
		position->suivant = eltListe;
		eltListe->precedent = position;
		
		liste->taille += 1;
	}
}

void supprimer(Liste *liste, EltListe *position)
{
	if(position != NULL)
	{
		if (position->precedent == NULL)
		{
			liste->premier = position->suivant;
		} else
		{
			position->precedent->suivant = position->suivant;
		}
		
		if (position->suivant == NULL)
		{
			liste->dernier = position->precedent;
		} else
		{
			position->suivant->precedent = position->precedent;
		}
		
		destroyEltListe(position);
		liste->taille -= 1;
	}
}

void remplacer(Liste *liste, EltListe *position, int valeur)
{
	if(position != NULL)
	{
		position->valeur = valeur;
	}
}

EltListe* get(Liste *liste, int position)
{
	EltListe* current;
	
	if(position < liste->taille/2)
	{
		current = premier(liste);
		for (int i = 0; i < position; ++i)
		{
			current = suivant(liste, current);
		}
	}
	else
	{
		current = dernier(liste);
		for (int i = liste->taille; i > position; --i)
		{
			current = precedent(liste, current);
		}
	}
	
	return current;
}

static void insererPremier(Liste *liste, int valeur)
{
	EltListe* eltListe = createEltListe(valeur);
	liste->premier = eltListe;
	liste->dernier = eltListe;
}

