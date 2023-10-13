#ifndef POSTUROMETRE_HPP
#define POSTUROMETRE_HPP
#include <Arduino.h>
#include "Stockage.hpp"
#include "LiaisonEthernet.hpp"
#include "Masse.hpp"
#include "Inclinometre.hpp"

/**
 * @file Posturometre.hpp et Posturometre.cpp
 * @brief Cette classe est destinée à gérer le posturometre
 * @author Badin Jeffrey 
 * @version version 1.0
 * @date 18/05/2021
*/

class Posturometre{

    public :

        /*---Constructeur---*/
            /**
             * @brief Constructeur de la classe Posturometre
            */
            Posturometre();
        /*------------------*/

        /*---Méthodes---*/    
            /**
             * @brief Cette méthode sert à gérer la suppression des données précédement récupérées
             * @return Cette méthode ne renvoie rien
            */
            void viderMemoire ();

            /**
             * @brief Cette méthode sert à gérer l'acquisition des données de masse des charges portées par l'utilisateur
             * @return Cette méthode ne renvoie rien
            */
            double acquisitionCharge();

             /**
             * @brief Cette méthode sert à gérer l'acquisition des données de masse des charges portées par l'utilisateur
             * @return Cette méthode ne renvoie rien
            */
            int calculInclinaison();

            /**
             * @brief Cette méthode sert à gérer le stockage des données localement dans la mémoire EEPROM de carte Arduino
             * @return Cette méthode ne renvoie rien
            */            
            void stockerDonnees();

            /**
             * @brief Cette méthode sert à gérer la connexion à la base de données
             * @return Cette méthode ne renvoie rien
            */
            void connexionServeur();
        /*--------------*/
            

    private : 

        /*---Attributs---*/
            /// @brief memoire correspond à l'attribut qui gère la classe Stockage
            Stockage memoire;
            /// @brief communication correspond à l'attribut qui gère la classe LiaisonEthernet
            LiaisonEthernet communication;
            /// @brief charge correspond à l'attribut qui gère la classe Masse
            Masse charge;
            /// @brief charge correspond à l'attribut qui gère la classe Inclinometre
            Inclinometre inclinaison;
            
        /*---------------*/
};

#endif
