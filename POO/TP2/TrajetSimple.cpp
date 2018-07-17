//-- Réalisation de la classe <TrajetSimple.cpp> (fichier TrajetSimple.cpp) ---

//--------------------------------------------------------------------- INCLUDE
//------------------------------------------------------------- include système
using namespace std;
#include <iostream>
#include <cstring>

//----------------------------------------------------------- include personnel
#include "TrajetSimple.h"

//------------------------------------------------------------------- constante
const char * nomTransport[] = {"voiture", "avion", "bateau", "train"};

//---------------------------------------------------------------------- PUBLIC
//---------------------------------------------------------- Méthodes publiques
char * TrajetSimple::GetDepart() const
{
    return depart;
}

char * TrajetSimple::GetArrivee() const
{
    return arrivee;
}

void TrajetSimple::Afficher() const
{
    cout << "Trajet direct de " << depart << " à " << arrivee << " en ";
    AfficherMT(vehicule);
    cout << endl;
}

Trajet* TrajetSimple::Copie() const
{
    Trajet* trajet = new TrajetSimple(*this);
    return trajet;
}

//------------------------------------------------- Constructeurs - destructeur

TrajetSimple::TrajetSimple(const char * villeDepart, const char * villeArrivee,
                     MoyenTransport moyenTransport) : vehicule(moyenTransport)
{
#ifdef MAP
cout<<"Appel au constructeur de <TrajetSimple>"<<endl;
#endif
    depart = new char[strlen(villeDepart)+1];
    arrivee = new char[strlen(villeArrivee)+1];
    
    strcpy(depart, villeDepart);
    strcpy(arrivee, villeArrivee);
    
}

TrajetSimple::TrajetSimple(const TrajetSimple & copie)
        : vehicule(copie.vehicule)
{
#ifdef MAP
cout<<"Appel au constructeur de copie de <TrajetSimple>"<<endl;
#endif
    depart = new char[strlen(copie.depart)+1];
    arrivee = new char[strlen(copie.arrivee)+1];
    
    strcpy(depart, copie.depart);
    strcpy(arrivee, copie.arrivee);
}

TrajetSimple::~TrajetSimple()
{
#ifdef MAP
cout << "Appel au destructeur de <TrajetSimple>" << endl;
#endif
    delete [] depart;
    delete [] arrivee;
}


void AfficherMT(MoyenTransport vehicule)
{
    cout << nomTransport[vehicule];
}