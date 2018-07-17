/*************************************************************************
 Node  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <Node> (fichier Node.h) ----------------
#if ! defined ( Node_H )
#define Node_H

using namespace std;
#include <cstring>

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Node>
//
//
//------------------------------------------------------------------------

class Node {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
	// type Méthode ( liste des paramètres );
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

//------------------------------------------------- Surcharge d'opérateurs
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
//----------------------------------------------------- Méthodes protégées
	void UpHits();
	// Mode d'emploi :
	//
	// Contrat :
	//
//----------------------------------------------------- Attributs protégés
	string name;
	int hits;

};

//-------------------------------- Autres définitions dépendantes de <Node>

#endif // Node_H

