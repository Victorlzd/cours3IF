/*************************************************************************
                           NodeDestination  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <NodeDestination> (fichier NodeDestination.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "NodeDestination.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type NodeDestination::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void NodeDestination::AddHit(string previous)
{
	//ajouter un hit pour la combinaison souhaitée
	//regarder si node de départ existe déjà ds la map, sinon créer et ajouter
	//si existe, fetch et augmenter nb hits
	if(previousNodes.count(previous) == 0)
	{
		Node * previousNode = new Node(previous);
		previousNodes.insert(make_pair<string,* Node>(previous,previousNode));
	}
	else
	{
		previousNodes[previous]->UpHits();
	}
}


//------------------------------------------------- Surcharge d'opérateurs
NodeDestination & NodeDestination::operator = ( const NodeDestination & unNodeDestination )
// Algorithme :
//
{
} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur



NodeDestination::NodeDestination(string n, int h = 1):Node(n,h)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <NodeDestination>" << endl;
#endif
previousNodes = new unordered_map<string,* Node>();
} //----- Fin de NodeDestination


NodeDestination::~NodeDestination ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <NodeDestination>" << endl;
#endif
} //----- Fin de ~NodeDestination


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

//protected pr éviter copie et const par def
//NodeDestination::NodeDestination ( const NodeDestination & unNodeDestination )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <NodeDestination>" << endl;
//#endif
//} //----- Fin de NodeDestination (constructeur de copie)
