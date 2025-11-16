#include "consommation.h"
#include <stdio.h>
#include <time.h>

Consommation consommations[MAX_CONSOMMATIONS];
int nbConsommations = 0;

// ajouter consommation

void ajouterConsommation(int idEquip, time_t debut, time_t fin, float conso) {
    if (nbConsommations >= MAX_CONSOMMATIONS) {
        printf("Nombre maximum de consommations atteint.\n");
        return;
    }
    Consommation c;
    c.id = (nbConsommations == 0) ? 1 : consommations[nbConsommations-1].id + 1;
    c.idEquipement = idEquip;
    c.debut = debut;
    c.fin = fin;
    c.consommation = conso;
    consommations[nbConsommations++] = c;
    printf("Consommation ajoutée pour l'équipement %d: %.2f\n", idEquip, conso);
}

// afficher consommations

void afficherConsommations() {
    printf("\n=== Consommations enregistrées ===\n");
    for (int i = 0; i < nbConsommations; i++) {
        struct tm *debut_tm = localtime(&consommations[i].debut);
        struct tm *fin_tm = localtime(&consommations[i].fin);
        printf("ID: %d | Equipement ID: %d | Début: %02d/%02d/%04d %02d:%02d:%02d | Fin: %02d/%02d/%04d %02d:%02d:%02d | Consommation: %.2f\n",
               consommations[i].id, consommations[i].idEquipement,
               debut_tm->tm_mday, debut_tm->tm_mon+1, debut_tm->tm_year+1900,
               debut_tm->tm_hour, debut_tm->tm_min, debut_tm->tm_sec,
               fin_tm->tm_mday, fin_tm->tm_mon+1, fin_tm->tm_year+1900,
               fin_tm->tm_hour, fin_tm->tm_min, fin_tm->tm_sec,
               consommations[i].consommation);
    }
}

// Trier consommations croissant (Tri par sélection)

void trierConsommationsCroissant() {
    for(int i=0;i<nbConsommations-1;i++){
        for(int j=i+1;j<nbConsommations;j++){
            if(consommations[i].consommation > consommations[j].consommation){
                Consommation temp = consommations[i];
                consommations[i] = consommations[j];
                consommations[j] = temp;
            }
        }
    }
    printf("Consommations triées par ordre croissant.\n");
}

// Trier consommations décroissant (Tri par sélection)

void trierConsommationsDecroissant() {
    for(int i=0;i<nbConsommations-1;i++){
        for(int j=i+1;j<nbConsommations;j++){
            if(consommations[i].consommation < consommations[j].consommation){
                Consommation temp = consommations[i];
                consommations[i] = consommations[j];
                consommations[j] = temp;
            }
        }
    }
    printf("Consommations triées par ordre décroissant.\n");
}