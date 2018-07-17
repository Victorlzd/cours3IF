//------------- Réalisation de la classe <Ensemble> (fichier Ensemble.cpp) --------------

//--------------------------------------------------------------------- INCLUDE
//------------------------------------------------------------- include système
using namespace std;

#include <iostream>

//----------------------------------------------------------- include personnel
#include "Ensemble.h"

//------------------------------------------------------------------ Constantes


//---------------------------------------------------------------------- PUBLIC
//---------------------------------------------------------- Méthodes publiques
void Ensemble::Afficher(void)
{
	unsigned int i = 0;
	
	cout << tailleAct << "\r\n";
	cout << tailleMax << "\r\n";
	
	cout << "{";
	
	for (; i < tailleAct; ++i)
	{
		cout << tableau[i];
		if (i != tailleAct - 1)
		{
			cout << ",";
		}
	}
	
	cout << "}\r\n";
}

bool Ensemble::EstEgal(const Ensemble &unEnsemble) const
{
	
	if (unEnsemble.tailleAct != tailleAct)
	{
		return false;
	}
	for (unsigned int i = 0; i < tailleAct; ++i)
	{
		if (unEnsemble.tableau[i] != tableau[i])
		{
			return false;
		}
	}
	return true;
}

Ensemble::crduAjouter Ensemble::Ajouter(int aAjouter)
{
	// la 1ère partie de la méthode recherche si l'entier doit être ajouter
	// et définit la valeur de retour
	// la 2ème partie n'est effectuée qui si on doit ajouter l'entier à l'ensemble
	// on y ajoute l'entier et on décale toutes les autres pour garder l'ordre croissant
	
	#ifdef MAP
		cout << "\r\n\r\najout de " << aAjouter << " dans :\r\n";
		Afficher();
	#endif
	
	
	Ensemble::crduAjouter retour = Ensemble::AJOUTE;
	bool nePasAjouter = false;
	bool decaler = false;
	int tampon1;
	int tampon2;
	unsigned int i = 0;
	
	//------ 1ère partie -------------
	
	if (tailleAct == tailleMax)
	{
		retour = Ensemble::PLEIN;
		nePasAjouter = true;
	}
	
	for (; i < tailleAct; ++i)
	{
		if (tableau[i] == aAjouter)
		{
			retour = Ensemble::DEJA_PRESENT;
			break;
		} else if (!nePasAjouter & (tableau[i] > aAjouter))
		{
			tampon1 = aAjouter;
			retour = Ensemble::AJOUTE;
			decaler = true;
			#ifdef MAP
				cout << "###########" << tampon1 << "      " << tableau[i] << "\r\n";
			#endif
			break;
		}
	}
	if ((i == tailleAct) & !nePasAjouter)
	{
		tableau[i] = aAjouter;
		tailleAct++;
		retour = Ensemble::AJOUTE;
	}
	
	
	//------ 2ème partie -------------
	
	
	if (decaler)
	{
		for (; i < tailleAct; ++i)
		{
			tampon2 = tableau[i];
			tableau[i] = tampon1;
			tampon1 = tampon2;
		}
		tableau[tailleAct] = tampon1;
		tailleAct++;
	}
	#ifdef MAP
		cout << "resultat : " << retour<< "\r\n";
		Afficher();
		cout << "------------------------------------------\r\n";
	#endif
	return retour;
}

Ensemble::crduEstInclus Ensemble::EstInclus(const Ensemble &unEnsemble) const
{
	
	if (EstEgal(unEnsemble))
	{
		return INCLUSION_LARGE;
	}
	else if(tailleAct == 0)
	{
		return INCLUSION_STRICTE;
	}
	
	unsigned int j = 0;
	for (unsigned int i = 0; i < unEnsemble.tailleAct; ++i)
	{
		if (tableau[j] < unEnsemble.tableau[i])
		{
			return NON_INCLUSION;
		}
		else if (tableau[j] == unEnsemble.tableau[i])
		{
			j++;
			if(tailleAct == j)
			{
				return INCLUSION_STRICTE;
			}
		}
	}
	return NON_INCLUSION;
	
}

unsigned int Ensemble::Ajuster(int delta)
{
	if (delta == 0)
	{
		return tailleMax;
	}
	
	if (((int) (tailleMax + delta)) >= ((int) tailleAct))
	{
		tailleMax = tailleMax + delta;
	} else
	{
		tailleMax = tailleAct;
	}
	#ifdef MAP
		cout << "### tailleMax : " << tailleMax << "\r\n";
		cout << "### tailleAct : " << tailleAct << "\r\n";
	#endif
	int *tabTampon = new int[tailleAct];
	for (unsigned int i = 0; i < tailleAct; i++)
	{
		tabTampon[i] = tableau[i];
	}
	delete[] tableau;
	tableau = new int[tailleMax];
	for (unsigned int i = 0; i < tailleAct; i++)
	{
		tableau[i] = tabTampon[i];
	}
	delete[] tabTampon;
	return tailleMax;
}
//------------------------------------------------------ Surcharge d'opérateurs


//------------------------------------------------- Constructeurs - destructeur
Ensemble::Ensemble(unsigned int cardMax) :
		tailleMax(cardMax), tailleAct(0)
{
	#ifdef MAP
	cout << "Appel au constructeur de Ensemble\r\n";
	#endif
	tableau = new int[tailleMax];
}

Ensemble::Ensemble(int t[], unsigned int nbElements) : tailleMax(nbElements)
{
	#ifdef MAP
	cout << "Appel au constructeur secondaire de Ensemble\r\n";
	#endif
	tableau = new int[tailleMax];
	int min;
	int taille = nbElements;
	
	#ifdef MAP_RETIRER
	cout << "######t : <" << taille << "> : ";
			for(int j = 0; j<taille; j++)
				cout << t[j] << " ";
			cout << "\r\n";
	#endif
	
	int i = 0;
	while (taille != 0)
	{
		min = searchMin(t, taille);
		tableau[i] = min;
		taille -= retirer(t, taille, min);
		
		#ifdef MAP_RETIRER
		cout << "######t : <" << taille << "> : ";
		for(int j = 0; j<taille; j++)
			cout << t[j] << " ";
		cout << "\r\n";
		#endif
		
		i++;
	}
	tailleAct = i;
}

Ensemble::~Ensemble()
{
	#ifdef MAP
	cout << "Appel au destructeur de Ensemble\r\n";
	#endif
	delete[] tableau;
}



//-------------------------------------------- FONCTIONS ORDINAIRES EXPORTABLES

int searchMin(int t[], unsigned int taille)
{
	int min = t[0];
	for (unsigned int i = 1; i < taille; i++)
	{
		if (min > t[i])
		{
			min = t[i];
		}
	}
	return min;
}

int retirer(int t[], unsigned int taille, int valeur)
{
	int nbRetires = 0;
	unsigned int tailleReelle = taille;
	for (unsigned int i = 0; i < tailleReelle; i++)
	{
		if (t[i] == valeur) //Si on trouve la valeur dans le tableau, on la retire
		{
			for (unsigned int j = i; j < taille - 1; j++)//On dÃ©cale toutes les valeurs suivantes dans le tableau d'un indice
			{
				t[j] = t[j + 1];
			}
			tailleReelle--; //La taille qui nous interesse diminue d'un
			nbRetires++;
			i--;
		}
	}
	return nbRetires;
}

//----------------------------------------------------------------------- PRIVE

//---------------------------------------------------------- Méthodes protégées




