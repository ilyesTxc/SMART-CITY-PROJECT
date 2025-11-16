/* type_equipement.h */

#ifndef TYPE_EQUIPEMENT_H
#define TYPE_EQUIPEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TYPES 50


typedef struct {
    int id;                 // identifiant du type 
    char nom[50];           // nom du type d'équipement 
    char description[100];  // description du type 
} TypeEquipement;

// Fonctions de gestion des types d'équipement

void ajouterTypeEquipement();
void modifierTypeEquipement();
void supprimerTypeEquipement();
void afficherTypeEquipements();

#endif 
