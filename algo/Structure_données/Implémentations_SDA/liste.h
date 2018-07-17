#ifndef PILE_LISTE_H
#define PILE_LISTE_H

typedef struct EltListe{
	int valeur;
	struct EltListe* suivant;
	struct EltListe* precedent;
}EltListe;

typedef struct Liste{
	EltListe* premier;
	EltListe* dernier;
	int taille;
}Liste;

Liste* initListe(void);
void insererAvant(Liste* liste, EltListe* position, int valeur);
void insererApres(Liste* liste, EltListe* position, int valeur);
void supprimer(Liste* liste, EltListe* position);
void remplacer(Liste* liste, EltListe* position, int valeur);
EltListe* suivant(Liste* liste, EltListe* position);
EltListe* precedent(Liste* liste, EltListe* position);
EltListe* get(Liste* liste, int position);
EltListe* premier(Liste* liste);
EltListe* dernier(Liste* liste);
void destroyListe(Liste* liste);
static void insererPremier(Liste* liste, int valeur);
EltListe* createEltListe(int valeur);
void destroyEltListe(EltListe* eltListe);
#endif //PILE_LISTE_H
