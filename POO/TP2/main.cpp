#include <iostream>
#include <cstring>
#include "Collection.h"
#include "TrajetSimple.h"
#include "TrajetCompose.h"
#include "Catalogue.h"

using namespace std;


// Fonctions ordinaires
static void saisirChaine(char* chaine, const char* message)
// cette procedure permet recupere une chaine entree au clavier en affichant
// un message sur la console avant
{
    cout << message;
    cin >> chaine;
}

static int saisirInt(const char* message)
// Cette fonction retourne un entier etre au clavier en affichant
// un message sur la console avant
{
    int x;
    cout << message;
    cin >> x;
    return x;
}

static MoyenTransport choixMT()
// Cette fonction retourne un MoyenTransport choisi par l'utilisateur
{
    cout << "1. Automobile" << endl;
    cout << "2. Avion" << endl;
    cout << "3. Bateau" << endl;
    cout << "4. Train" << endl;
    
    for(;;)
    {
        switch (saisirInt("--- Votre choix : "))
        {
            case 1:
                return AUTO;
            case 2:
                return AVION;
            case 3:
                return BATEAU;
            case 4:
                return TRAIN;
        }
    }
}

static void ajoutTrajet(Catalogue &catalogue)
// Cette procedure permet a l'utilisateur d'entrer un Trajet dans le catalogue
// passe en parametre
{
    
    bool boucle = true;
    Collection collection;
    char depart[100];
    char arrivee[100];
    MoyenTransport moyenTransport;
    
    
    cout << "-------------- AJOUT TRAJET --------------" << endl;
    
    
    saisirChaine(arrivee, "Ville de départ : ");
    while(boucle)
        // On permet a l'utilisateur d'entre la ville d'arrivee de l'etape
        // ainsi que le moyen de transport utilise
        // la ville de depart est la ville d'arrivee precedente
    {
        strcpy(depart, arrivee);
        saisirChaine(arrivee, "Ville d'arrivée : ");
        moyenTransport = choixMT();
        collection.Ajouter(new TrajetSimple(depart, arrivee, moyenTransport));
        
        cout << "Voulez-vous ajouter une étape à ce trajet?" << endl;
        cout << "(0 pour NON, autre chose pour OUI)" << endl;
        
        if(saisirInt("--- Votre choix : ")==0)
        {
            boucle = false;
        }
        else
        {
            boucle = true;
        }
    }
    
    // Les trajets comportant qu'une seule etape sont des TrajetSimple les
    // autres sont des TrajetComposes
    if(collection.GetTailleActuelle()==1)
    {
        catalogue.Ajouter(collection.GetTrajet(0)->Copie());
    }
    else
    {
        catalogue.Ajouter(new TrajetCompose(collection));
    }
    
    cout << "------------ FIN AJOUT TRAJET ------------" << endl;
	cout << endl << endl;
}

static void rechercheSimple(Catalogue & catalogue)
    // Cette procedure permet a l'utilisateur d'effectuer une recherche simple
    // dans le catalogue passe en parametre
{
    char depart[100];
    char arrivee[100];
    cout << "-------------- RECHERCHE SIMPLE --------------"<< endl;
    saisirChaine(depart, "Ville de départ : ");
    saisirChaine(arrivee, "Ville d'arrivée : ");
    cout << "Voici l'ensemble des trajets correspondants :" << endl;
    catalogue.RechercheSimple(depart, arrivee).Afficher();
	cout << "------------ FIN RECHERCHE SIMPLE ------------"<< endl;
	cout << endl << endl;
    
}

static void rechercheAvancee(Catalogue & catalogue)
    // Cette procedure permet a l'utilisateur d'effectuer une recherche avance
    // dans le catalogue passe en parametre
{
    char depart[100];
    char arrivee[100];
    
    cout << "-------------- RECHERCHE AVANCEE --------------"<< endl;
    saisirChaine(depart, "Ville de départ : ");
    saisirChaine(arrivee, "Ville d'arrivée : ");
	cout << endl << "-------------- RESULTAT RECHERCHE --------------"<< endl;
    cout << "Voici l'ensemble des voyages correspondants :" << endl;
    
    catalogue.RechercheAvancee(depart, arrivee).AfficherAvance(arrivee);
	cout << "------------ FIN RECHERCHE AVANCEE ------------"<< endl;
	cout << endl << endl;
}

static bool menu(Catalogue & catalogue)
    // cette fonction permet a l'utilisateur d'effectuer un ajout ou une
    // recherche selon son choix sur le catalogue passe en parametre
    // La fonction retourne true si le programme doit continuer
    // et false s'il faut arreter
{
    bool boucle = true;
    bool quitter = false;
    
    cout << "-------------- MENU PRINCIPAL --------------" << endl;
    cout << "1. Ajouter un trajet au catalogue" << endl;
    cout << "2. Rechercher un trajet (simple)" << endl;
    cout << "3. Rechercher un trajet (avance)" << endl;
    cout << "0. Sortir du programme" << endl;
    
    while (boucle)
    {
        boucle = false;
        switch (saisirInt("--- Votre choix : "))
        {
            case 0:
                quitter = true;
                break;
            case 1:
	            cout << endl << endl;
                ajoutTrajet(catalogue);
                break;
            case 2:
	            cout << endl << endl;
	            rechercheSimple(catalogue);
                break;
            case 3:
	            cout << endl << endl;
	            rechercheAvancee(catalogue);
                break;
            default:
                boucle = true;
                break;
        }
    }
    
    return quitter;
}

static void programmePrincipal()
{
    Catalogue catalogue;
    
    while(!menu(catalogue));
}

//------- Test rechercheSimple -------
static void testrechercheSimple()
{
    Catalogue c;
    
    c.Ajouter(new TrajetSimple("Lyon","Paris",TRAIN));
    c.Ajouter(new TrajetSimple("Paris","Bordeaux",AUTO));
    
    Collection c1(5);
    c1.Ajouter(new TrajetSimple("Lyon","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Paris","Bordeaux",AUTO));
    c1.Ajouter(new TrajetSimple("Bordeaux","Brest",BATEAU));
    c1.Ajouter(new TrajetSimple("Brest","Londres",AVION));
    Trajet* tc = new TrajetCompose(c1);
    c.Ajouter(tc);
    
    c.Ajouter(new TrajetSimple("Bordeaux","Brest",BATEAU));
    c.Ajouter(new TrajetSimple("Lyon","Londres",AVION));
    
    rechercheSimple(c);
}



//------- Test TrajetSimple -------
static void testTrajetSimple()
{
    cout<<"------- Test TrajetSimple -------"<<endl;
    TrajetSimple ts("Lyon","Paris",TRAIN);
    ts.Afficher();
    cout<<"départ = " << ts.GetDepart() <<endl;
    cout<<"arrivée = " << ts.GetArrivee() << endl;
    cout<<"------- Fin Test TrajetSimple -------"<<endl;
}

//------- Test Collection -------
static void testCollection1(){
    cout<<"------- Test Collection 1 -------"<<endl;
    Collection c1;
    c1.Ajouter(new TrajetSimple("Lyon","Paris",TRAIN));
    c1.GetTrajet(0)->Afficher();
    cout<<"------- Fin Test Collection 1 -------"<<endl;
}

static void testCollection2()
{
    cout<<"------- Test Collection 2 -------"<<endl;
    Collection c1(0);
    c1.Ajouter(new TrajetSimple("Lyon","Paris",TRAIN));
    c1.GetTrajet(0)->Afficher();
    cout<<"------- Fin Test Collection 2 -------"<<endl;
}

static void testCollection3()
{
    cout<<"------- Test Collection 3 -------"<<endl;
    Collection c1(0);
    c1.Ajouter(new TrajetSimple("Lyon0","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Lyon1","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Lyon2","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Lyon3","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Lyon4","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Lyon5","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Lyon6","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Lyon7","Paris",TRAIN));
    c1.GetTrajet(0)->Afficher();
    c1.GetTrajet(5)->Afficher();
    c1.GetTrajet(6)->Afficher();
    cout<<endl;
    c1.Afficher();
    cout<<"------- Fin Test Collection 3 -------"<<endl;
}

static void testCollection4()
{
    cout<<"------- Test Collection 4 -------"<<endl;
    Collection c1;
    cout<< "GetTrajet(0) :" << endl;
    c1.GetTrajet(0);
    cout<< "GetTrajet(5) :" << endl;
    c1.GetTrajet(5);
    cout<< "GetTrajet(10) :" <<endl;
    c1.GetTrajet(10);
    cout<< "GetLastTrajet() :" << endl;
    c1.GetLastTrajet();
    cout<< "EstVide() :" << c1.EstVide() << endl;
    cout<< "Affichage : ";
    c1.Afficher();
    cout<<"------- Fin Test Collection 4 -------"<<endl;
}


static void testCollection(){
    testCollection1();
    testCollection2();
    testCollection3();
    testCollection4();
}

//------- Test TrajetCompose -------
static void testTrajetCompose1()
{
    cout<<"------- Test TrajetCompose 1 -------"<<endl;
    Collection c1(5);
    c1.Ajouter(new TrajetSimple("Lyon","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Paris","Bordeaux",AUTO));
    c1.Ajouter(new TrajetSimple("Bordeaux","Brest",BATEAU));
    c1.Ajouter(new TrajetSimple("Brest","Londres",AVION));
    
    TrajetCompose tc(c1);
    cout << "depart = " << tc.GetDepart() << endl;
    cout << "arrivee = " << tc.GetArrivee() << endl;
    tc.Afficher();
    cout<<"------- Fin Test TrajetCompose 1 -------"<<endl;
}

static void testTrajetCompose2()
{
    cout<<"------- Test TrajetCompose 2 -------"<<endl;
    Collection c1;
    TrajetCompose tc(c1);
    cout << "depart = " << tc.GetDepart() << endl;
    cout << "arrivee = " << tc.GetArrivee() << endl;
    tc.Afficher();
    cout<<"------- Fin Test TrajetCompose 2 -------"<<endl;
}

static void testTrajetCompose()
{
    testTrajetCompose1();
    testTrajetCompose2();
}

//------- Test Catalogue -------
static void testCatalogue()
{
    Catalogue c;
    c.Afficher();
    
    
    c.Ajouter(new TrajetSimple("Lyon","Paris",TRAIN));
    c.Ajouter(new TrajetSimple("Paris","Bordeaux",AUTO));
    
    Collection c1(5);
    c1.Ajouter(new TrajetSimple("Lyon","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Paris","Bordeaux",AUTO));
    c1.Ajouter(new TrajetSimple("Bordeaux","Brest",BATEAU));
    c1.Ajouter(new TrajetSimple("Brest","Londres",AVION));
    Trajet* tc = new TrajetCompose(c1);
    
    c.Ajouter(tc);
    c.Ajouter(new TrajetSimple("Bordeaux","Brest",BATEAU));
    c.Ajouter(new TrajetSimple("Brest","Londres",AVION));
    c.Afficher();
}

//------- Test Recherche Simple -------
static void testRechercheSimple()
{
    Catalogue c;
    
    c.Ajouter(new TrajetSimple("Lyon","Paris",TRAIN));
    c.Ajouter(new TrajetSimple("Paris","Bordeaux",AUTO));
    
    Collection c1(5);
    c1.Ajouter(new TrajetSimple("Lyon","Paris",TRAIN));
    c1.Ajouter(new TrajetSimple("Paris","Bordeaux",AUTO));
    c1.Ajouter(new TrajetSimple("Bordeaux","Brest",BATEAU));
    c1.Ajouter(new TrajetSimple("Brest","Londres",AVION));
    Trajet* tc = new TrajetCompose(c1);
    c.Ajouter(tc);
    
    c.Ajouter(new TrajetSimple("Bordeaux","Brest",BATEAU));
    c.Ajouter(new TrajetSimple("Lyon","Londres",AVION));
    
    c.RechercheSimple("Lyon", "Bordeaux").Afficher();
    cout << endl;
    c.RechercheSimple("Lyon", "Londres").Afficher();
}

//------- Test Recherche Simple -------
static void testRechercheAvancee()
{
    Catalogue c;
    
    c.Ajouter(new TrajetSimple("A", "B", AUTO));
    c.Ajouter(new TrajetSimple("B", "C", AUTO));
    c.Ajouter(new TrajetSimple("C", "D", AUTO));
    c.Ajouter(new TrajetSimple("D", "E", AUTO));
    c.Ajouter(new TrajetSimple("E", "F", AUTO));
    c.Ajouter(new TrajetSimple("E", "A", AUTO));
    c.Ajouter(new TrajetSimple("C", "B", AUTO));
    c.Ajouter(new TrajetSimple("D", "B", AUTO));
    c.Ajouter(new TrajetSimple("B", "E", AUTO));
    c.Ajouter(new TrajetSimple("B", "D", AUTO));
    
    
    
    c.Afficher();
    c.RechercheAvancee("A", "F").AfficherAvance("F");
}

int main(){
    programmePrincipal();
    return 0;
}
