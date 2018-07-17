/*************************************************************************
 Node  -  description
 -------------------
 d�but                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- R�alisation de la classe <Node> (fichier Node.cpp) ------------
//---------------------------------------------------------------- INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
//#include <iostream>
#include <cstring>

//------------------------------------------------------ Include personnel
#include "Node.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- M�thodes publiques
// type Node::M�thode ( liste des param�tres )
// Algorithme :
//
//{
//} //----- Fin de M�thode

string Node::Name()
//Algorithme :
{
	return name;
} //----- Fin de M�thode

int Node::Hits()
//Algorithme :
{
	return hits;
} //----- Fin de M�thode

//------------------------------------------------- Surcharge d'op�rateurs
Node & Node::operator =(const Node & unNode)
// Algorithme :
//
		{
	return Node(unNode);
} //----- Fin de operator =

//-------------------------------------------- Constructeurs - destructeur
Node::Node(const Node & unNode)
// Algorithme :
//
		{
#ifdef MAP
	cout << "Appel au constructeur de copie de <Node>" << endl;
#endif
	name = unNode.name;
	hits = unNode.hits;
} //----- Fin de Node (constructeur de copie)

Node::Node(String n, int h = 1)
// Algorithme :
//
		{
#ifdef MAP
	cout << "Appel au constructeur de <Node>" << endl;
#endif
	name = n;
	hits = h;
} //----- Fin de Node

Node::~Node()
// Algorithme :
//
{
#ifdef MAP
	cout << "Appel au destructeur de <Node>" << endl;
#endif

} //----- Fin de ~Node

//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- M�thodes prot�g�es
protected :

void Node::UpHits()
//Algorithme :
{
	hits+=1;
} //----- Fin de M�thode
