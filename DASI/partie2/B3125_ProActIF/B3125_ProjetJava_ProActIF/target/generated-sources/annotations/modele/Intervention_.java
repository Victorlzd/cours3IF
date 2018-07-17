package modele;

import java.util.Date;
import javax.annotation.Generated;
import javax.persistence.metamodel.SingularAttribute;
import javax.persistence.metamodel.StaticMetamodel;
import modele.Client;
import modele.Employe;

@Generated(value="EclipseLink-2.5.2.v20140319-rNA", date="2018-03-23T14:10:51")
@StaticMetamodel(Intervention.class)
public class Intervention_ { 

    public static volatile SingularAttribute<Intervention, Boolean> estFinie;
    public static volatile SingularAttribute<Intervention, Date> horodate;
    public static volatile SingularAttribute<Intervention, Employe> employe;
    public static volatile SingularAttribute<Intervention, Boolean> aucunSoucis;
    public static volatile SingularAttribute<Intervention, String> description;
    public static volatile SingularAttribute<Intervention, Client> client;
    public static volatile SingularAttribute<Intervention, Integer> id;
    public static volatile SingularAttribute<Intervention, Date> dateFin;
    public static volatile SingularAttribute<Intervention, String> commentaire;

}