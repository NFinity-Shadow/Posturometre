/*---== Biblitothèques ==---*/
#include <Wire.h>
#include <math.h>
#include "Inclinometre.hpp"
#include "Arduino.h"
/*---====================---*/


    Inclinometre::Inclinometre(){}; // Constructeur par défaut
 
   
    int Inclinometre::calculInclinaison() // Méthode du calcul des inclinaisons du dos 
    
    { 


        float sinVal;        // crée une variable de type "float" appelée "SinVal" et qui contient la valeur sinusoïdale qui fera monter et descendre la tonalité.
        
        int toneVal;


        //================================= Paramétrage variable couleur RGB pour lecteur LCD ( Facultatif ) ===================================// 


        const int rouge = 255;

        const int vert = 255;
  
        const int bleu = 255;
        

        //=================================================== Calcul inclinaison du dos  ====================================// 


        float xValeur = analogRead(xpin);                              // Lis la valeur de la pin X et mesure l'accelération en direction de l'axe X
        float x = map(xValeur, 268, 407, -100, 100);               
        float xG = (float)x/(-100);                                    // Converti les valeurs mappé en accélération en "g" 


        float yValeur = analogRead(ypin);
        float y = map(yValeur, 260, 401, -100, 100);
        float yG = (float)y/(-100);
        

        
        float zValeur = analogRead(zpin);
        float z = map(zValeur, 270, 406, -100, 100);
        float zG = (float)z/(-100);

        unsigned int tangage = (((atan2(zG,xG)*180)/PI)+180);
        unsigned int roulis = (((atan2(xG,yG)*180)/PI)+180);



        Serial.print(tangage);
        Serial.print(roulis);  
        
        //=================================Buzzer=================================//


            if ( ( tangage <= 65 && tangage >= 115  ) && ( roulis <= 65 && roulis >= 115 )) {
    
              for(int x=0; x<180; x++){                   // crée une variable "x" de type "int" dont la valeur de départ est de 0 et qui lorsqu'elle est inférieur 
                                                          // à 180 augmente de +1. Ce qui permet de s'arrurer que la valeur sinusoïdale ne va pas dans le négatif.   
                  sinVal = (sin(x*(3.1412/180)));         // permet de convertir la valeur de x en radians pour la suite du programme.
                  toneVal = 2000+(int(sinVal*1000));      // formule qui permet de convertir la variable en une nouvelle varianble "toneVal" qui défénira la fréquence du Buzzer.
                  tone(2, toneVal);                      // utilise la fonction tone, constituer du numéro de la Broche (13) et de la fréquence (toneVal) 
              }
    
        }

        
        delay(300);


        };
