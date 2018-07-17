/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package modele;

import java.util.ArrayList;
import java.util.Calendar;
import java.util.Date;
import java.util.List;
import javax.persistence.CascadeType;
import javax.persistence.ElementCollection;
import javax.persistence.Entity;
import javax.persistence.JoinColumn;
import javax.persistence.OneToMany;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

/**
 *
 * @author AlexandreLang
 */
@Entity
@Table(name = "Employe")
public class Employe extends Personne {
    private boolean estEnIntervention = false;
    @Temporal(TemporalType.TIMESTAMP)
    private Date dispoDebut;
    @Temporal(TemporalType.TIMESTAMP)
    private Date dispoFin;
    
    public Employe(String civilite, String nom, String prenom,String mdp, int jour, int mois,int annee, String rue, String ville, String pays, String numero, String mail,int heureD,int minuteD,int heureF,int minuteF) {
        super(civilite, nom, prenom,mdp, jour,mois,annee, rue, ville, pays, numero, mail);
        
        Calendar dateD = Calendar.getInstance();
        dateD.set(Calendar.MINUTE,minuteD);
        dateD.set(Calendar.HOUR_OF_DAY,heureD);
        this.dispoDebut = dateD.getTime();
        
        Calendar dateF = Calendar.getInstance();
        dateF.set(Calendar.MINUTE,minuteF);
        dateF.set(Calendar.HOUR_OF_DAY,heureF);
        this.dispoFin = dateF.getTime();
    }

    public Employe(){
        super();
    }

    public boolean isEstEnIntervention() {
        return estEnIntervention;
    }

    public void setEstEnIntervention(boolean estEnIntervention) {
        this.estEnIntervention = estEnIntervention;
    }

    public Date getDispoDebut() {
        return dispoDebut;
    }

    public void setDispoDebut(Date dispoDebut) {
        this.dispoDebut = dispoDebut;
    }

    public Date getDispoFin() {
        return dispoFin;
    }

    public void setDispoFin(Date dispoFin) {
        this.dispoFin = dispoFin;
    }

    @Override
    public String toString() {
        return super.toString()+" estEnIntervention=" + estEnIntervention + ", dispoDebut=" + dispoDebut + ", dispoFin=" + dispoFin + '}';
    }
    
    
}
