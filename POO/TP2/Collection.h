//------- Interface de la classe <Collection> (fichier Collection.h) ----------
#ifndef COLLECTION_H
#define COLLECTION_H

//-------------------------------------------------------- Interfaces utilisées
#include "Trajet.h"

//-----------------------------------------------------------------------------
// Rôle de la classe <Collection>
// La classe collection contient une liste ordonnées de Trajet*. Ici nous
// l’implémentons avec un tableau dynamique.
//-----------------------------------------------------------------------------

class Collection
{
    //------------------------------------------------------------------ PUBLIC
    public :
    
    //------------------------------------------------------ Méthodes publiques
    void Ajouter(Trajet* trajet);
    // Ajoute le trajet pointé par le paramètre à la collection

    void Ajouter(const Collection &collection);
    // Ajoute la collection passee en parametre a la collection courante
    
    Trajet* GetTrajet(unsigned int index) const;
    // Renvoie un pointeur vers le trajet contenu à la place index de la
    // collection, renvoie nullptr si index<0 ou index>tailleAct
    
    Trajet* GetLastTrajet() const;
    // Renvoie un pointeur vers le dernier trajet
    
    void Afficher() const;
    // Affiche la liste des trajets présents dans la collection

    void AfficherAvance(const char * arrivee) const;
    // Permet d'afficher le resultat de la recherche avancee
    
    bool EstVide() const;
    // Renvoie true si le catalogue est vide

    bool EstDansLaCollection(const char* depart, const char* arrivee) const;
    // Renvoie true si il existe un trajet allant de depart a arrivee dans
    // la collection
    
    unsigned int GetTailleActuelle() const;
    // Renvoie la taille actuelle de la collection
    
    //--------------------------------------------- Constructeurs - Destructeur
    Collection(unsigned int taille=1);
    // Initialise la collection avec taille case allouées pour le tableau.
    
    Collection(const Collection & copie);
    // Constructeur de copie de la classe
    
    virtual ~Collection();
    // Destructeur de la classe
    
    //------------------------------------------------------------------- PRIVE
    protected:
    //------------------------------------------------------- Méthodes protégées
    void allouer(unsigned int delta);
    // Alloue delta nouvelle cases en mémoire
    
    //------------------------------------------------------- Attributs protégés
    Trajet** trajets;
    unsigned int tailleMax;
    unsigned int tailleAct;
    
};

//------------------------------- Autres définitions dépendantes de <Collection>


#endif // ! defined ( COLLECTION_H )
