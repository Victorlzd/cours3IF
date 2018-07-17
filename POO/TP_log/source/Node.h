/*************************************************************************
 Node  -  description
 -------------------
 d�but                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <Node> (fichier Node.h) ----------------
#if ! defined ( Node_H )
#define Node_H

using namespace std;
#include <cstring>

//--------------------------------------------------- Interfaces utilis�es

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <Node>
//
//
//------------------------------------------------------------------------

class Node {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	string Name();
	// Mode d'emploi :
	//
	// Contrat :
	//
	int Hits();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'op�rateurs
	Node & operator =(const Node & unNode);
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur
	Node(const Node & unNode);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

	Node();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~Node();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es
	void UpHits();
	// Mode d'emploi :
	//
	// Contrat :
	//
//----------------------------------------------------- Attributs prot�g�s
	string name;
	int hits;

};

//-------------------------------- Autres d�finitions d�pendantes de <Node>

#endif // Node_H

