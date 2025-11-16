/* consommation.h */

#ifndef CONSOMMATION_H
#define CONSOMMATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONSOMMATIONS 1000


typedef struct {
    int id;                     // identifiant de la consommation 
    int idEquipement;           // identifiant de l'équipement utilisé 
    time_t debut;         // date/heure de début 
    time_t fin;           // date/heure de fin 
    float consommation;         // consommation calculée 
} Consommation;

// Fonctions de gestion des consommations

void ajouterConsommation(int idEquip, time_t debut, time_t fin, float conso);
void afficherConsommations();
void trierConsommationsCroissant();
void trierConsommationsDecroissant();

#endif 
