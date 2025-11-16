#include "utilisation.h"

void allumerEquipement() {
    int id;
    printf("ID de l'équipement à allumer: ");
    scanf("%d", &id);
    for(int i=0;i<nbEquipements;i++){
        if(equipements[i].id == id){
            if(equipements[i].etat == 1){
                printf("L'équipement est déjà allumé.\n");
                return;
            }
            equipements[i].etat = 1;
            equipements[i].debut_utilisation = time(NULL);
            printf("Équipement %s allumé.\n", equipements[i].nom);
            return;
        }
    }
    printf("Équipement introuvable.\n");
}

void eteindreEquipement() {
    int id;
    printf("ID de l'équipement à éteindre: ");
    scanf("%d", &id);
    for(int i=0;i<nbEquipements;i++){
        if(equipements[i].id == id){
            if(equipements[i].etat == 0){
                printf("L'équipement est déjà éteint.\n");
                return;
            }
            time_t fin = time(NULL);
            double duree_min = difftime(fin, equipements[i].debut_utilisation)/60.0;
            float conso = duree_min * equipements[i].conso_min;
            ajouterConsommation(equipements[i].id, equipements[i].debut_utilisation, fin, conso);
            equipements[i].etat = 0;
            printf("Équipement %s éteint. Consommation: %.2f\n", equipements[i].nom, conso);
            return;
        }
    }
    printf("Équipement introuvable.\n");
}

void afficherEtatEquipements() {
    printf("\n=== État des équipements ===\n");
    for(int i=0;i<nbEquipements;i++){
        printf("ID: %d | Nom: %s | Etat: %s\n", equipements[i].id, equipements[i].nom,
               equipements[i].etat ? "Allumé" : "Éteint");
    }
}
