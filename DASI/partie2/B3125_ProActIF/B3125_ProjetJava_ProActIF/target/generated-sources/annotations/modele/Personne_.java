package modele;

import java.util.Date;
import javax.annotation.Generated;
import javax.persistence.metamodel.SingularAttribute;
import javax.persistence.metamodel.StaticMetamodel;

@Generated(value="EclipseLink-2.5.2.v20140319-rNA", date="2018-03-23T14:10:51")
@StaticMetamodel(Personne.class)
public class Personne_ { 

    public static volatile SingularAttribute<Personne, String> ville;
    public static volatile SingularAttribute<Personne, String> rue;
    public static volatile SingularAttribute<Personne, String> numero;
    public static volatile SingularAttribute<Personne, String> mail;
    public static volatile SingularAttribute<Personne, Date> dateNaissance;
    public static volatile SingularAttribute<Personne, Double> lon;
    public static volatile SingularAttribute<Personne, String> nom;
    public static volatile SingularAttribute<Personne, String> mdp;
    public static volatile SingularAttribute<Personne, Integer> id;
    public static volatile SingularAttribute<Personne, String> prenom;
    public static volatile SingularAttribute<Personne, Double> lat;
    public static volatile SingularAttribute<Personne, String> civilite;
    public static volatile SingularAttribute<Personne, String> pays;

}