#include "Posturometre.hpp"
#include <Arduino.h>

Posturometre::Posturometre(){
    //Implémentation du constructeur...
}

//Appel de méthode de façon implicite ce qui en appel d'autres venant d'autres classes

void Posturometre::viderMemoire(){
    memoire.vidageMemoire();
}

void Posturometre::stockerDonnees(){
    memoire.stockageDonnees();
}

void Posturometre::connexionServeur(){
    communication.connexion();
}

double Posturometre::acquisitionCharge(){
    charge.acquisitionMasseCharge();
}

int Posturometre::calculInclinaison(){
    inclinaison.calculInclinaison();
}
