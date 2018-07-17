
/*************************************************************************
                           Main.cpp  -  description
                             -------------------
    d�but                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- R�alisation du module <Main> (fichier Main.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include syst�me
using namespace std;
#include <cstring>

//------------------------------------------------------ Include personnel

#include "Main.h"
#include "Read.h"
#include "OutputRegular.h"
#include "OutputGraph.h"


///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions priv�es
//static type nom ( liste de param�tres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
//type Nom ( liste de param�tres )
//// Algorithme :
////
//{
//} //----- fin de Nom

int main(int argc, char * arglist)
// Algorithme :
//
{
	int i;
	bool e;
	bool t;
	bool g;
	string fileName = str(arglist[argc-1]);
	string graphName;
	string hour = "none";

	for(i = 1; i < argc-1 ; i++){
		if(strcmp(arglist[i], "-e") == 0){
			e = true;
		}
		else if(strcmp(arglist[i], "-t") == 0){
			t = true;
			i++;
			hour = str(arglist[i]);
		}
		else if(strcmp(arglist[i], "-g") == 0){
			g = true;
			i++;
			graphName = str(arglist[i]);
		}
	}

	//call to read file
	Read::Read(fileName,e,t,hour);
	//call to start output
	if(g)
	{
		OutputGraph();
	}
	else
	{
		OutPutRegular();
	}


} //----- fin de main

