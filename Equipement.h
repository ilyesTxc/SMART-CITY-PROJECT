/* equipement.h */

#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EQUIPEMENTS 300

// Déclarations externes
extern Equipement equipements[MAX_EQUIPEMENTS];
extern int nbEquipements;

// Structure représentant un équipement électrique

typedef struct {
    int id;                 // identifiant de l'équipement 
    char nom[50];           // nom de l'équipement 
    float conso_min;        // consommation par minute 
    int idBatiment;         // identifiant du bâtiment associé 
    int idType;             // identifiant du type d'équipement 
    int etat;               // état : 0 = éteint, 1 = allumé 
    time_t debut_utilisation;
} Equipement;

// Fonctions de gestion des équipements

void ajouterEquipement();
void modifierEquipement();
void supprimerEquipement();
void afficherEquipements();
void afficherEquipementsParBatiment();
void afficherEquipementsParType();

#endif 
