package modele;

import java.util.Date;
import javax.annotation.Generated;
import javax.persistence.metamodel.SingularAttribute;
import javax.persistence.metamodel.StaticMetamodel;

@Generated(value="EclipseLink-2.5.2.v20140319-rNA", date="2018-03-23T14:10:51")
@StaticMetamodel(Employe.class)
public class Employe_ extends Personne_ {

    public static volatile SingularAttribute<Employe, Date> dispoFin;
    public static volatile SingularAttribute<Employe, Boolean> estEnIntervention;
    public static volatile SingularAttribute<Employe, Date> dispoDebut;

}