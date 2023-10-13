#ifndef LIAISONETHERNET_HPP
#define LIAISONETHERNET_HPP
#include "Ethernet.h"
#include "SPI.h"
#include "string.h"

/**
 * @file LiaisonEthernet.hpp et LiaisonEthernet.cpp
 * @brief Cette classe est destinée à gérer la connexion à la base de données
 * @author Badin Jeffrey 
 * @version version 1.0
 * @date 18/05/2021
*/

class LiaisonEthernet {

    public :

        /*---Constructeur---*/
            /**
             * @brief Constructeur de la classe LiaisonEthernet
            */
            LiaisonEthernet();
        /*------------------*/    

        /*---Méthodes---*/
            /**
             * @brief Cette méthode sert à gérer la connexion à la base de données
             * @return Cette méthode renvoie un caractère
            */
            void connexion ();

    private :
    
        /*---Attributs---*/
            ///@brief portServeur correspond à l'attribut qui gère le numéro de port de la base de données
            int portServeur;
            ///@brief client correspond à l'attribut qui gère l'Arduino en mode client pour se connecter à la base de données
            EthernetClient client;
            ///@brief donneesEEPROM correspond à l'attribut qui gère toutes les données stockées dans la mémoire EEPROM
            double donneesEEPROM;
        /*---------------*/
};

#endif
