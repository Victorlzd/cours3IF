/*************************************************************************
                           NodeDestination  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation de la classe <NodeDestination> (fichier NodeDestination.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include syst�me
using namespace std;
#include <iostream>

//------------------------------------------------------ Include personnel
#include "NodeDestination.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type NodeDestination::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

void NodeDestination::AddHit(string previous)
{
	//ajouter un hit pour la combinaison souhait�e
	//regarder si node de d�part existe d�j� ds la map, sinon cr�er et ajouter
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


//------------------------------------------------- Surcharge d'op�rateurs
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

//----------------------------------------------------- M�thodes prot�g�es

//protected pr �viter copie et const par def
//NodeDestination::NodeDestination ( const NodeDestination & unNodeDestination )
//// Algorithme :
////
//{
//#ifdef MAP
//    cout << "Appel au constructeur de copie de <NodeDestination>" << endl;
//#endif
//} //----- Fin de NodeDestination (constructeur de copie)
