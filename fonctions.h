#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#include <time.h>
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"


typedef struct {
    char ville[20];
    char rue[20] ;
    int code_postal ;
} adresse ;
typedef struct {
    int id_bat;
    char nom_bat[50];
    adresse adresses;
    int nbEquip;
} Batiment;


typedef struct {
    int id_equip;
    char nom_equip[50];
    float energie_consom_min;
    int id_bat;
    int id_type;
    int etat;
    time_t debut_utilisation;
} Equipement;
typedef struct {
    int id;
    char nom[50];
    char description[100];
} TypeEquipement;

Batiment saisie_batiment();
void saisie_tab_batiment();
void affiche_batiment();
void affiche_tab_batiment();
void modifier_batiment();
void modifier_tab_batiment();
void supprimer_batiment();
int recherche_id_batiment();
Batiment recherche_nom_batiment();


Equipement saisie_equipement();
void saisie_tab_equipement();
void affiche_equipement();
void affiche_tab_equipement();
void modifier_equipement();
void modifier_tab_equipement();
void supprimer_equipement();
int recherche_id_equipement();
Equipement recherche_nom_equipemnt();

#define MAX_CONSO 100  // Taille maximale du tableau

typedef struct {
    int id;
    int idEquipement;
    time_t debut;
    time_t fin;
    float consommation;
} Consommation;

// Prototypes des fonctions
int ajouterConsommation(Consommation consoList[], int *nbConso,
                       int idEquipement, time_t debut, time_t fin, float consommation);
void afficherConsommations(Consommation consoList[], int nbConso);
void allumerEquipement(int idEquipement, time_t *debut);
void eteindreEquipement(int idEquipement, time_t debut, Consommation consoList[],
                       int *nbConso, float tauxConsommation);

#endif // FONCTIONS_H_INCLUDED
