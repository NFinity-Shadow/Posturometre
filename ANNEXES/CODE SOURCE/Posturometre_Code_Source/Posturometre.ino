#include "Posturometre.hpp"
#include "string.h"
#include <Arduino.h> 

int reponse = 0;

Posturometre o_Posturometre;

void setup(){
    Serial.begin(115200);

    Serial.println("1.Récupération de donnees. ou 2.Transfert.");

    while(reponse == 0){
      if(Serial.available() > 0){
        reponse = Serial.read();
      }
      if(reponse == 49){
        o_Posturometre.viderMemoire();
        o_Posturometre.stockerDonnees();
      }else if (reponse == 50){
        delay(1000);
        o_Posturometre.connexionServeur();
      }else{
        reponse = 0; 
      }
   }
}

void loop(){

}
