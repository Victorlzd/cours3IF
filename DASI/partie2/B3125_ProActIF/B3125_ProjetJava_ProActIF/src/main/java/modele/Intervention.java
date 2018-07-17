/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package modele;

import java.io.Serializable;
import java.util.Date;
import javax.persistence.Entity;
import javax.persistence.GeneratedValue;
import javax.persistence.GenerationType;
import javax.persistence.Id;
import javax.persistence.Inheritance;
import javax.persistence.InheritanceType;
import javax.persistence.ManyToOne;
import javax.persistence.Table;
import javax.persistence.Temporal;
import javax.persistence.TemporalType;

/**
 *
 * @author AlexandreLang  
 */
@Entity
@Inheritance(strategy = InheritanceType.JOINED)
@Table(name = "Intervention")
public class Intervention implements Serializable {
    @Id
    @GeneratedValue(strategy = GenerationType.AUTO)
    protected Integer id;
    
    private String description;

    @Temporal(TemporalType.DATE)
    private Date horodate;
    
    private boolean estFinie = false;
    
    @ManyToOne(targetEntity = Client.class)
    private Client client;
    
    @ManyToOne(targetEntity = Employe.class)
    private Employe employe;
    
    @Temporal(TemporalType.TIMESTAMP)
    private Date dateFin;
    
    private String commentaire;
    
    private boolean aucunSoucis;
    
    public Intervention(String description) {
        this.description = description;
        this.client = null;
        this.horodate = new Date();
        this.commentaire = "";
    }
    
    public Intervention() {
        this.description = "";
        this.client = null;
        this.horodate = null;
        this.commentaire = "";
    }

    public boolean isEstFinie() {
        return estFinie;
    }

    public void setEstFinie(boolean estFinie) {
        this.estFinie = estFinie;
    }
    
    public Integer getId() {
        return id;
    }

    public void setId(Integer id) {
        this.id = id;
    }

    public String getDescription() {
        return description;
    }

    public void setDescription(String description) {
        this.description = description;
    }

    public Client getClient() {
        return client;
    }

    public void setClient(Client client) {
        this.client = client;
    }

    public Date getHorodate() {
        return horodate;
    }

    public void setHorodate(Date horodate) {
        this.horodate = horodate;
    }

    public Employe getEmploye() {
        return employe;
    }

    public void setEmploye(Employe employe) {
        this.employe = employe;
    }

    @Override
    public String toString() {
        return "Intervention{" + "id=" + id + ", description=" + description + ", horodate=" + horodate + ", estFinie=" + estFinie + ", idClient=" +client + ", idEmploye=" + employe + " Avec le commentaire final : "+ commentaire + '}';
    }

    public Date getDateFin() {
        return dateFin;
    }

    public void setDateFin(Date dateFin) {
        this.dateFin = dateFin;
    }

    public String getCommentaire() {
        return commentaire;
    }

    public void setCommentaire(String commentaire) {
        this.commentaire = commentaire;
    }

    public boolean isAucunSoucis() {
        return aucunSoucis;
    }

    public void setAucunSoucis(boolean aucunSoucis) {
        this.aucunSoucis = aucunSoucis;
    }
    
    
}
