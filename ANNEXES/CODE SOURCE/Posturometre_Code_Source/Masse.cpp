#include "Arduino.h"
#include "Masse.hpp"

Masse::Masse(){
    brocheCapteurDroite = 0;
    brocheCapteurGauche = 1;
    surface = 5.3; //Surface sur laquelle s'appuie la masse de la charge
}

double Masse::acquisitionMasseCharge(){

    pressionCapteurDroite = analogRead(brocheCapteurDroite);
    pressionCapteurGauche = analogRead(brocheCapteurGauche);

    pression = ((pressionCapteurDroite + pressionCapteurGauche) - 342.00)/10;

    Serial.print(pression);
    Serial.print("\t");

    masse = (pression * surface)/ 9,81; //Formule de la masse à l'aide d'une pression en N/m^2 

    Serial.println(masse/2);

    return masse/2;
}
