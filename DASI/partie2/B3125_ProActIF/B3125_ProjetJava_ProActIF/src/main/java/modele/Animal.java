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
@Table(name = "Animal")
public class Animal extends Intervention {
    private String animal;
    
    public Animal(String description, String animal){
        super(description);
        this.animal = animal;
    }
     
    public Animal(){
        super();
        this.animal = "";
    }

    public String getAnimal() {
        return animal;
    }

    public void setAnimal(String animal) {
        this.animal = animal;
    }
 
}
