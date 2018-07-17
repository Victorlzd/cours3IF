/*************************************************************************
 NodeDestination  -  description
 -------------------
 d�but                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <NodeDestination> (fichier NodeDestination.h) ----------------
#if ! defined ( NodeDestination_H )
#define NodeDestination_H

using namespace std;
#include <cstring>
//--------------------------------------------------- Interfaces utilis�es
#include "Node.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// R�le de la classe <NodeDestination>
//
//
//------------------------------------------------------------------------

class NodeDestination: public Node {
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- M�thodes publiques
	// type M�thode ( liste des param�tres );
	// Mode d'emploi :
	//
	// Contrat :
	//

	void AddHit(string previous);
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------- Surcharge d'op�rateurs
	NodeDestination & operator =(const NodeDestination & unNodeDestination);
	// Mode d'emploi :
	//
	// Contrat :
	//

//-------------------------------------------- Constructeurs - destructeur

	NodeDestination();
	// Mode d'emploi :
	//
	// Contrat :
	//

	virtual ~NodeDestination();
	// Mode d'emploi :
	//
	// Contrat :
	//

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- M�thodes prot�g�es
	NodeDestination(const NodeDestination & unNodeDestination);
	// Mode d'emploi (constructeur de copie) :
	//
	// Contrat :
	//

//----------------------------------------------------- Attributs prot�g�s
	unordered_map<string, Node> previousNodes;

};

//-------------------------------- Autres d�finitions d�pendantes de <NodeDestination>

#endif // NodeDestination_H

