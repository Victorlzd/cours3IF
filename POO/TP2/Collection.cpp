//------ Réalisation de la classe <Collection> (fichier Collection.cpp) -------

//--------------------------------------------------------------------- INCLUDE
//------------------------------------------------------------- include système
using namespace std;
#include <iostream>
#include <cstring>

//----------------------------------------------------------- include personnel
#include "Collection.h"

//---------------------------------------------------------------------- PUBLIC
//---------------------------------------------------------- Méthodes publiques
void Collection::Ajouter(Trajet *trajet)
{
    if(tailleAct == tailleMax)
    {
        allouer(tailleMax);
    }
    trajets[tailleAct] = trajet;
    ++tailleAct;
}

void Collection::Ajouter(const Collection &collection)
{
    unsigned int i;
    for (i = 0; i < collection.GetTailleActuelle(); ++i)
    {
        Trajet* trajet = collection.GetTrajet(i);
        Ajouter(trajet->Copie());
    }
}

Trajet* Collection::GetTrajet(unsigned int index) const
{
    if(index < tailleAct)
    {
        return trajets[index];
    }
    else
    {
        return nullptr;
    }
}

Trajet* Collection::GetLastTrajet() const
{
    if(EstVide())
    {
        return nullptr;
    }
    return trajets[tailleAct-1];
}

void Collection::Afficher() const
{
    if(EstVide())
    {
        cout << "VIDE" << endl;
    }
    else
    {
        unsigned int i;
        cout << "{" << endl;
        for (i = 0; i < tailleAct; ++i)
        {
            cout << "    Trajet " << i+1 << " : ";
            trajets[i]->Afficher();
        }
        cout << "}" << endl;
    }
}

void Collection::AfficherAvance(const char * arrivee) const
{
    if(EstVide())
    {
        cout << "VIDE" << endl;
    }
    else
    {
        unsigned int i;
        unsigned int j = 1;
        unsigned int k = 1;
        bool changeVoyage = true;
        cout << "{" << endl;
        for (i = 0; i < tailleAct; ++i)
        {
            if (changeVoyage)
            {
                cout << "Voyage numero " << j << " : " << endl;
                changeVoyage = false;
            }
            cout << "    Trajet " << k << " : ";
            trajets[i]->Afficher();
            int compArrivee = strcmp(arrivee, trajets[i]->GetArrivee());
            if (compArrivee == 0)
            {
                cout << "Fin du voyage" << endl;
                ++j;
                changeVoyage = true;
                k = 0;
            }
            ++k;
        }
        cout << "}" << endl;
    }
}

bool Collection::EstVide() const
{
    return tailleAct==0;
}

bool Collection::EstDansLaCollection(const char* depart,
                                     const char* arrivee) const
{
    if(EstVide())
    {
        return false;
    }
    else
    {
        unsigned int i;
        for (i = 0; i < tailleAct; ++i)
        {
            Trajet* trajet = GetTrajet(i);
        
            int compDepart = strcmp(depart, trajet->GetDepart());
            int compArrivee = strcmp(arrivee, trajet->GetArrivee());
        
            if(compDepart==0 && compArrivee==0)
            {
                return true;
            }
        }
        return false;
    }
}

unsigned int Collection::GetTailleActuelle() const
{
    return tailleAct;
}


//------------------------------------------------- Constructeurs - destructeur
Collection::Collection(unsigned int taille) : tailleMax(taille), tailleAct(0)
{
#ifdef MAP
    cout << "Appel au constructeur de <Collection>"<< endl;
#endif
    trajets = new Trajet*[tailleMax];
    unsigned int i;
    for (i = 0; i < tailleAct; ++i)
    {
        trajets[i] = nullptr;
    }
}

Collection::Collection(const  Collection & copie) :
        tailleMax(copie.tailleMax), tailleAct(copie.tailleAct)
{
#ifdef MAP
cout << "Appel au constructeur de copie de <Collection>"<< endl;
#endif
    trajets = new Trajet*[copie.tailleMax];
    unsigned int i;
    for (i = 0; i < tailleAct; ++i)
    {
        trajets[i] = copie.trajets[i]->Copie();
    }
}

Collection::~Collection()
{
    // On libère les espaces pointés par les pointeurs contenus dans le tableau
    // On libère l'espace du tableau
#ifdef MAP
    cout << "Appel au destructeur de <Collection>"<< endl;
#endif
    unsigned int i;
    for (i = 0; i < tailleAct; ++i)
    {
        delete trajets[i];
    }
    delete [] trajets;
}

//----------------------------------------------------------------------- PRIVE

//---------------------------------------------------------- Méthodes protégées
void Collection::allouer(unsigned int delta)
{
    // On alloue un tableau avec la nouvelle taille
    // On copie l'ancien tableau dans le nouveau
    // On libère l'ancien
    // On stocke le nouveau dans trajets
    
    Trajet** temp = new Trajet*[tailleAct+delta];
    unsigned int i;
    for (i = 0; i < tailleAct; ++i)
    {
        temp[i] = trajets[i];
    }
    delete [] trajets;
    trajets = temp;
    tailleMax = tailleMax+delta;
}
