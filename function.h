// Structure Date & Adresse

#ifndef DATE_ADRESSE_H
#define DATE_ADRESSE_H

#include <stdio.h>
#include <string.h>

typedef struct{
    int jour;
    int mois;
    int annee;
}Date;

typedef struct{
    char rue[100];
    char ville[50];
    int code_postal;
}Adresse;

#endif

// BATIMENTS

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
    Adresse adresse;                    
    int equipements[MAX_EQUIP_PAR_BATIMENT];  
    int nb_equipements;                  
} Batiment;

// Prototypes des fonctions de gestion des bâtiments 

void ajouterBatiment();
void modifierBatiment();
void supprimerBatiment();
void afficherBatiments();
void gererEquipementsBatiment();
int rechercheBatimentParId(int id);

#endif 

//EQUIPEMENTS

#ifndef EQUIPEMENT_H
#define EQUIPEMENT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EQUIPEMENTS 300

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

// Déclarations externes
extern Equipement equipements[MAX_EQUIPEMENTS];
extern int nbEquipements;

// Fonctions de gestion des équipements

void ajouterEquipement();
void modifierEquipement();
void supprimerEquipement();
void afficherEquipements();
void afficherEquipementsParBatiment();
void afficherEquipementsParType();

#endif 

//TYPE_EQUIPEMENTS

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


// CONSOMMATION

#ifndef CONSOMMATION_H
#define CONSOMMATION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_CONSOMMATIONS 1000


typedef struct {
    int id;                     // identifiant de la consommation 
    int idEquipement;           // identifiant de l'équipement utilisé 
    time_t debut;         // date/heure de début 
    time_t fin;           // date/heure de fin 
    float consommation;         // consommation calculée 
} Consommation;

// Fonctions de gestion des consommations

void ajouterConsommation();
void afficherConsommations();
void trierConsommationsCroissant();
void trierConsommationsDecroissant();
// Versions utilisées dans Function.c
void trierConsommationsAsc();
void trierConsommationsDesc();


#endif 


#ifndef UTILISATION_H
#define UTILISATION_H

#include <stdio.h>
#include <time.h>

void allumerEquipement();
void eteindreEquipement();
void afficherEtatEquipements();

// Menus et statistiques
void statistiquesMenu();
void statistiquesIntervalleTemps();
void MenuDeTrie();

#endif