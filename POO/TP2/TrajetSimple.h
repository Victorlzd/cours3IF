//----- Interface de la classe <TrajetSimple.h> (fichier TrajetSimple.h) ------
#ifndef TRAJET_SIMPLE_H
#define TRAJET_SIMPLE_H

//-------------------------------------------------------- Interfaces utilisées
#include "Trajet.h"
//----------------------------------------------------------------------- Types
typedef enum {AUTO,AVION,BATEAU,TRAIN} MoyenTransport;
// L'enumeration recense les differents les moyen de transport utilisable pour
// les TrajetSimple

//-----------------------------------------------------------------------------
// Rôle de la classe <TrajetSimple>
// La classe TrajetSimple symbolise un trajet direct d'une ville depart a une
// ville arrivee a l'aide d'un moyen transport
// Un TrajetSimple est une sorte de Trajet
//-----------------------------------------------------------------------------

class TrajetSimple :public Trajet
{
    //------------------------------------------------------------------ PUBLIC
    public :
    //------------------------------------------------------ Méthodes publiques
    virtual char* GetDepart() const;
    // renvoie la valeur stockée dans l’attribut depart
    
    virtual char* GetArrivee() const;
    // renvoie la valeur stockée dans l’attribut arrivee
    
    virtual void Afficher() const;
    // permet d’afficher en console les informations liées à l’objet.
    // Les informations seront affichés ainsi :
    // TrajetSimple de <depart> à <arrivee>
    
    virtual Trajet* Copie() const;
    // Renvoie un pointeur sur une copie distincte de ce trajet
    // Contrat :
    // Le pointeur retourné pointe sur un objet alloué dynamiquement
    // IL DOIT ETRE LIBERE PAR UN delete !!!
    
    //--------------------------------------------- Constructeurs - Destructeur
    TrajetSimple(const char * villeDepart, const char * villeArrivee,
    MoyenTransport moyenTransport);
    // Constructeur de la classe
    
    TrajetSimple(const TrajetSimple & copie);
    // Constructeur de copie de la classe
    
    virtual ~TrajetSimple();
    // Destructeur de la classe
    
    //------------------------------------------------------------------- PRIVE
    protected:
    //------------------------------------------------------ Méthodes protégées
    TrajetSimple();
    // Constructeur par defaut de la classe
    
    //------------------------------------------------------ Attributes protégé
    char * depart;
    // ville de depart du Trajet
    
    char * arrivee;
    // ville d'arrivee du Trajet
    
    MoyenTransport vehicule;
    // moyen de transport utilise pendant le trajet
};

//---------------------------- Autres définitions dépendantes de <TrajetSimple>

void AfficherMT(MoyenTransport vehicule);
// Affiche le nom du moyen de transport

#endif // ! defined ( TRAJET_SIMPLE_H )