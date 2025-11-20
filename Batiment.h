/* batiment.h */

#ifndef BATIMENT_H
#define BATIMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BATIMENTS 100
#define MAX_EQUIP_PAR_BATIMENT 300

// Structure représentant un bâtiment 

typedef struct {
    int id_batiment;                              
    char nom_batiment[50];                       
    char adresse[100];                  
    int equipements[MAX_EQUIP_PAR_BATIMENT];  
    int nb_equipements;                  
} Batiment;

// Prototypes des fonctions de gestion des bâtiments 

void ajouterBatiment();
void modifierBatiment();
void supprimerBatiment();
void afficherBatiments();
void gererEquipementsBatiment();
// Recherche d'un bâtiment par son ID : retourne l'indice dans le tableau ou -1 si non trouvé
int rechercheBatimentParId(int id);

#endif 
