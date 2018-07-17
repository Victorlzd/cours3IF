/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.util.ArrayList;
import java.util.List;
import javax.persistence.Query;
import modele.Client;
import modele.Employe;
import modele.Personne;

/**
 *
 * @author AlexandreLang
 */
public class PersonneDAO {
    
    public static Personne creerPersonne(Personne c) throws Exception {
        try {
            JpaUtil.obtenirEntityManager().persist(c);
            return c;
        } catch(Exception e) {
            throw new Exception("Erreur rencontrée lors de l'enregistrement d'une personne");
        }
    }

    public static Client getClientFromEmail(String email) throws Exception {
        Query query = JpaUtil.obtenirEntityManager().createQuery("SELECT p FROM Client p WHERE p.mail = :mail");
        query.setParameter("mail", email);
        List<Client> multipleClient = (List<Client>) query.getResultList(); 
        if(multipleClient.size() == 1){
            return multipleClient.get(0);
        }else{
            throw new Exception("Ce client n'existe pas !");
        }
    }
    
    public static Employe getEmployeFromEmail(String email) throws Exception {
        Query query = JpaUtil.obtenirEntityManager().createQuery("SELECT p FROM Employe p WHERE p.mail = :mail");
        query.setParameter("mail", email);
        List<Employe> multipleEmploye = (List<Employe>) query.getResultList(); 
        if(multipleEmploye.size() == 1){
            return multipleEmploye.get(0);
        }else{
            throw new Exception("Cet employé n'existe pas !");
        }
    }
    
    public static List<Client> getAllClient() {
        Query query = JpaUtil.obtenirEntityManager().createQuery("Select p From Client p");
        return (List<Client>) query.getResultList();
    }
    
    
    public static List<Employe> getAllEmployeDispo() {
        List<Employe> listEmp = new ArrayList<>();
        Query query = JpaUtil.obtenirEntityManager().createQuery("Select p From Employe p WHERE p.estEnIntervention = 0");
        listEmp.addAll((List<Employe>) query.getResultList());
        return listEmp;
    }
    
    public static Employe updateEtatDispoEmploye(Employe e){
        return JpaUtil.obtenirEntityManager().merge(e);
    }
    
    public Personne updateInfosPersonne(Personne p) {
        return JpaUtil.obtenirEntityManager().merge(p);
    }
}
