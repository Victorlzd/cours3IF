//----- Interface de la classe <TrajetCompose> (fichier TrajetCompose.h) ------
#ifndef TRAJET_COMPOSE_H
#define TRAJET_COMPOSE_H

//-------------------------------------------------------- Interfaces utilisées
#include "Collection.h"
#include "Trajet.h"

//-----------------------------------------------------------------------------
// Rôle de la classe <TrajetCompose>
// La classe TrajetCompose symbolise un trajet ayant des étapes. Il contient
// donc une liste ordonnée de Trajet. Un TrajetCompose est une sorte de Trajet,
// cette classe hérite donc publiquement de la classe Trajet.
//-----------------------------------------------------------------------------

class TrajetCompose :public Trajet
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
    
    virtual Trajet* Copie() const;
    // Renvoie un pointeur sur une copie distincte de ce trajet
    // Contrat :
    // Le pointeur retourné pointe sur un objet alloué dynamiquement
    // IL DOIT ETRE LIBERE PAR UN delete !!!
    
    //--------------------------------------------- Constructeurs - Destructeur
    TrajetCompose(const Collection & collec);
    // Constructeur de la classe
    
    TrajetCompose(const TrajetCompose & copie);
    // Constructeur de copie de la classe
    
    virtual ~TrajetCompose();
    // Destructeur de la classe
    
    //------------------------------------------------------------------- PRIVE
    protected:
    //-------------------------------------------------------- Methodes protégé
    TrajetCompose();
    //------------------------------------------------------ Attributes protégé
    Collection etapes;
    // Collection contenant la liste des etapes du TrajetCompose
};



#endif // ! defined ( TRAJET_COMPOSE_H )
