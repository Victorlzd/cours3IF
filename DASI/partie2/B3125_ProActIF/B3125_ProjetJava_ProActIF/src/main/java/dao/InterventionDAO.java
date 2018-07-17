/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package dao;

import java.time.LocalDateTime;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import javax.persistence.Query;
import modele.Client;
import modele.Employe;
import modele.Incident;
import modele.Intervention;

/**
 *
 * @author AlexandreLang
 */
public class InterventionDAO {
    public static boolean creerIntervention(Intervention e) {
        try {
            JpaUtil.obtenirEntityManager().persist(e);
            return true;
        } catch(Exception r) {
            return false;
        }
        
    }
    
    public static Intervention updateIntervention(Intervention inter){
        return JpaUtil.obtenirEntityManager().merge(inter);
    }
        
    public static List<Intervention> getHistoriqueClient(Client cli) {
        Query query = JpaUtil.obtenirEntityManager().createQuery("Select p From Intervention p WHERE p.client = :cli");
        query.setParameter("cli", cli);
        return (List<Intervention>) query.getResultList();
    }
    
    public static List<Intervention> getHistoriqueEmploye(Employe emp) {
        Query query = JpaUtil.obtenirEntityManager().createQuery("Select p From Intervention p WHERE p.employe = :emp AND p.horodate = CURRENT_DATE");
        query.setParameter("emp", emp);
    
        return (List<Intervention>) query.getResultList();
    }
    
    public static List<Intervention> getHistoriqueAllInterventionDuJour() {
        Query query = JpaUtil.obtenirEntityManager().createQuery("Select p From Intervention p WHERE p.horodate = CURRENT_DATE");
    
        return (List<Intervention>) query.getResultList();
    }
    
}
