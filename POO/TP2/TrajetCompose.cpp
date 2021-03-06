//- Réalisation de la classe <TrajetCompose.cpp> (fichier TrajetCompose.cpp) --

//--------------------------------------------------------------------- INCLUDE
//------------------------------------------------------------- include système
using namespace std;
#include <iostream>

//----------------------------------------------------------- include personnel
#include "TrajetCompose.h"

//---------------------------------------------------------------------- PUBLIC
//---------------------------------------------------------- Méthodes publiques
char * TrajetCompose::GetDepart() const
{
    if(etapes.EstVide())
    {
        return nullptr;
    }
    return etapes.GetTrajet(0)->GetDepart();
}

char * TrajetCompose::GetArrivee() const
{
    if(etapes.EstVide())
    {
        return nullptr;
    }
    return etapes.GetLastTrajet()->GetArrivee();
}

void TrajetCompose::Afficher() const
{
    cout<<"Trajet composé des étapes suivantes :"<<endl;
    etapes.Afficher();
}

Trajet* TrajetCompose::Copie() const
{
    Trajet* trajet = new TrajetCompose(*this);
    return trajet;
}

//------------------------------------------------- Constructeurs - destructeur
TrajetCompose::TrajetCompose(const Collection & collec) : etapes(collec)
{
#ifdef MAP
    cout << "Appel au constructeur de <TrajetCompose>" << endl;
#endif
}

TrajetCompose::TrajetCompose(const TrajetCompose & copie)
        : etapes(copie.etapes)
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <TrajetCompose>" << endl;
#endif
}

TrajetCompose::~TrajetCompose()
{
#ifdef MAP
    cout << "Appel au destructeur de <TrajetCompose>" << endl;
#endif
}
