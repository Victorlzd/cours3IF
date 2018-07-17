/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package modele;

import java.util.Date;
import javax.persistence.Entity;
import javax.persistence.Table;

/**
 *
 * @author AlexandreLang
 */
@Entity
@Table(name = "Livraison")
public class Livraison extends Intervention {
    private String objet;
    private String entreprise;
    
    public Livraison(String description, String objet,String entreprise){
        super(description);
        this.objet = objet;
        this.entreprise = entreprise;
    }
    
    public Livraison() {
        super();
        this.objet = "";
        this.entreprise = "";
    }
}
