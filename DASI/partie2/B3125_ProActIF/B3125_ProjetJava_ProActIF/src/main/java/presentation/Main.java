package presentation;


import dao.JpaUtil;
import java.io.UnsupportedEncodingException;
import java.security.NoSuchAlgorithmException;
import java.text.ParseException;
import java.util.ArrayList;
import java.util.Date;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import modele.Animal;
import modele.Client;
import modele.Employe;
import modele.Incident;
import modele.Intervention;
import modele.Livraison;
import service.Service;
import util.Saisie;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author alang
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        JpaUtil.init();
        
        //Instanciation de la classe Service
        Service s = new Service();
        
        System.out.println("------------------------------------------------------------------------");
        System.out.println("--------------------Bienvenue dans ProAct'IF----------------------------");
        System.out.println("Interface destinée à la présentation de la partie 1\n");
        
        int resMain = 1;
        
        while(resMain != 3){

            System.out.println("Que voulez-vous faire ?");
            System.out.println("Tapez 1 pour accéder au côté client");
            System.out.println("Tapez 2 pour accéder au côté employé");
            System.out.println("Tapez 3 pour quitter l'application");

            resMain = Saisie.lireInteger("");

            if(resMain == 1){ //interface client
                System.out.println("---------------------------Côté client----------------------------------");
         
                int sortirMainClient = 0;
                while(sortirMainClient != 3){
                    System.out.println("  Que voulez-vous faire ?");
                    System.out.println("  Tapez 1 pour vous inscrire");
                    System.out.println("  Tapez 2 pour vous connecter");
                    System.out.println("  Tapez 3 pour revenir en arrière");

                    sortirMainClient = Saisie.lireInteger("  ");

                    if(sortirMainClient == 1){ //inscriptionç
                        Client c = new Client("M.", "MANTHE", "Matthis","passe", 07,01,1975, "32 Rue Wilhelmine", "Villeurbanne", "France", "0590232772", "matthis.manthe@insa-lyon.fr");
                        Client c2 = new Client("M.", "LANG", "Alexandre","passe", 07,01,1975, "1 Rue Wilhelmine", "Villeurbanne", "France", "0590232772", "alexandre.lang@insa-lyon.fr");

                        System.out.println("    [Instruction]Couper Internet !");
                        Saisie.lireChaine("    Saisir Ok quand Internet est coupé : ");

                        try {
                            s.inscriptionClient(c);
                        } catch (Exception ex) {
                            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                        }

                        System.out.println("    [Instruction]Remettre Internet !");
                        Saisie.lireChaine("    Saisir Ok quand Internet est opérationnel : ");

                        try {
                            s.inscriptionClient(c2);
                        } catch (Exception ex) {
                            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                        }
                    }else {
                        if(sortirMainClient == 2) {//Connexion
                            Client actual = null;
                            int recommencerConnexion = 1;
                            while(recommencerConnexion == 1){

                                String email = Saisie.lireChaine("    Saisir votre adresse mail : ");
                                String mdp = Saisie.lireChaine("    Saisir votre mot de passe : ");
                            
                                try {
                                    actual = s.connexionClient(email, mdp);
                                    System.out.println("Bienvenue Client "+actual.getPrenom()+" "+actual.getNom());
                                    recommencerConnexion = 2;
                                } catch (Exception ex) {
                                    Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                                }
                            }
                            
                            //Le client est connecté 
                            int clientCo = 1;
                            while(clientCo !=3) {
                                System.out.println("      Que voulez-vous faire ?");
                                System.out.println("      Tapez 1 pour afficher l'ensemble de votre historique des interventions");
                                System.out.println("      Tapez 2 pour ajouter une nouvelle intervention");
                                System.out.println("      Tapez 3 pour revenir en arrière");
                                clientCo = Saisie.lireInteger("      ");
                                
                                if(clientCo == 1) {//Historique
                                    List<Intervention> listInter = s.getHistoriqueClient(actual);
                                    if(listInter.isEmpty()){
                                        System.out.println("Aucune intervention enregistrée");
                                    }else {
                                        for(int i=0;i<listInter.size();i++) {
                                            System.out.println(listInter.get(i));
                                        }
                                    }
                                }else{
                                    if(clientCo == 2){//Ajouter une nouvelle intervention
                                        String typeInter = Saisie.lireChaine("      Type de l'intervention : ");
                                        String description = Saisie.lireChaine("      Description de l'intervention : ");
                                      
                                        Intervention newInter = null;
                                        
                                        if(typeInter.equals("Animal") || typeInter.equals("animal")) {
                                           String animal = Saisie.lireChaine("      Animal : "); 
                                           newInter = new Animal(description,animal);
                                        }
                                        if(typeInter.equals("Livraison") || typeInter.equals("livraison")) {
                                            String objet = Saisie.lireChaine("      Objet : "); 
                                            String entreprise = Saisie.lireChaine("      Entreprise : "); 
                                            newInter = new Livraison(description,objet,entreprise);
                                        }
                                        if(typeInter.equals("Incident") || typeInter.equals("incident")) {
                                            newInter = new Incident(description);
                                        }
                                        
                                        try {
                                            s.ajouterUneIntervention(newInter, actual);
                                        } catch (Exception ex) {
                                            Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                                        }
                                    }else{
                                        clientCo = 3;
                                    }
                                }
                            }
                        }else{
                            sortirMainClient = 3;
                           
                        }
                    }
                }
            }else{
                if(resMain == 2){ //interface employé
                    System.out.println("--------------------------Côté employé----------------------------------");
         
                    int sortirMainEmploye = 0;
                    while(sortirMainEmploye != 3){
                        System.out.println("  Que voulez-vous faire ?");
                        System.out.println("  Tapez 1 pour inscrire des employés");
                        System.out.println("  Tapez 2 pour vous connecter");
                        System.out.println("  Tapez 3 pour revenir en arrière");

                        sortirMainEmploye = Saisie.lireInteger("  ");

                        if(sortirMainEmploye == 1){ //inscription
                            Employe e = new Employe("Mme", "E1", "E1","passe", 07,01,1975, "203 Avenue Du général De gaulle", "Draguignan", "France", "0590232772", "draguignan@insa-lyon.fr",7,30,23,40);
                            try {
                                s.inscriptionEmploye(e);
                            } catch (Exception ex) {
                                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                            }

                            e = new Employe("M.", "E2", "E2","passe", 07,01,1975, "8 Rue Wilhelmine", "Lyon", "France", "0590232772", "lyon@insa-lyon.fr",7,30,23,40);
                            try {
                                s.inscriptionEmploye(e);
                            } catch (Exception ex) {
                                Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                            }
                        }else {
                            if(sortirMainEmploye == 2) {//Connexion
                                Employe actual = null;
                                int recommencerConnexion = 1;
                                while(recommencerConnexion == 1){

                                    String email = Saisie.lireChaine("    Saisir votre adresse mail : ");
                                    String mdp = Saisie.lireChaine("    Saisir votre mot de passe : ");

                                    try {
                                        actual = s.connexionEmploye(email, mdp);
                                        System.out.println("Bienvenue Employé "+actual.getPrenom()+" "+actual.getNom());
                                        recommencerConnexion = 2;
                                    } catch (Exception ex) {
                                        Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                                    }
                                }

                                //L'employé est connecté 
                                int clientCo = 1;
                                while(clientCo !=4) {
                                    System.out.println("      Que voulez-vous faire ?");
                                    System.out.println("      Tapez 1 pour afficher l'historique de vos interventions du jour");
                                    System.out.println("      Tapez 2 pour consulter le tableau avec l'ensemble des interventions du jour");
                                    System.out.println("      Tapez 3 pour terminer une intervention");
                                    System.out.println("      Tapez 4 pour revenir en arrière");
                                    clientCo = Saisie.lireInteger("      ");

                                    if(clientCo == 1) {//Historique
                                        List<Intervention> listInter = s.getHistoriqueEmploye(actual);
                                        if(listInter.isEmpty()){
                                            System.out.println("Aucune intervention enregistrée");
                                        }else {
                                            for(int i=0;i<listInter.size();i++) {
                                                System.out.println(listInter.get(i));
                                            }
                                        }
                                    }else{
                                        if(clientCo == 2){//Consulter le tableau de bord
                                            List<Intervention> listInter = s.getHistoriqueAllInterventionDuJour();
                                            if(listInter.isEmpty()){
                                                System.out.println("Aucune intervention enregistrée");
                                            }else {
                                                for(int i=0;i<listInter.size();i++) {
                                                    System.out.println(listInter.get(i));
                                                }
                                            }
                                        }else{
                                            if(clientCo == 3) {//Terminer une intervention
                                           
                                                List<Intervention> listInter = s.getHistoriqueEmploye(actual);
                         
                                                String commentaire = Saisie.lireChaine("Laissez un commentaire ? : ");
                                                String res = Saisie.lireChaine("Tout s'est bien passé (Oui/Non) ? : ");
                                                   boolean etatF;
                                                if(res.equals("Oui")){
                                                    etatF = true;
                                                }else{
                                                    etatF = false;
                                                }
                                                
                                                if(commentaire.equals("")) {
                                                    try {
                                                        s.terminerIntervention(listInter.get(0), etatF, new Date());
                                                    } catch (Exception ex) {
                                                        Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                                                    }
                                                }else {
                                                    try {
                                                        s.terminerIntervention(listInter.get(0), etatF, new Date(),commentaire);
                                                    } catch (Exception ex) {
                                                        Logger.getLogger(Main.class.getName()).log(Level.SEVERE, null, ex);
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }else{
                              
                            }
                        }
                    } 
                    
                }else{//Retour en arrière

                }
            }
        }

    }
    
}
