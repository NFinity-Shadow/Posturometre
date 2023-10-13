#include <EEPROM.h>
#include <MySQL_Connection.h>
#include <MySQL_Cursor.h>
#include <MySQL_Encrypt_Sha1.h>
#include <MySQL_Packet.h>
#include <Arduino.h>
#include "Ethernet.h"
#include "SPI.h"
#include "LiaisonEthernet.hpp"
#include "Masse.hpp"
#include "Inclinometre.hpp"

LiaisonEthernet::LiaisonEthernet(){
    //Implémentation du constructeur:
    byte adresseMAC[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
    IPAddress ipArduino(192,168,1,4);
    portServeur = 3306;
}

void LiaisonEthernet::connexion(){
    //Implémentation de la fonction de vérification de la connexion :
    byte adresseMAC[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
    IPAddress ipArduino(192,168,1,4);
    IPAddress ipServeur(192,168,1,186);
    Ethernet.begin(adresseMAC, ipArduino);
    
    MySQL_Connection connexion((Client *) &client);
    MySQL_Cursor * cur_mem = new MySQL_Cursor(&connexion); //Gestion de la véracité de la trame lors de l'envoie des données 

    char donneesCapteurMasse [10];
    char requete[128];

    char utilisateur[] = "admincharge";
    char mot_de_passe[] = "Admincharge";

    char INSERT_SQL[] = "INSERT INTO statistique.charge (id_capteur, masseCharge, dateCharge, utilisateur_id) VALUES ('1',%s,NOW(),'2')"; //Requête permettant l'inclusion de données dans la base de données
    
    if(connexion.connect(ipServeur, portServeur, utilisateur, mot_de_passe)){
        Serial.println("Connexion reussie.");
        delay(1000);
     }else{                                    //Si la connexion n'aboutie pas alors on ferme le flux
        Serial.println("Connexion echouee.");
        connexion.close();

     }
     
    for (int i = 0; i < EEPROM.length(); i++){
      donneesEEPROM = EEPROM.read(i)/10.0;
      dtostrf(donneesEEPROM, 5, 1, donneesCapteurMasse);  //Conversion d'un double en string par la fonction dtostrf
      sprintf(requete, INSERT_SQL, donneesCapteurMasse); //Écriture de la chaine de caractère créée précédement dans la requête SQL

      Serial.println(requete);
      delay(500);
      cur_mem->execute(requete);
    }
}
