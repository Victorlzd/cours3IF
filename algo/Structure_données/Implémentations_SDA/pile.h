#ifndef PILE_PILE_H
#define PILE_PILE_H

typedef struct EltPile{
	int valeur;
	struct EltPile* suivant;
}EltPile;

typedef struct {
	EltPile* premier;
}Pile;

Pile* initPile();
void empiler(Pile* pile, int valeur);
int depiler(Pile* pile, int* valeurRetour);
void destroyPile(Pile *pile);

#endif //PILE_PILE_H
