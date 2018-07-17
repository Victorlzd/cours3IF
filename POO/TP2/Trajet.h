//------- Interface de la classe <Trajet> (fichier Trajet.h) -------------
#if ! defined ( TRAJET_H )
#define TRAJET_H
//------------------------------------------------------------------------
// Rôle de la classe <Trajet>
//
//	La classe Trajet symbolise un trajet quelconque
//------------------------------------------------------------------------

class Trajet
{
//----------------------------------------------------------------- PUBLIC
    public:
//----------------------------------------------------- Méthodes publiques
        virtual char* GetDepart() const = 0;
        // renvoie le nom de la ville de depart
        
        virtual char* GetArrivee() const = 0;
        // renvoie le nom de la ville de depart
        
        virtual void Afficher() const = 0;
        // permet d’afficher en console les informations liées à l’objet.
        
        virtual Trajet* Copie() const = 0;
        // Renvoie un pointeur sur une copie distincte de ce trajet
        // Contrat :
        // Le pointeur retourné pointe sur un objet alloué dynamiquement
        // IL DOIT ETRE LIBERE PAR UN delete !!!
        
        virtual ~Trajet();
        // Destructeur de la classe

//-------------------------------------------------------------- PROTECTED
    protected:
//----------------------------------------------------- Méthodes protégées
        Trajet();
        // Constructeur de la classe
        
        Trajet(const Trajet & copie);
        // Constructeur de copie de la classe

};

#endif // TRAJET_H
