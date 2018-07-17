//------------- Interface de la classe <OutputGraph> (fichier OutputGraph.h) ------------------
#ifndef OUTPUTGRAPH_H
#define OUTPUTGRAPH_H

//-------------------------------------------------------- Interfaces utilisées
#include <unordered_map>
#include "Node.h"
#include "NodeDestination.h"

void WriteCodeGraphWiz(const unordered_map<string,NodeDestination> & links, ostream os);


//------------------------------------------------------------------ Constantes
//
//
//----------------------------------------------------------------------- Types
//
//
//-----------------------------------------------------------------------------
// Rôle de la classe <OutputGraph>
// La classe OutputGrap permet de passer d'une map à un code GraphWiz
//-----------------------------------------------------------------------------
//
//class OutputGraph
//{
//	//------------------------------------------------------------------ PUBLIC
//	public :
//	//------------------------------------------------------ Méthodes publiques
//	void WriteCodeFile(string filename);
//	//-------------------------------------------------- Surcharge d'opérateurs
//
//	//--------------------------------------------- Constructeurs - Destructeur
//	OutputGraph(const unordered_map<string,NodeDestination> & mapOfLink);
//	//------------------------------------------------------------------- PRIVE
//	protected:
//	//------------------------------------------------------- Méthodes protégées
//	OutputGraph(const OutputGraph & copy);
//	operator=(const OutputGraph & copy);
//
//	string generateCode();
//	string generateCodeLink();
//
//	//------------------------------------------------------- Attributes protégé
//	const unordered_map<string,NodeDestination> mapLink;
//	unordered_map<string,int> nodeNumbers;
//};
//
//------------------------------------- Autres définitions dépendantes de <XXX>


#endif // ! defined ( OUTPUTGRAPH_H )