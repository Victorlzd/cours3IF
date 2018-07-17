//------- Interface de la classe <Catalogue> (fichier Catalogue.h) ------------
#ifndef CATALOGUE_H
#define CATALOGUE_H

//-------------------------------------------------------- Interfaces utilisées
#include "Collection.h"

//------------------------------------------------------------------ Constantes


//------------------------------------------------------------------- Fonctions


// Effectue les operations recursives necessaires a la recherche avancee

//----------------------------------------------------------------------- Types


//-----------------------------------------------------------------------------
// Rôle de la classe <Catalogue>
// La classe Catalogue symbolise un ensemble de trajet, dans lequel on peut
// rechercher l’ensemble des trajets permettant d’aller d’une ville A à une
// ville B (avec ou sans combinaison de trajet).
//-----------------------------------------------------------------------------

class Catalogue
{
    //------------------------------------------------------------------ PUBLIC
    public :
    //------------------------------------------------------ Méthodes publiques
    void Ajouter(Trajet * unTrajet);
    // Permet d'ajouter un trajet au catalogue
    
    void Afficher() const;
    // Permet d'afficher les informations liées au catalogue
    
    Collection RechercheSimple(const char* depart, const char* arrivee) const;
    // Renvoie les trajets allant de depart à arrivee dans une collection
    
    Collection RechercheAvancee(const char* depart, const char* arrivee) const;
    // Renvoie les combinaisons de trajets allant de depart à arrivee dans une
    // collection sans reutiliser 2 fois le même trajet

    

    //--------------------------------------------- Constructeurs - Destructeur
    Catalogue();
    // Constructeur par défaut de la classe
    
    virtual ~Catalogue();
    // Destructeur de la classe
    
    //------------------------------------------------------------------- PRIVE
    protected:
    void Recursion(const char* depart, const char* arrivee,
                   Collection TrajetsEmpruntes, Collection & result) const;
    //------------------------------------------------------- Attributes protégé
    Collection collection;

};

//-------------------------------- Autres définitions dépendantes de <Catalogue>


#endif // ! defined ( CATALOGUE_H )
