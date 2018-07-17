//-------- Réalisation de la classe <Catalogue> (fichier Catalogue.cpp) -------

//--------------------------------------------------------------------- INCLUDE
//------------------------------------------------------------- include système
using namespace std;
#include <iostream>
#include <cstring>

//----------------------------------------------------------- include personnel
#include "Catalogue.h"
#include "Collection.h"

//---------------------------------------------------------------------- PUBLIC
//---------------------------------------------------------- Méthodes publiques
void Catalogue::Ajouter(Trajet *unTrajet)
{
    collection.Ajouter(unTrajet);
}

void Catalogue::Afficher() const
{
    cout << "Le catalogue contient les trajets suivants :" << endl;
    collection.Afficher();
}

Collection Catalogue::RechercheSimple(const char * depart,
                                      const char * arrivee) const
{
    // Stocke dans une collection c l'ensemble des trajets allant
    // de depart a arrivee
    
    Collection c;
    unsigned int i;
    
    for (i = 0; i < collection.GetTailleActuelle(); ++i)
    {
        Trajet* trajet = collection.GetTrajet(i);
        
        int compDepart = strcmp(depart, trajet->GetDepart());
        int compArrivee = strcmp(arrivee, trajet->GetArrivee());
        
        if(compDepart==0 && compArrivee==0)
        {
            c.Ajouter(trajet->Copie());
        }
    }
    return c;
}

Collection Catalogue::RechercheAvancee(const char* depart,
                       const char* arrivee) const
{
    // Stocke dans une collection c l'ensemble des combinaisons de
    // trajets allant de depart a arrivee
    Collection resultat;
    Collection trajetEmpruntes;
    Recursion(depart, arrivee, trajetEmpruntes, resultat);
    return resultat;
}

void Catalogue::Recursion(const char* depart, const char* arrivee,
                          Collection TrajetsEmpruntes, Collection & result) const
{
    unsigned int i;
    for (i = 0; i < collection.GetTailleActuelle(); ++i)
    {
        Trajet* trajet = collection.GetTrajet(i);
        
        int compDepart = strcmp(depart, trajet->GetDepart());
        bool dejaEmprunte = TrajetsEmpruntes.EstDansLaCollection
                (trajet->GetDepart(), trajet->GetArrivee());
        
        // pour chaque trajet on teste si la ville de depart est bien depart
        // et on verifie que l'on ne l'ai pas deja emprunte
        
        if (compDepart == 0 && !dejaEmprunte)
        {
            Collection nvxTrajetsEmpruntes(TrajetsEmpruntes);
            nvxTrajetsEmpruntes.Ajouter(trajet->Copie());
            // On crée une copie de la Collection puis on ajoute le trajet courant
            
            int compArrivee = strcmp(arrivee, trajet->GetArrivee());
            
            if (compArrivee == 0)
            {
                // si on est arrive on ajoute les trajets a la collection result
                result.Ajouter(nvxTrajetsEmpruntes);
            }
            else
            {
                // sinon on appelle a nouveau la methode
                Recursion(trajet->GetArrivee(), arrivee,
                          nvxTrajetsEmpruntes,result);
            }
        }
    }
}

//------------------------------------------------- Constructeurs - destructeur
Catalogue::Catalogue(): collection()
{
#ifdef MAP
cout << "Appel du constructeur de <Catalogue>" << endl;
#endif
}

Catalogue::~Catalogue()
{
#ifdef MAP
cout << "Appel du destructeur de <Catalogue>" << endl;
#endif
}
