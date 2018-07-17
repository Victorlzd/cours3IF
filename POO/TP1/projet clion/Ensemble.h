//------------- Interface de la classe <Ensemble> (fichier Ensemble.h) ------------------
#ifndef ENSEMBLE_H
#define ENSEMBLE_H

//-------------------------------------------------------- Interfaces utilisées


//------------------------------------------------------------------ Constantes
const unsigned int CARD_MAX = 5;

//----------------------------------------------------------------------- Types


//-----------------------------------------------------------------------------
// Rôle de la classe <XXX>
// La classe ensemble permet de gérer un ensemble mathématique d'entier de
// taille maximale quelconque fixée (mais modifiable)
//-----------------------------------------------------------------------------

class Ensemble
{
	
	
	//------------------------------------------------------------------ PUBLIC
public :
	
	enum crduEstInclus{ NON_INCLUSION, INCLUSION_LARGE, INCLUSION_STRICTE };
	enum crduAjouter{DEJA_PRESENT, PLEIN, AJOUTE};
	
	//------------------------------------------------------ Méthodes publiques
	void Afficher(void);
	// Mode d'emploi:
	// Affiche le contenu de l'ensemble
	
	bool EstEgal( const Ensemble & unEnsemble) const;
	// Mode d'emploi:
	// renvoie true si les deux ensembles contiennent exactement les même
	// entiers renvoient false sinon
	
	crduEstInclus EstInclus( const Ensemble & unEnsemble ) const;
	
	crduAjouter Ajouter(int aAjouter);
	// Mode d'emploi:
	// Renvoie DEJA_PRESENT si l'entier est déjà dans l'ensemble, renvoie PLEIN
	// si l'ensemble a atteint sa taille maximale et renvoie AJOUTE et ajoute
	// l'entier à l'ensemble sinon
	
	unsigned int Ajuster(int delta);
	// Mode d'emploi :
	// Modifie la taille de l'ensemble de la valeur de delta
	// (si delta < 0, la taille de l'ensemble diminue)
	// Contrat :
	// tailleAct <= tailleMax
	//-------------------------------------------------- Surcharge d'opérateurs
	
	//--------------------------------------------- Constructeurs - Destructeur
	explicit Ensemble(unsigned int cardMax = CARD_MAX);
	// Mode d'emploi:
	// Constructeur créant un objet Ensemble de cardinalité max fixée
	// Constructeur par défaut avec une cardinalité max fixé à CARD_MAX
	
	Ensemble (int t[], unsigned int nbElements);
	//Mode d'emploi :
	//Constructeur secondaire de la classe ensemble
	//Ajoute les elements spÃ©cifiÃ©s dans le tableau à l'ensemble
	//Définit les caractéristiques de l'ensemble
	//Contrat :
	//0 <= tailleAct <= tailleMax
	//taille de t >= nbElements
	
	Ensemble(const Ensemble & unEnsemble);
	// Mode d'emploi :
	// Constructeur de copie
	
	
	virtual ~Ensemble();
	//------------------------------------------------------------------- PRIVE
protected:
	//------------------------------------------------------- Méthodes protégées
	
	//------------------------------------------------------- Attributes protégé
	unsigned int tailleMax;
	unsigned int tailleAct;
	int * tableau;
};

//------------------------------------- Autres définitions dépendantes de <XXX>

//-------------------------------------------- FONCTIONS ORDINAIRES EXPORTABLES
int searchMin(int t[], unsigned int taille);
//Mode d'emploi :
//Retourne la valeur minimale contenue dans les tailles premières cases du tableau rentré en paramètre

int retirer(int t[], unsigned int taille, int valeur);
//Mode d'emploi :
//Retire la valeur contenue dans les tailles premières cases du tableau rentré en paramètre autant de fois qu'elle apparait
//Retourne le nombre de fois que la valeur cherchée a été supprimée dans le tableau


#endif // ! defined ( ENSEMBLE_H )