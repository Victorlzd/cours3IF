/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package service;

import com.google.maps.model.LatLng;
import dao.JpaUtil;
import dao.InterventionDAO;
import dao.PersonneDAO;
import java.io.UnsupportedEncodingException;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Date;
import modele.Personne;
import java.util.List;
import javax.xml.bind.DatatypeConverter;
import modele.Client;
import java.security.*;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.Calendar;
import java.util.HashMap;
import java.util.Map;
import java.util.TreeMap;
import javax.xml.bind.*;
import modele.Employe;
import modele.Incident;
import modele.Intervention;
import static util.GeoTest.getLatLng;
import static util.GeoTest.getTripDurationByBicycleInMinute;

/**
 *
 * @author alang
 */
public class Service {

    public Service() {
    }
    
    /**
     * Méthode appelée quand le client a finalisé son inscription
     */
    
    public Client inscriptionClient(Client newClient) throws Exception {
        String mailAEnvoyer = "Expéditeur : contact@proactif.if\n"+
                "Pour : "+newClient.getMail()+"\n"+
                "Sujet : Bienvenue chez PROACT'IF\n\n"+
                "Corps :\n"+
                "Bonjour "+newClient.getNom()+",\n";
                
        try{
            JpaUtil.creerEntityManager();
            JpaUtil.ouvrirTransaction();

            //On récupère les coordonnées du client
            getCoordsOfPersonne(newClient);

            Client newCli = (Client)PersonneDAO.creerPersonne(newClient);      
            JpaUtil.validerTransaction();
            JpaUtil.fermerEntityManager();
            
            //L'inscription a pu être effectuée donc on envoie un mal au nouveau client
            mailAEnvoyer+="Nous vous confirmons que votre inscription au service PROACT'IF. Votre numéro de client est : "+newClient.getId()+".\n";
            System.out.println(mailAEnvoyer);
            
            return newCli;
        }catch(Exception e){
            //Si le persist n'a pas pu être fait
            mailAEnvoyer+="Votre inscription au service PROACT'IF a malencontreusement échoué... Merci de recommencer utérieurement.";
            System.out.println(mailAEnvoyer);
            JpaUtil.annulerTransaction();
            JpaUtil.fermerEntityManager();
            throw new Exception("Erreur rencontrée lors de l'enregistrement d'un client");
        }
    }
    
    public Client envoyerANouveauMailConfirmation(Client newClient) throws Exception {
        String mailAEnvoyer = "Expéditeur : contact@proactif.if\n"+
                "Pour : "+newClient.getMail()+"\n"+
                "Sujet : Bienvenue chez PROACT'IF\n\n"+
                "Corps :\n"+
                "Bonjour "+newClient.getNom()+",\n";
        mailAEnvoyer+="Nous vous confirmons que votre inscription au service PROACT'IF. Votre numéro de client est : "+newClient.getId()+".\n";
        System.out.println(mailAEnvoyer);
        return newClient;
    }
    
    /**
     * 
     */
    public Employe inscriptionEmploye(Employe newEmploye) throws Exception{
        try {
            JpaUtil.creerEntityManager();
            JpaUtil.ouvrirTransaction();

            getCoordsOfPersonne(newEmploye);
            
            Employe newEmp = (Employe)PersonneDAO.creerPersonne(newEmploye);      
            JpaUtil.validerTransaction();
            JpaUtil.fermerEntityManager();
            
            return newEmp;
        }catch(Exception e) {
            JpaUtil.annulerTransaction();
            JpaUtil.fermerEntityManager();
            throw new Exception("Erreur rencontrée lors de l'enregistrement d'un employé");
        }
    }
    
    /**
    * Méthode appelée quand le client souhaite se connecter à son compte
    **/
    
    public Client connexionClient(String email,String mdp) throws Exception {
        JpaUtil.creerEntityManager();
        JpaUtil.ouvrirTransaction();
       
        Client c = PersonneDAO.getClientFromEmail(email);
        
        JpaUtil.fermerEntityManager();
        //Si le client existe on vérifie le mot de passe donné sur l'interface graphique
        //Génération du Hash du mot de passe
        byte[] bytesOfMessage = mdp.getBytes("UTF-8");
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] bytesOfDigest = md.digest(bytesOfMessage);
            String encryptedMdp = DatatypeConverter.printHexBinary(bytesOfDigest).toLowerCase();
            //Si le mot de passe est le même on retourne l'objet client récupéré
            if(encryptedMdp.equals(c.getMdp())){
                return c;
            }else{
                throw new Exception("Le mot de passe est incorrect !");
            }

    }
    
    public Employe connexionEmploye(String email,String mdp) throws Exception {
        JpaUtil.creerEntityManager();
        JpaUtil.ouvrirTransaction();
       
        Employe c = PersonneDAO.getEmployeFromEmail(email);
        
        JpaUtil.fermerEntityManager();
        //Si l'employé existe on vérifie le mot de passe donné sur l'interface graphique
        //Génération du Hash du mot de passe
        byte[] bytesOfMessage = mdp.getBytes("UTF-8");
            MessageDigest md = MessageDigest.getInstance("MD5");
            byte[] bytesOfDigest = md.digest(bytesOfMessage);
            String encryptedMdp = DatatypeConverter.printHexBinary(bytesOfDigest).toLowerCase();
            //Si le mot de passe est le même on retourne l'objet employe récupéré
            if(encryptedMdp.equals(c.getMdp())){
                return c;
            }else{
                throw new Exception("Le mot de passe est incorrect !");
            }
    }
        
   /**
    * Lorsque l'on crée une intervention
    **/
    public Intervention ajouterUneIntervention(Intervention inter,Client client) throws Exception{
        try{
            inter.setClient(client);

            JpaUtil.creerEntityManager();
            JpaUtil.ouvrirTransaction();

            //On cherche maintenant, parmi la liste des employés, ceux qui peuvent réaliser l'intervention
            ArrayList<Employe> allEmploye = (ArrayList<Employe>) PersonneDAO.getAllEmployeDispo();

            //On enlève tous les employés qui ne sont pas dispo sur cette heure
            Calendar calInter = Calendar.getInstance();
            calInter.set(Calendar.HOUR_OF_DAY, inter.getHorodate().getHours());
            calInter.set(Calendar.MINUTE, inter.getHorodate().getMinutes());
            calInter.set(Calendar.SECOND, inter.getHorodate().getSeconds());     

            ArrayList<Employe> employeDispos = new ArrayList<>();

            for(Employe emp : allEmploye) {
                Calendar calDeb = Calendar.getInstance();
                calDeb.set(Calendar.HOUR_OF_DAY, emp.getDispoDebut().getHours());
                calDeb.set(Calendar.MINUTE, emp.getDispoDebut().getMinutes());
                calDeb.set(Calendar.SECOND, emp.getDispoDebut().getSeconds());

                Calendar calFin = Calendar.getInstance();
                calFin.set(Calendar.HOUR_OF_DAY, emp.getDispoFin().getHours());
                calFin.set(Calendar.MINUTE, emp.getDispoFin().getMinutes());
                calFin.set(Calendar.SECOND, emp.getDispoFin().getSeconds());

                if(calDeb.before(calInter) && calFin.after(calInter)){
                    employeDispos.add(emp);
                }
            }

            //On calcule ensuite la distance des employés restants avec l'@ du client
            String adresseInter = client.getRue()+", "+client.getVille();
            LatLng coordsInter = getLatLng(adresseInter);

            HashMap<Double,Employe> employeDistance = new HashMap<>();

            for(Employe emp : employeDispos){
                String adresseEmp = emp.getRue()+", "+emp.getVille();
                LatLng coordsEmp = getLatLng(adresseEmp);

                Double duree = getTripDurationByBicycleInMinute(coordsEmp, coordsInter);

                employeDistance.put(duree,emp);
            }

            //On trie la Map en fonction de la distance
            Map<Double, Employe> map = new TreeMap<>(employeDistance);

            //On garde uniquement le 1er employé
            if(map.isEmpty()) {
                JpaUtil.validerTransaction();
                JpaUtil.fermerEntityManager();
                throw new Exception("Il n'y a aucun employé disponible !");
            }else{
                 Map.Entry<Double,Employe> entry = map.entrySet().iterator().next();
                 Double key= entry.getKey();
                 Employe value=entry.getValue();
                 value.setEstEnIntervention(true);
                 inter.setEmploye(value);

                 InterventionDAO.creerIntervention(inter);

                 //On dit alors que cet employé n'est plus disponible pour le moment
                 PersonneDAO.updateEtatDispoEmploye(value);

                 //On envoie la notification à l'employé
                 System.out.println("Intervention "+inter.getClass().getSimpleName().toString()+" demandée le "+inter.getHorodate().toString()+" pour "+client.getPrenom()+" "+client.getNom()+" (#"+client.getId()+"), "+client.getRue()+", "+client.getVille()+" ("+key+"km) : "+inter.getDescription());

                JpaUtil.validerTransaction();
                JpaUtil.fermerEntityManager();

                return inter;
            }
        }catch(Exception ex){
            JpaUtil.annulerTransaction();
            JpaUtil.fermerEntityManager();
            throw new Exception("Erreur rencontrée lors de l'ajout d'une intervention");
        }
        
    }
     
    public Intervention terminerIntervention(Intervention inter, boolean aucunProbleme,Date dateFin, String commentaire) throws Exception {
        try{
            JpaUtil.creerEntityManager();
            JpaUtil.ouvrirTransaction();

            inter.getEmploye().setEstEnIntervention(false);
            inter.setCommentaire(commentaire);
            inter.setDateFin(dateFin);
            inter.setAucunSoucis(aucunProbleme);
            inter.setEstFinie(true);

            PersonneDAO.updateEtatDispoEmploye(inter.getEmploye());
            Intervention newInter = InterventionDAO.updateIntervention(inter);

            JpaUtil.validerTransaction();
            JpaUtil.fermerEntityManager(); 

            System.out.println("Cher "+inter.getClient().getPrenom()+" "+inter.getClient().getNom() + ", l'intervention que vous aviez demandée vient de se terminer.");
            System.out.println("L'employé en charge de l'intervention vous a laissé un message : "+commentaire);
            System.out.println("L'application ProAct'IF vous remercie pour votre confiance ! A très bientôt !");
            
            return newInter;
        }catch(Exception e){
            JpaUtil.annulerTransaction();
            JpaUtil.fermerEntityManager();
            throw new Exception("Erreur rencontrée lors de la terminaison d'une intervention");
        }
    }
    
    public Intervention terminerIntervention(Intervention inter, boolean aucunProbleme,Date dateFin) throws Exception {
        try {
        JpaUtil.creerEntityManager();
        JpaUtil.ouvrirTransaction();
        
        inter.getEmploye().setEstEnIntervention(false);
        inter.setDateFin(dateFin);
        inter.setAucunSoucis(aucunProbleme);
        inter.setEstFinie(true);
        
        PersonneDAO.updateEtatDispoEmploye(inter.getEmploye());
        Intervention newInter = InterventionDAO.updateIntervention(inter);
        
        JpaUtil.validerTransaction();
        JpaUtil.fermerEntityManager(); 
        
        System.out.println("Cher "+inter.getClient().getPrenom()+" "+inter.getClient().getNom() + ", l'intervention que vous aviez demandée vient de se terminer.");
        System.out.println("L'application ProAct'IF vous remercie pour votre confiance ! A très bientôt !");
            
        return newInter;
        }catch(Exception e){
            JpaUtil.annulerTransaction();
            JpaUtil.fermerEntityManager();
            throw new Exception("Erreur rencontrée lors de la terminaison d'une intervention");
        }
    }
        
    public List<Intervention> getHistoriqueClient(Client cli){
        JpaUtil.creerEntityManager();
        JpaUtil.ouvrirTransaction();
        
        List<Intervention> listeInter = InterventionDAO.getHistoriqueClient(cli);
        
        JpaUtil.fermerEntityManager(); 
        return listeInter;
    }
    
    public List<Intervention> getHistoriqueEmploye(Employe emp){
        JpaUtil.creerEntityManager();
        JpaUtil.ouvrirTransaction();
        
        List<Intervention> listeInter = InterventionDAO.getHistoriqueEmploye(emp);
        
        JpaUtil.fermerEntityManager(); 
        return listeInter;
    }
    
    public List<Intervention> getHistoriqueAllInterventionDuJour(){
        JpaUtil.creerEntityManager();
        JpaUtil.ouvrirTransaction();
        
        List<Intervention> listeInter = InterventionDAO.getHistoriqueAllInterventionDuJour();
        
        JpaUtil.fermerEntityManager(); 
        return listeInter;
    }
    
    private void getCoordsOfPersonne(Personne perso) {
        LatLng coords = getLatLng(perso.getRue()+", "+perso.getVille());
        perso.setLat(coords.lat);
        perso.setLon(coords.lng);
    }
}