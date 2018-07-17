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
@Table(name = "Incident")
public class Incident extends Intervention {

    public Incident(String description) {
        super(description);
    }
    
    public Incident(){
        super();
    }
    
    
}
