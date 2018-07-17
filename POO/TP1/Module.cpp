/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation du module <Xxx> (fichier Xxx.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <iostream>

using namespace std;
//------------------------------------------------------ Include personnel
#include "Ensemble.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
static void testConstructeurParDefaut1(void)
{
	Ensemble o1;
	o1.Afficher();
}

static void testConstructeurParDefaut2(void)
{
	Ensemble o2(10);
	o2.Afficher();
}

static void testConstructeurParDefaut3(void)
{
	Ensemble o3(0);
	o3.Afficher();
}

static void testConstructeurParDefaut(void)
{
	testConstructeurParDefaut1();
	testConstructeurParDefaut2();
	testConstructeurParDefaut3();
}

static void testSecondConstructeur1(void)
{
	cout << "-------------testSecondConstructeur1------------\r\n";
	int tab[] = {};
	Ensemble ensemble(tab, 0);
	ensemble.Afficher();
	cout << "----------fin du testSecondConstructeur1--------\r\n";
}

static void testSecondConstructeur2(void)
{
	cout << "-------------testSecondConstructeur2------------\r\n";
	int tab[] = {3,4,1,-4};
	Ensemble ensemble(tab, 0);
	ensemble.Afficher();
	cout << "----------fin du testSecondConstructeur2--------\r\n";
}

static void testSecondConstructeur3(void)
{
	cout << "-------------testSecondConstructeur3------------\r\n";
	int tab[] = {3,4,1,-4};
	Ensemble ensemble(tab, 4);
	ensemble.Afficher();
	cout << "----------fin du testSecondConstructeur3--------\r\n";
}

static void testSecondConstructeur4(void)
{
	cout << "-------------testSecondConstructeur4------------\r\n";
	int tab[] = {3,4,1,-4, 1, 1, 4, -4, 3, 3, -4, 1, 1};
	Ensemble ensemble(tab, 13);
	ensemble.Afficher();
	cout << "----------fin du testSecondConstructeur4--------\r\n";
}

static void testSecondConstructeur(void)
{
	testSecondConstructeur1();
	testSecondConstructeur2();
	testSecondConstructeur3();
	testSecondConstructeur4();
}

static void testEstEgal1()
{
	cout << "-------------testEstEgal1-------------------\r\n";
	int tab1[] = {3,4,1,-4};
	Ensemble e1(tab1, 4);
	int tab2[] = {3,4,1,-4, 1, 1, 4, -4, 3, 3, -4, 1, 1};
	Ensemble e2(tab2, 13);
	
	cout << "EST EGAL : " << e1.EstEgal(e2) << "\r\n";
	
	cout << "-------------fin du testEstEgal1------------\r\n";
}

static void testEstEgal2()
{
	cout << "-------------testEstEgal2-------------------\r\n";
	int tab1[] = {3,4,1,-4};
	Ensemble e1(tab1, 4);
	Ensemble e2;
	
	cout << "EST EGAL : " << e1.EstEgal(e2) << "\r\n";
	
	cout << "-------------fin du testEstEgal2------------\r\n";
}

static void testEstEgal3()
{
	cout << "-------------testEstEgal3-------------------\r\n";
	int tab1[] = {3,4,2,-4};
	Ensemble e1(tab1, 4);
	int tab2[] = {3,4,1,-4, 1, 1, 4, -4, 3, 3, -4, 1, 1};
	Ensemble e2(tab2, 13);
	
	cout << "EST EGAL : " << e1.EstEgal(e2) << "\r\n";
	
	cout << "-------------fin du testEstEgal3------------\r\n";
}

static void testEstEgal()
{
	testEstEgal1();
	testEstEgal2();
	testEstEgal3();
}

static void testAjouter(void)
{
	Ensemble e(4);
	
	e.Ajouter(0);
	
	e.Ajouter(0);
	
	e.Ajouter(-2);
	
	e.Ajouter(3);
	
	e.Ajouter(3);
	
	e.Ajouter(2);
	
	e.Ajouter(2);
	
	e.Ajouter(1);
	//cout << "test ajout 3 : " << e.Ajouter(2) << "\r\n";
	
}

static void testAjuster1(void)
{
	cout << "-------------Debut testAjuster1---------------\r\n\r\n";
	Ensemble ens;
	cout << "Avant: \r\n";
	ens.Afficher();
	ens.Ajuster(-1);
	cout << "Apres delta -1: \r\n";
	ens.Afficher();
	cout << "-------------Fin testAjuster1---------------\r\n\r\n";
}

static void testAjuster2(void)
{
	cout << "-------------Debut testAjuster2---------------\r\n\r\n";
	Ensemble ens;
	cout << "Avant: \r\n";
	ens.Afficher();
	ens.Ajuster(1);
	cout << "Apres delta 1: \r\n";
	ens.Afficher();
	cout << "-------------Fin testAjuster2---------------\r\n\r\n";
}

static void testAjuster3(void)
{
	cout << "-------------Debut testAjuster3---------------\r\n\r\n";
	Ensemble ens;
	cout << "Avant: \r\n";
	ens.Afficher();
	ens.Ajuster(0);
	cout << "Apres delta 0: \r\n";
	ens.Afficher();
	cout << "-------------Fin testAjuster3---------------\r\n\r\n";
}

static void testAjuster4(void)
{
	cout << "-------------Debut testAjuster4---------------\r\n\r\n";
	int t[5] = {-7, 8, 6, -5, 0};
	Ensemble ens(t, 5);
	cout << "Avant: \r\n";
	ens.Afficher();
	ens.Ajuster(8);
	cout << "Apres delta 8: \r\n";
	ens.Afficher();
	cout << "-------------Fin testAjuster4---------------\r\n\r\n";
}

static void testAjuster5(void)
{
	cout << "-------------Debut testAjuster5---------------\r\n\r\n";
	int t[5] = {-7, 8, 6, -5, 0};
	Ensemble ens(t, 5);
	cout << "Avant: \r\n";
	ens.Afficher();
	ens.Ajuster(-1);
	cout << "Apres delta -1: \r\n";
	ens.Afficher();
	cout << "-------------Fin testAjuster5---------------\r\n\r\n";
}

static void testAjuster6(void)
{
	cout << "-------------Debut testAjuster6---------------\r\n\r\n";
	int t[5] = {-7, 8, 6, -5, 0};
	Ensemble ens(t, 5);
	cout << "Avant: \r\n";
	ens.Afficher();
	ens.Ajuster(-10);
	cout << "Apres delta -10: \r\n";
	ens.Afficher();
	cout << "-------------Fin testAjuster6---------------\r\n\r\n";
}

static void testAjuster(void)
{
	testAjuster1();
	testAjuster2();
	testAjuster3();
	testAjuster4();
	testAjuster5();
	testAjuster6();
}


static void afficheInclus(Ensemble::crduEstInclus inclus)
{
	switch (inclus)
	{
		case Ensemble::NON_INCLUSION:
			cout << "NON_INCLUSION\r\n";
			break;
		case Ensemble::INCLUSION_STRICTE:
			cout << "INCLUSION\r\n";
			break;
		case Ensemble::INCLUSION_LARGE:
			cout << "EGALITE\r\n";
			break;
	}
}
static void testEstInclus1(void)
{
	cout << "-------------Debut testInclus1---------------\r\n\r\n";
	int t[5] = {-7, 8, 6, -5, 0};
	Ensemble e1(t, 5);
	e1.Afficher();
	Ensemble e2;
	e2.Afficher();
	afficheInclus(e2.EstInclus(e1));
	cout << "-------------Fin testInclus1---------------\r\n\r\n";
}

static void testEstInclus2(void)
{
	cout << "-------------Debut testInclus2---------------\r\n\r\n";
	int t[5] = {-7, 8, 6, -5, 0};
	Ensemble e1;
	e1.Afficher();
	Ensemble e2(t, 5);
	e2.Afficher();
	afficheInclus(e2.EstInclus(e1));
	cout << "-------------Fin testInclus2---------------\r\n\r\n";
}

static void testEstInclus3(void)
{
	cout << "-------------Debut testInclus3---------------\r\n\r\n";
	Ensemble e1;
	e1.Afficher();
	Ensemble e2;
	e2.Afficher();
	afficheInclus(e2.EstInclus(e1));
	cout << "-------------Fin testInclus3---------------\r\n\r\n";
}

static void testEstInclus4(void)
{
	cout << "-------------Debut testInclus4---------------\r\n\r\n";
	int t[5] = {-7, 8, 6, -5, 0};
	Ensemble e1(t, 5);
	e1.Afficher();
	Ensemble e2(t, 5);
	e2.Afficher();
	afficheInclus(e2.EstInclus(e1));
	cout << "-------------Fin testInclus4---------------\r\n\r\n";
}

static void testEstInclus5(void)
{
	cout << "-------------Debut testInclus5---------------\r\n\r\n";
	int t1[3] = {8, 6, -5};
	int t2[5] = {-7, 8, 6, -5, 0};
	Ensemble e1(t1, 3);
	e1.Afficher();
	Ensemble e2(t2, 5);
	e2.Afficher();
	afficheInclus(e2.EstInclus(e1));
	cout << "-------------Fin testInclus5---------------\r\n\r\n";
}

static void testEstInclus6(void)
{
	cout << "-------------Debut testInclus6---------------\r\n\r\n";
	int t1[3] = {8, 6, -5};
	int t2[5] = {-7, 8, 6, -5, 0};
	Ensemble e1(t2, 5);
	e1.Afficher();
	Ensemble e2(t1, 3);
	e2.Afficher();
	afficheInclus(e2.EstInclus(e1));
	cout << "-------------Fin testInclus6---------------\r\n\r\n";
}

static void testEstInclus7(void)
{
	cout << "-------------Debut testInclus7---------------\r\n\r\n";
	int t1[3] = {-10, 6, -5};
	int t2[5] = {-7, 8, 6, -5, 0};
	Ensemble e1(t2, 5);
	e1.Afficher();
	Ensemble e2(t1, 3);
	e2.Afficher();
	afficheInclus(e2.EstInclus(e1));
	cout << "-------------Fin testInclus7---------------\r\n\r\n";
}

static void testEstInclus8(void)
{
	cout << "-------------Debut testInclus8---------------\r\n\r\n";
	int t1[3] = {10, 6, -5};
	int t2[5] = {-7, 8, 6, -5, 0};
	Ensemble e1(t2, 5);
	e1.Afficher();
	Ensemble e2(t1, 3);
	e2.Afficher();
	afficheInclus(e2.EstInclus(e1));
	cout << "-------------Fin testInclus8---------------\r\n\r\n";
}

static void testEstInclus9(void)
{
	cout << "-------------Debut testInclus9---------------\r\n\r\n";
	int t1[4] = {-7, 3, 6, -5};
	int t2[5] = {-7, 8, 6, -5, 0};
	Ensemble e1(t2, 5);
	e1.Afficher();
	Ensemble e2(t1, 4);
	e2.Afficher();
	afficheInclus(e2.EstInclus(e1));
	cout << "-------------Fin testInclus9---------------\r\n\r\n";
}

static void testEstInclus()
{
	testEstInclus1();
	testEstInclus2();
	testEstInclus3();
	testEstInclus4();
	testEstInclus5();
	testEstInclus6();
	testEstInclus7();
	testEstInclus8();
	testEstInclus9();
}
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

int main()
{
	testAjuster();
	return 0;
}