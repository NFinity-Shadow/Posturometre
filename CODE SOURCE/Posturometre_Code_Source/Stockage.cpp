#include "Masse.hpp"
#include "Inclinometre.hpp"
#include "Stockage.hpp"
#include <EEPROM.h>
#include <Arduino.h>

Stockage::Stockage(){
    //Implémentation du constructeur...
    emplacementMemoire = 0;
}

void Stockage::vidageMemoire(){
    //Implémentation de la fonction de remise à zéro de la mémoire...
    Serial.println("La mémoire se vide, patienter un instant... ");
    for(int i = 0; i < EEPROM.length(); i++){
        EEPROM.write(i, 0);
    }
}

void Stockage::stockageDonnees(){
    //Implémentation de la fonction de stockage des données dans la mémoire...
    while (emplacementMemoire != EEPROM.length()){
        donneesCharge = donneesCapteurMasse.acquisitionMasseCharge()*10.0;
        donneesIncliTangage = donneesCapteurIncliTangage.calculInclinaison();
        donneesIncliRoulis = donneesCapteurIncliRoulis.calculInclinaison();
        if(donneesCharge || donneesIncliTangage || donneesIncliRoulis >= 1){
          EEPROM.update(emplacementMemoire, donneesCharge);
          EEPROM.update(emplacementMemoire + 1, donneesIncliTangage);
          EEPROM.update(emplacementMemoire + 2, donneesIncliRoulis);
          emplacementMemoire = emplacementMemoire + 3; 
          delay(100);
        }
    } 
    Serial.println("Memoire pleine");
}
