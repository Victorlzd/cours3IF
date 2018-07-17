/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package modele;

import java.io.UnsupportedEncodingException;
import java.security.NoSuchAlgorithmException;
import java.text.ParseException;
import java.util.Date;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Table;

/**
 *
 * @author AlexandreLang
 */
@Entity
@Table(name = "Client")
public class Client extends Personne {
    
    public Client(String civilite, String nom, String prenom,String mdp, int jour, int mois,int annee, String rue, String ville, String pays, String numero, String mail) {
        super(civilite, nom, prenom,mdp, jour,mois,annee, rue, ville, pays, numero, mail);
    }

    public Client(){
        super();
    }

    @Override
    public String toString() {
        return super.toString();
    }
    
    
}
