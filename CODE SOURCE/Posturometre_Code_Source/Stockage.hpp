#ifndef STOCKAGE_HPP
#define STOCKAGE_HPP
#include <EEPROM.h>
#include <Arduino.h>
#include "Masse.hpp"
#include "Inclinometre.hpp"

/**
 * @file Stockage.hpp et Stockage.cpp
 * @brief Cette classe est destinée à gérer le posturometre
 * @author Badin Jeffrey 
 * @version version 1.0
 * @date 18/05/2021
*/

class Stockage {

    public :

        /*---Constructeur---*/
            /**
             * @brief Constructeur de la classe Stockage
            */
            Stockage();
        /*-----------------*/

        /*---Méthodes---*/
            /**
             * @brief Cette méthode sert à gérer la suppression des données précédement récupérées
             * @return Cette méthode ne renvoie rien
            */
            void vidageMemoire();

            /**
             * @brief Cette méthode sert à gérer le stockage des données localement dans la mémoire EEPROM de carte Arduino
             * @return Cette méthode ne renvoie rien
            */
            void stockageDonnees();
        /*---------------*/

    private :

        /*---Attributs---*/
            Masse donneesCapteurMasse;
            ///@brief donnees correspond à l'attribut de données collectées par le capteur
            Inclinometre donneesCapteurIncliTangage;
            ///@brief donnees correspond à l'attribut de données collectées par le capteur
             Inclinometre donneesCapteurIncliRoulis;
            ///@brief donnees correspond à l'attribut de données collectées par le capteur
            unsigned int donneesCharge;
            unsigned int donneesIncliTangage;
            unsigned int donneesIncliRoulis;  
            ///@brief emplacementMemoire correspond à l'attribut qui gère la taille de la mémoire
            int emplacementMemoire;       
        /*---------------*/
};

#endif
