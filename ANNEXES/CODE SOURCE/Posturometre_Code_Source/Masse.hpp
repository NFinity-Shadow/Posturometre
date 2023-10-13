#ifndef MASSE_HPP
#define MASSE_HPP

/**
 * @file Masse.hpp et Masse.cpp
 * @brief Cette classe est destinée à gérer l'acquisition des charges portées par l'utilisateur
 * @author Badin Jeffrey 
 * @version version 1.0
 * @date 18/05/2021
*/

class Masse{

    public : 

        /*---Constructeur---*/
            /**
             * @brief Constructeur de la classe Masse
            */
            Masse();
        /*------------------*/

        /*---Méthodes---*/
            /**
             * @brief Cette méthode sert à gérer l'acquisition des données de masse des charges portées par l'utilisateur
             * @return Cette méthode ne renvoie rien
            */
            double acquisitionMasseCharge();
        /*--------------*/

    private :
        /*---Attributs---*/
            ///@brief brocheCapteurDroite correspond à l'attribut qui gère la broche sur laquelle le capteur de droite est branché
            int brocheCapteurDroite;
            ///@brief brocheCapteurGauche correspond à l'attribut qui gère la broche sur laquelle le capteur de gauche est branché
            int brocheCapteurGauche;

            ///@brief pressionCapteurDroite correspond à l'attribut qui gère la pression collecté par le capteur de droite
            double pressionCapteurDroite;
            ///@brief pressionCapteurGauche correspond à l'attribut qui gère la pression collecté par le capteur de gauche
            double pressionCapteurGauche;

            ///@brief pression correspond à l'attribut qui gère la pression collecté au total
            double pression;
            ///@brief masse correspond à l'attribut qui gère la masse des charges portées par l'utilisateur
            double masse;
            ///@brief surface correspond à l'attribut qui représente la surface de la chaussure
            double surface;
        /*---------------*/
};

#endif
