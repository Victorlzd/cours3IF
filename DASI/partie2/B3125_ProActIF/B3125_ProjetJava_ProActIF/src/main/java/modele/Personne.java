package modele;

import java.io.Serializable;
import java.io.UnsupportedEncodingException;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Locale;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Inheritance;
import javax.persistence.InheritanceType;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;
import java.security.*;
import javax.xml.bind.*;
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author alang
 */

@Entity
@Inheritance(strategy = InheritanceType.JOINED)
@Table(name = "Personne")
public class Personne implements Serializable {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    protected Integer id;   

    private String civilite;
    
    private String nom;

    private String prenom;
    private String mdp;

    @Temporal(TemporalType.DATE)
    private Date dateNaissance;
    private String rue ="";
    private String ville="";
    private String pays;
    private String numero;
    private String mail;
    private Double lat,lon;

    
    public Personne(String civilite, String nom, String prenom, String mdp, int jour, int mois, int annee, String rue, String ville, String pays, String numero, String mail) {
        this.civilite = civilite;
        this.nom = nom;
        this.prenom = prenom;
       
        this.mdp = getEncryptedMdp(mdp);
        
        //Génération de la date
        String string = jour+"/"+mois+"/"+annee;
        DateFormat format = new SimpleDateFormat("dd/MM/yyyy", Locale.FRANCE);
        Date date = null;
        try {
            date = format.parse(string);
        } catch (ParseException ex) {
            Logger.getLogger(Personne.class.getName()).log(Level.SEVERE, null, ex);
        }
        this.dateNaissance = date;

        this.rue = rue;
        this.ville = ville;
        this.pays = pays;
        this.numero = numero;
        this.mail = mail;
        this.lat = 0.0;
        this.lon = 0.0;
    }
    
    public Personne() {
        this.civilite = "M.";
        this.nom = "X";
        this.prenom = "Y";
        this.mdp = getEncryptedMdp("passe");
        String string = "11/11/1996";
        DateFormat format = new SimpleDateFormat("dd/MM/yyyy", Locale.FRANCE);
        Date date=null;
        try {
            date = format.parse(string);
        } catch (ParseException ex) {
            Logger.getLogger(Personne.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        this.dateNaissance = date;
           
        this.rue = "Rue 1";
        this.ville = "Paris, 75000";
        this.pays = "France";
        this.numero = "0606060606";
        this.mail = "contact@insa-lyon.fr";
        this.lat = 0.0;
        this.lon = 0.0;
    }

    private String getEncryptedMdp(String mdp){
        String motDePasse=null;
        
        try {
            //Génération du Hash du mot de passe
            byte[] bytesOfMessage = mdp.getBytes("UTF-8");
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] bytesOfDigest = md.digest(bytesOfMessage);
            motDePasse = DatatypeConverter.printHexBinary(bytesOfDigest).toLowerCase();
        } catch (UnsupportedEncodingException ex) {
            Logger.getLogger(Personne.class.getName()).log(Level.SEVERE, null, ex);
        } catch (NoSuchAlgorithmException ex) {
            Logger.getLogger(Personne.class.getName()).log(Level.SEVERE, null, ex);
        }
        
        return motDePasse;
    }
    
    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getCivilite() {
        return civilite;
    }

    public void setCivilite(String civilite) {
        this.civilite = civilite;
    }

    public String getNom() {
        return nom;
    }

    public void setNom(String nom) {
        this.nom = nom;
    }

    public String getPrenom() {
        return prenom;
    }

    public void setPrenom(String prenom) {
        this.prenom = prenom;
    }

    public Date getDateNaissance() {
        return dateNaissance;
    }

    public void setDateNaissance(Date dateNaissance) {
        this.dateNaissance = dateNaissance;
    }

    public String getRue() {
        return rue;
    }

    public void setRue(String rue) {
        this.rue = rue;
    }

    public String getVille() {
        return ville;
    }

    public void setVille(String ville) {
        this.ville = ville;
    }

    public String getPays() {
        return pays;
    }

    public void setPays(String pays) {
        this.pays = pays;
    }

    public String getNumero() {
        return numero;
    }

    public void setNumero(String numero) {
        this.numero = numero;
    }

    public String getMail() {
        return mail;
    }

    public void setMail(String mail) {
        this.mail = mail;
    }
    
    public String getMdp() {
        return mdp;
    }

    public void setMdp(String mdp) throws UnsupportedEncodingException, NoSuchAlgorithmException {
        this.mdp = getEncryptedMdp(mdp);
    }

    public Double getLat() {
        return lat;
    }

    public void setLat(Double lat) {
        this.lat = lat;
    }
    
    public Double getLon() {
        return lon;
    }

    public void setLon(Double lon) {
        this.lon = lon;
    }
    
    @Override
    public String toString() {
        return "Personne{" + "id=" + id + ", civilite=" + civilite + ", nom=" + nom + ", prenom=" + prenom + ", dateNaissance=" + dateNaissance + ", rue=" + rue + ", ville=" + ville + ", pays=" + pays + ", numero=" + numero + ", mail=" + mail + '}';
    }

    

}