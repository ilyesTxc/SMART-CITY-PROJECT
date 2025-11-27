#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

// BATIMENTS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BATIMENTS 100
#define MAX_EQUIP_PAR_BATIMENT 300

// Structure représentant un bâtiment
typedef struct {
    char rue[20] ;
    int code_postal ;
} adresse ;
typedef struct {
    int id_batiment;
    char nom_batiment[50];
    adresse adresses;
    int equipements[MAX_EQUIP_PAR_BATIMENT];
    int nb_equipements;
} Batiment;

// Prototypes des fonctions de gestion des bâtiments

void ajouterBatiment();
void modifierBatiment();
void supprimerBatiment();
void afficherBatiments();
int rechercheBatimentParId(int id);



//EQUIPEMENTS



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
extern Batiment batiments[MAX_BATIMENTS];
extern int nbBatiments;


// Fonctions de gestion des équipements

void ajouterEquipement();
void modifierEquipement();
void supprimerEquipement();
void afficherEquipements();
void afficherEquipementsParBatiment();
void afficherEquipementsParType();



//TYPE_EQUIPEMENTS


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TYPES 50


typedef struct {
    int id;                 // identifiant du type
    char nom[50];           // nom du type d'équipement
    char description[100];  // description du type
} TypeEquipement;

extern TypeEquipement types[MAX_TYPES];
extern int nbTypes;
// Fonctions de gestion des types d'équipement

void ajouterTypeEquipement();
void modifierTypeEquipement();
void supprimerTypeEquipement();
void afficherTypeEquipements();




// CONSOMMATION



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

extern Consommation consommations[MAX_CONSOMMATIONS];
extern int nbConsommations;

// Fonctions de gestion des consommations

void ajouterConsommation(int idEquip, time_t debut, time_t fin, float conso);
void afficherConsommations();
void trierConsommationsCroissant();
void trierConsommationsDecroissant();



#include <stdio.h>
#include <time.h>

void allumerEquipement();
void eteindreEquipement();
void afficherEtatEquipements();

// Statistiques
void statistiquesParEquipement();
void statistiquesParBatiment();
void statistiquesParType();
void statistiquesIntervalleTemps();
void trierConsommations();
void rechercheParNom();

/* Prototypes des fonctions de menu */
void gestionBatiments();
void gestionEquipements();
void utilisationEquipements();
void statistiquesMenu();
#endif // FONCTIONS_H_INCLUDED
